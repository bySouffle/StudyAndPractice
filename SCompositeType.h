//
// Created by by Souffle on 2021/5/1.
//

#ifndef STUDYANDPRACTICE_SCOMPOSITETYPE_H
#define STUDYANDPRACTICE_SCOMPOSITETYPE_H

#include <stdio.h>
#include <string>

class SCompositeType {
public:
    void AddHead(std::string title);
    void AddEnd();

    //  结构体数组
    void s_struct_arr();
    //  结构体数组一级指针
    void s_struct_p();
    //  共用体
    void s_union_();
    //  堆栈的增长方向
    void heap_stack_direction();

    char cpu_arch(unsigned long n);
};



#endif //STUDYANDPRACTICE_SCOMPOSITETYPE_H
