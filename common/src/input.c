#include <malloc.h>
#include <string.h>
#include "input.h"

int DynamicBufferPut(DynamicBuffer *buffer, char c) {
    if (buffer->data == NULL) {
        buffer->data = malloc(4);
        buffer->size = 4;
    }
    if (buffer->size == buffer->ptr) {
        size_t newSize = buffer->size * 2;
        char *newData = malloc(newSize);
        memcpy(newData, buffer->data, buffer->size);
        free(buffer->data);
        buffer->data = newData;
        buffer->size = newSize;
    }
    buffer->data[buffer->ptr++] = c;
    return 0;
}

void DynamicBufferFree(DynamicBuffer *buffer) {
    free(buffer->data);
    *buffer = (DynamicBuffer) {0};
}

void DynamicBufferReset(DynamicBuffer *buffer) {
    buffer->ptr = 0;
}