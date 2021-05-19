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
                return &src[i - stdlen];
            }
        }
        if (j < stdlen) {
            return nullptr;
        }


    }

    int CharArrStr::cnt_str_number(char *str) {
        if (strlen(str) == 0) {
            return 0;
        }

        int start = 0;
        int end = strlen(str) - 1;

        while ((str[start] == ' ') || (str[end] == ' ')) {
            if (str[start] == ' ') {
                start++;
            }
            if (str[end] == ' ') {
                end--;
            }
        }

        int len = end - start;
        return len;

    }

    int CharArrStr::cp_str_no_empty(char *str, char *dst) {
        if (strlen(str) == 0) {
            return 0;
        }

        int start = 0;
        int end = strlen(str) - 1;

        while ((str[start] == ' ') || (str[end] == ' ')) {
            if (str[start] == ' ') {
                start++;
            }
            if (str[end] == ' ') {
                end--;
            }
        }
        int len = end - start + 1;
        memcpy(dst, &str[start], len);
        dst[end + 1] = 0;
        return 0;
    }

    int CharArrStr::getStr1Str2(char *source, char **str1, char **str2) {
         *str1 = new char[128];
         *str2 = new char[128];
        int str_1_cnt = 0;
        int str_2_cnt = 0;

        for (int i = 0; i < strlen(source); ++i) {
            char a = source[i];
            int ctoi = a - '0';
            if (ctoi < 11) {
                if (ctoi % 2 == 0) {
                    (*str1)[str_1_cnt] = a;
                    str_1_cnt++;

                } else  {
                    (*str2)[str_2_cnt] = a;
                    str_2_cnt++;

                }
            } else {

            }
        }
//        str1 = str_1;
//        str2 = str_2;
        return 0;
    }
}


