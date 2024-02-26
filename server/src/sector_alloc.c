#include "../include/sector.h"
#include "table.h"
#include "file.h"

int readSectorHeaderByIndex(FILE *file, uint32_t sectorNumber, struct SectorHeader *header) {
    fseek(file, sectorNumber * SECTOR_SIZE, SEEK_SET);
    return fread(header, sizeof(struct SectorHeader), 1, file);
}

int writeSectorHeaderByIndex(FILE *file, uint32_t sectorNumber, struct SectorHeader *header) {
    fseek(file, sectorNumber * SECTOR_SIZE, SEEK_SET);
    return fwrite(header, sizeof(struct SectorHeader), 1, file);
}

uint32_t allocateSector(FILE *file, size_t allocSize) {
    struct StaticFileHeader staticHeader;
    int read_result = readStaticHeader(file, &staticHeader);
    if (read_result < 0) return -1;
    uint32_t headerPtrFree = staticHeader.firstAtEndFree;
    uint32_t lastSector = staticHeader.lastSector;

    struct SectorHeader header;
    header.isTaken = true;
    header.sectorsTakenInRow = allocSize;

    if (lastSector == HASH_NONE) {
        // Write sector
        header.prevSectorNumber = HASH_NONE;
        header.nextSectorNumber = HASH_NONE;
        writeSectorHeaderByIndex(file, headerPtrFree, &header);
    } else {
        // Change last sector header
        struct SectorHeader last_header;
        readSectorHeaderByIndex(file, lastSector, &last_header);
        last_header.nextSectorNumber = headerPtrFree;
        writeSectorHeaderByIndex(file, lastSector, &last_header);

        header.prevSectorNumber = lastSector;
        header.nextSectorNumber = HASH_NONE;
        writeSectorHeaderByIndex(file, headerPtrFree, &header);
    }

    staticHeader.lastSector = headerPtrFree;
    staticHeader.firstAtEndFree = headerPtrFree + allocSize;
    writeStaticHeader(file, &staticHeader);

    return headerPtrFree;
}

void deallocateSector(FILE *file, uint32_t sectorNumber) {
    struct SectorHeader headerToFree;
    readSectorHeaderByIndex(file, sectorNumber, &headerToFree);
    if (!headerToFree.isTaken) return;
    headerToFree.isTaken = false;

    struct SectorHeader sectorHeader;
    // Append at right
    if (headerToFree.nextSectorNumber != HASH_NONE) {
        readSectorHeaderByIndex(file, headerToFree.nextSectorNumber, &sectorHeader);
        if (!sectorHeader.isTaken) {
            headerToFree.nextSectorNumber = sectorHeader.nextSectorNumber;
            headerToFree.sectorsTakenInRow += sectorHeader.sectorsTakenInRow;
            writeSectorHeaderByIndex(file, sectorNumber, &headerToFree);
        }
    }
    // Append at left
    if (headerToFree.prevSectorNumber != HASH_NONE) {
        readSectorHeaderByIndex(file, headerToFree.prevSectorNumber, &sectorHeader);
        if (!sectorHeader.isTaken) {
            sectorHeader.nextSectorNumber = headerToFree.nextSectorNumber;
            sectorHeader.sectorsTakenInRow += headerToFree.sectorsTakenInRow;
            writeSectorHeaderByIndex(file, headerToFree.prevSectorNumber, &sectorHeader);
        }
    }
}
