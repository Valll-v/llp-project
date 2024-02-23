#include "../include/index.h"

int readTableIndexFromSector(FILE *file, uint32_t sectorNumber, struct TableIndexArray *tableIndex) {
    return readDataFromSector(file, tableIndex, sizeof(struct TableIndexArray), sectorNumber);
}

int writeTableIndexToSector(FILE *file, uint32_t sectorNumber, struct TableIndexArray *tableIndex) {
    return writeDataToSector(file, tableIndex, sizeof(struct TableIndexArray), sectorNumber);
}
