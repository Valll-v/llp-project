#include "../include/sector.h"

const size_t sectorDataOffset = sizeof(struct SectorHeader) + SECTOR_PADDING;

size_t calculateSectorsNeeded(size_t structSize) {
    return (structSize + sizeof(struct SectorHeader) + SECTOR_PADDING) / SECTOR_SIZE + 1;
}

int writeDataToSector(FILE *file, void *dataPtr, size_t bufferSize, uint32_t sectorN) {
    struct SectorHeader currentHeader;
    int secRead = readSectorHeaderByIndex(file, sectorN, &currentHeader);
    if (!secRead) return -1;
    if (calculateSectorsNeeded(bufferSize) > currentHeader.sectorsTakenInRow) return -1;
    if (!currentHeader.isTaken) return -1;
    size_t sectorPtr = sectorN * SECTOR_SIZE;
    fseek(file, sectorPtr + sectorDataOffset, SEEK_SET);
    return fwrite(dataPtr, bufferSize, 1, file) - 1;
}

int readDataFromSector(FILE *file, void *dataPtr, size_t bufferSize, uint32_t sectorN) {
    struct SectorHeader currentHeader;
    int secRead = readSectorHeaderByIndex(file, sectorN, &currentHeader);
    if (!secRead) return -3;
    if (calculateSectorsNeeded(bufferSize) > currentHeader.sectorsTakenInRow) return -4;
    if (!currentHeader.isTaken) return -2;
    size_t sectorPtr = sectorN * SECTOR_SIZE;
    fseek(file, sectorPtr + sectorDataOffset, SEEK_SET);
    return fread(dataPtr, bufferSize, 1, file) - 1;
}
