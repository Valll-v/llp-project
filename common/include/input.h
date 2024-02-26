#include <stddef.h>

struct DynamicBuffer {
    char *data;
    size_t ptr;
    size_t size;
};

typedef struct DynamicBuffer DynamicBuffer;

int DynamicBufferPut(DynamicBuffer *buffer, char c);

void DynamicBufferFree(DynamicBuffer *buffer);

void DynamicBufferReset(DynamicBuffer *buffer);
