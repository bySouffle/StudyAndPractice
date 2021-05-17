//
// Created by by Souffle on 2021/5/17.
//

#include "CharArrStr.h"


namespace bys_practice {
    int CharArrStr::copy_string(const char *src, char *dst) {
        if (src == nullptr || dst == nullptr) {
            return -1;
        }
        for (int i = 0; *(src + i) != 0; ++i) {
            dst[i] = src[i];
        }
        return 0;
    }

#define _func1_

    int CharArrStr::copy_string_while(const char *src, char *dst) {
        if (src == nullptr || dst == nullptr) {
            return -1;
        }
        int i = 0;
#ifndef _func1

        while (*src != '\0') {
            *dst = *src;
            *dst++;
            *src++;
        }
#else
        while (src[i] != '\0')
        {
            *dst = src[i];
            dst ++;
            i ++;

        }
#endif
        return 0;
    }

}
