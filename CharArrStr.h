//
// Created by by Souffle on 2021/5/17.
//

#ifndef STUDYANDPRACTICE_CHARARRSTR_H
#define STUDYANDPRACTICE_CHARARRSTR_H

namespace bys_practice {
#include "string.h"

#include "stdio.h"

    class CharArrStr {
    public:
        int copy_string(const char*src, char*dst);

        int copy_string_while(const char*src, char*dst);
        int cnt_substring( char*src,const  char* sub);
        char* m_strstr(char *src, const char *sub);
        int cnt_str_number( char*str);
        int cp_str_no_empty( char *str, char *dst);
        int getStr1Str2(char *source, char** str1, char** str2);
        int getKeyByValue( char *k_v_buf, char *k_buf, char *v_buf, int *v_buf_len);
    };


}

#endif //STUDYANDPRACTICE_CHARARRSTR_H
