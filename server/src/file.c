#include <stdlib.h>
#include <stdint.h>


#include "file.h"

uint32_t writeStringToSector(FILE* file, const char* string) {
    size_t buffSize = strlen(string) + SECTOR_PADDING;
    char buffer[buffSize];
    strcpy(buffer, string);
    uint32_t freeSector = allocateSector(file, calculateSectorsNeeded(buffSize));
    writeDataToSector(file, buffer, buffSize, freeSector);
    return freeSector;
}

void printStringFromSector(FILE* file, uint32_t sectorNum, size_t strSize) {
    size_t buffSize = strSize + SECTOR_PADDING;
    char buffer[buffSize];
    readDataFromSector(file, buffer, buffSize, sectorNum);
    printf("%s", buffer);
}

int createFileAndInitEmptyStructure(FILE* file) {
    struct StaticFileHeader defHeader = createEmptyFileHeader();
    writeStaticHeader(file, &defHeader);

    struct TableIndexArray* globalIndexArray = allocateEmptyTableIndex();
    size_t sectors_needed = calculateSectorsNeeded(sizeof(struct TableIndexArray));
    allocateSector(file, sectors_needed);
    writeTableIndexToSector(file, defHeader.tableIndicesSector, globalIndexArray);
    defHeader.firstAtEndFree += sectors_needed;
    writeStaticHeader(file, &defHeader);
    free(globalIndexArray);
    return 0;
}

uint32_t hashStringDefault(const char* str) {
    uint32_t hash = HASH_SEED;
    for (; *str; ++str) {
        hash ^= *str;
        hash *= 0x5bd1e995;
        hash ^= hash >> 15;
    }
    return hash;
}
