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

    };


}

#endif //STUDYANDPRACTICE_CHARARRSTR_H
