//
// Created by by Souffle on 2021/7/19.
//

#ifndef MAIN_LINKLIST_H
#define MAIN_LINKLIST_H

#include "stdlib.h"
#include "stdio.h"

typedef struct LinkNode{
    int data;
    LinkNode * next;
} LinkNode_t;

class linklist {
public:
    linklist();     //  构建一个单链表
    ~linklist();

    void create_linklist(int n);        //  创建一个单链表
    void travel_linklist();             //  遍历一个单链表
    int get_length();                   //  获取长度
    bool isempty();                     //  判空
    LinkNode_t *find_node(int data);    //  查找节点
    void insert_end(int data);          //  在尾部插入节点
    void insert_index(int data, int index); //  在指定位置插入节点
    void insert_begin(int data);        //  在头部插入节点
    void del_end();                     //  删除尾部节点
    void del_all();                     //  清空数据
    void del_index(int data);           //  删除指定数据的节点
    void del_head();                    //  删除头节点的数据

    LinkNode * head;
};


#endif //MAIN_LINKLIST_H
