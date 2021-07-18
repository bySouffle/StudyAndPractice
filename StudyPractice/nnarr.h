//
// Created by by Souffle on 2021/5/27.
//

#ifndef MAIN_NNARR_H
#define MAIN_NNARR_H

#include "string"
#include "string.h"
#include "stdlib.h"

typedef struct Box{
    char *id;
    char **small_box;
}Box_t;

class nnarr {
public:
    nnarr();
    //  二级指针结构体套二级指针
    int create_box(Box_t ***box);
    int delete_box(Box_t ***box);
    int add_box(Box_t ***box);
    int out_box(Box_t ***box);
};

#endif //MAIN_NNARR_H
