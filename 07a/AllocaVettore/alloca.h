#define ALLOCA(ptr) \
    do {    \
        ptr = (int32_t *)malloc(10 * sizeof(int32_t)); \
        if (ptr != NULL) {   \
            int j;  \
            for (j = 0; j < 10; j++) {   \
                ptr[j] = -1000 + j; \
            }   \
        }   \
    } while (0)
    