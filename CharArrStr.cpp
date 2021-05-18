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

    int CharArrStr::cnt_substring(char *src, const char *sub) {

#define sub3
#ifdef sub1
        if(src==nullptr || sub==nullptr){
            return -1;
        }
        char *str = nullptr;
        int cnt = 0;
       while (1){
           src = strstr(src,sub);
           if(src != nullptr){
               cnt += 1;
           } else{
               break;
           }
           src += strlen(sub);
           }
       return cnt;
#endif
#ifdef sub2
        char *str = src;
        int cnt = 0;
        while ( str != nullptr )
        {
            str = strstr(str, sub);
            if(str!= nullptr){
                str += strlen(sub);
                cnt++;
            }
        }
        return cnt;

#endif
#ifdef sub3
        int cnt = 0;
        while ((src = m_strstr(src, sub)) != nullptr) {
            cnt++;
            src += strlen(sub);
        }
        return cnt;
    }

#endif

#ifdef sub4
#endif


    char *CharArrStr::m_strstr(char *src, const char *sub) {
        int stdlen = strlen(sub);
        int j = 0;

        for (int i = 0; i < strlen(src); ++i) {
            if (src[i] == sub[j]) {
                printf("[src[i] = %c] [dst[j] = %c]\n", src[i], sub[j]);
                j++;

            } else {
                j = 0;
            }
            if (j == stdlen) {
                return &src[i-stdlen];
            }
            }
        if(j<stdlen){
            return nullptr;
        }


    }
}


