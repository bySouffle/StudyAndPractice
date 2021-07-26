//
// Created by by Souffle on 2021/7/26.
//

#include "OverloadOperator.h"
std::ostream& operator << (std::ostream &cout, OverloadOperator &s){
    cout << s.str_;
    return cout;
}

std::istream&  operator >> (std::istream &cin, OverloadOperator &s){
    if(s.str_ != nullptr){
        free(s.str_);
    }

    char buf[1024] = {};
    cin>>buf;
    s.str_ = (char*) malloc(strlen(buf)+1);
    strcpy(s.str_, buf);
    s.len_ = strlen(buf);
}


bool OverloadOperator::operator==(OverloadOperator &p) {
    if(this->len_ == p.len_){
        return true;
    }
    return false;
}

bool OverloadOperator::operator!=(OverloadOperator &p) {
    if(this->len_ != p.len_){
        return true;
    }
    return false;
}

void OverloadOperator::operator()(std::string str) {
    if(strcmp(str_, str.data())){
        std::cout << "ok!!!"<<std::endl;
    }
}

void OverloadOperator::operator()(int a, int b) {
    len_ > a ? a : b ;
    std::cout << "max " << len_ <<std::endl;
}

OverloadOperator::OverloadOperator(std::string str) {
    this->str_ = (char*) malloc(strlen(str.data())+1);
    memcpy(this->str_, str.data(), strlen(str.data()));
    this->len_ = strlen(str.data());
}

OverloadOperator::~OverloadOperator() {
    if(this->str_!= nullptr){
        free(this->str_);
        this->str_ = nullptr;

    }

}

void OverloadOperator::printf_str() {
    printf("str: %s\r\n", this->str_);
}

OverloadOperator::OverloadOperator(const OverloadOperator &ol) {
    this->str_ = (char*) malloc(strlen(ol.str_)+1);
    memcpy(this->str_, ol.str_,strlen(ol.str_));
    this->len_ = ol.len_;
}

OverloadOperator &OverloadOperator::operator=(std::string str) {
    if(this->str_ != nullptr){
        free(this->str_);
    }
    this->str_ = (char*) malloc(strlen(str.data())+1);
    memcpy(this->str_, str.data(), strlen(str.data()));
    return *this;

}

OverloadOperator &OverloadOperator::operator = (const OverloadOperator &ot) {
    if(this->str_ != nullptr){
        free(this->str_);
    }
    this->str_ = (char*) malloc(strlen(ot.str_)+1);
    memcpy(this->str_, ot.str_,strlen(ot.str_));
    this->len_ = ot.len_;
    return *this;
}


