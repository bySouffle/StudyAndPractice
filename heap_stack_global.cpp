//
// Created by by Souffle on 2021/5/12.
//

#include "heap_stack_global.h"
namespace bys_code_analytics{

    char *heap_stack_global::get_str_from_static() {
        char *str = "hello, am from  text static";
        return str;
    }

    char *heap_stack_global::get_str_from_stack() {
        char str[] = "hello, am from stack";
        return str;
    }

    char *heap_stack_global::get_str_from_heap() {
        char *str = (char*)malloc(sizeof (char)*20);
        strcpy(str,"hello, am from heap");
        return str;
    }
};