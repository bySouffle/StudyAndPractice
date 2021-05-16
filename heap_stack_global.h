//
// Created by by Souffle on 2021/5/12.
//

#ifndef STUDYANDPRACTICE_HEAP_STACK_GLOBAL_H
#define STUDYANDPRACTICE_HEAP_STACK_GLOBAL_H
#include "string.h"
#include "stdlib.h"
namespace bys_code_analytics {
    class heap_stack_global {
    public:
        char *get_str_from_static();
        char *get_str_from_stack();
        char *get_str_from_heap();

    };

}


#endif //STUDYANDPRACTICE_HEAP_STACK_GLOBAL_H
