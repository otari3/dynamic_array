#pragma once
#include <stdlib.h>
#define ARRAY_CREATE(T,arr)\
    do{\
      size_t *raw = malloc(2 * sizeof(size_t));\
      raw[0] = 0;\
      raw[1] = 0;\
      arr = (void *) &raw[2];\
    }while (0)

#define ARRAY_SIZE(arr) *((size_t *) arr - 2)
#define ARRAY_CAP(arr)  *((size_t *) arr - 1)

#define ARRAY_PUSH(arr,value)\
    do {\
        size_t *header = (size_t*) arr-2;\
        header[0] = header[0]+1;\
        if (header[1]==0) {\
            header[1] = 1;\
            header = realloc(header,2*sizeof(size_t)+header[1]*sizeof(value));\
            arr = (void*) &header[2];\
        }\
        if (header[0]>header[1]) {\
            header[1] = header[1]*2;\
            header = realloc(header,2*sizeof(size_t)+header[1]*sizeof(value));\
            arr = (void*)&header[2];\
        }\
        arr[header[0]-1]= value;\
    }while (0)
#if defined(ARRAY_HELPER)
void* ARRAY_POP(void * arr,size_t size) {
        if (ARRAY_SIZE(arr)>0) {
            return (char *) arr + (--ARRAY_SIZE(arr)*size);
        }
        return NULL;
    }
#endif


