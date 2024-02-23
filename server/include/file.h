#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>
#include <string.h>

#include "./table.h"
#include "./file.h"
#include "./index.h"

int createFileAndInitEmptyStructure(FILE* file);

uint32_t writeStringToSector(FILE* file, const char* string);
void printStringFromSector(FILE* file, uint32_t sectorNum, size_t strSize);

struct StaticFileHeader createFileHeader(int tableCount, int tableIndicesSector, int lastSectorTaken);
struct StaticFileHeader createEmptyFileHeader();
int writeStaticHeader(FILE* file, const struct StaticFileHeader* header);
int readStaticHeader(FILE* file, struct StaticFileHeader* header);

uint32_t hashStringDefault(const char* str);

#endif //FILE_UTILS_H
