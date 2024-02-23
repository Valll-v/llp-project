#include "../include/file.h"
#include "table.h"

struct StaticFileHeader createFileHeader(
        int tableCount,
        int tableIndicesSector,
        int lastSectorTaken
) {
    struct StaticFileHeader header;
    header.tableCount = tableCount;
    header.tableIndicesSector = tableIndicesSector;
    header.firstAtEndFree = lastSectorTaken;
    header.lastSector = HASH_NONE;
    return header;
}

struct StaticFileHeader createEmptyFileHeader() {
    return createFileHeader(0, 1, 1);
}

int writeStaticHeader(FILE* file, const struct StaticFileHeader* header) {
    if (file == NULL || header == NULL) { return -1; }
    if (fseek(file, 0, SEEK_SET) != 0) { return -2; }
    size_t header_written = fwrite(header, sizeof(struct StaticFileHeader), 1, file);
    fflush(file);
    if (header_written != 1) { return -2; }
    return 0;
}

int readStaticHeader(FILE* file, struct StaticFileHeader* header) {
    if (file == NULL || header == NULL) { return -1; }
    if (fseek(file, 0, SEEK_SET) != 0) { return -2; }
    size_t read = fread(header, sizeof(struct StaticFileHeader), 1, file);
    if (read != 1) { return -2; }
    return 0;
}
