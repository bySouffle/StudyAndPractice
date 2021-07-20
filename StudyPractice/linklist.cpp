//
// Created by by Souffle on 2021/7/19.
//

#include "linklist.h"


linklist::linklist() {
    head = new LinkNode_t;
    head->data = 0;
    head->next = nullptr;

}

linklist::~linklist() {
    delete head;
}

//! 1.  如果直接指定head.next = new xxx，head会跟着移动，所以用另一个指针来代替当前对象
//! 2.  新产生的对象如果没有别名不好继续指定
//!
//!
//! \param n


void linklist::create_linklist(int n) {
    if (n < 0) {
        printf("...\r\n");
    }
    LinkNode_t * pre = head;
    LinkNode_t * pnew = nullptr;
    for (int i = 0; i < n; ++i) {
        pnew = new LinkNode_t ;
        pnew->next = nullptr;
        pre->next = pnew;
        pre->data = i;
        pre = pnew;
    }
}


//! 1.  遍历条件即 head本身是否为 空 以及下一个节点是否为空
//! 2.  方法 用一个指针替代head套娃
void linklist::travel_linklist() {
    if(head->next == nullptr || head == nullptr){
        printf("empty...\r\n");
    }
    LinkNode_t *p = head;
    while (p->next!= nullptr){
        printf("p = %d\r\n", p->data);
        p = p->next;
    }
}

int linklist::get_length() {
    if(head->next == nullptr || head == nullptr){
        printf("empty...\r\n");
        return 0;
    }
    int cnt = 0;
    LinkNode_t *p = head;
    while (p->next!= nullptr){
        printf("p = %d\r\n", p->data);
        p = p->next;
        cnt ++;
    }
    return cnt;
}

bool linklist::isempty() {
    if(head->next== nullptr||head== nullptr){
        return true;
    }
    return false;
}

LinkNode_t *linklist::find_node(int data) {
    if(head->next == nullptr || head == nullptr){
        printf("empty...\r\n");
        return 0;
    }
    LinkNode_t *p = head;
    while (p->next!= nullptr){
        printf("p = %d\r\n", p->data);
        if(p->data==data){
            return p;
        }
        p = p->next;

    }
    return nullptr;
}

void linklist::insert_end(int data) {
    if(head->next == nullptr || head == nullptr){
        printf("empty...\r\n");
    }
    LinkNode_t *p = head;
    while (1){
        printf("p = %d\r\n", p->data);
        if(p->next== nullptr){
            p->next = new LinkNode_t;
            p->next->data = data;
            p->next->next = nullptr;
            break;
        }
        p = p->next;

    }

}


