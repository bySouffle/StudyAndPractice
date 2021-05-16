//
// Created by by Souffle on 2021/5/4.
//

#ifndef STUDYANDPRACTICE_FILEOPERATE_H
#define STUDYANDPRACTICE_FILEOPERATE_H

#include <cstdio>
#include <fcntl.h>
#include <unistd.h>
#include "ctime"
#include "cstdlib"
#include "CommonElement.h"
#include "string"

#define __print__

#ifdef __print__
//#define _print(format,...) \
//        printf("FILE: " __FILE__ ", LINE: %d: " format "\n", __LINE__, ##__VA_ARGS__)

#define _print(format,...) printf("FILE: " __FILE__ ", LINE: %d : " format "\n", __LINE__, ##__VA_ARGS__)

#else
#define _printf(format,...)
#endif

class FileOperate {
public:
    void m_close_win_out();
    void m_fopen();
    void m_fputc();
    void m_fgetc();
    void m_cat(std::string str);
    void m_vi(std::string str);
    void m_fputs();
    void m_fgets();
    void m_rand_num_file();
    void m_read_file_arr();
    void m_read_file_d_arr();
    void m_fgets_read();
    void m_fgets_read_sub_exec(char *str_line, int num1, int num2, char sym);

    void m_fwrite_fread();

    void m_fcopy(const char *srcfile, const char *dstfile);
    void m_fopt_random();

    void m_pstruct_rw();
};


#endif //STUDYANDPRACTICE_FILEOPERATE_H
