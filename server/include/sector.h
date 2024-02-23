#ifndef SECTOR_UTILS_H
#define SECTOR_UTILS_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "./table.h"

uint32_t allocateSector(FILE* file, size_t allocSize);
void deallocateSector(FILE* file, uint32_t sectorNumber);
size_t calculateSectorsNeeded(size_t structSize);

int readSectorHeaderByIndex(FILE *file, uint32_t sectorNumber, struct SectorHeader *header);
int writeSectorHeaderByIndex(FILE *file, uint32_t sectorNumber, struct SectorHeader *header);

int writeDataToSector(FILE* file, void* dataPtr, size_t bufferSize, uint32_t sectorN);
int readDataFromSector(FILE* file, void* dataPtr, size_t bufferSize, uint32_t sectorN);

#endif //SECTOR_UTILS_H
