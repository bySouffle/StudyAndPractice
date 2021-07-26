//
// Created by by Souffle on 2021/7/26.
//

#ifndef MAIN_OVERLOADOPERATOR_H
#define MAIN_OVERLOADOPERATOR_H

#include "string"
#include "iostream"

class OverloadOperator {
    friend std::ostream& operator << (std::ostream &cout, OverloadOperator &s);
    friend std::istream& operator >> (std::istream &cin, OverloadOperator &s);

public:
    bool operator == (OverloadOperator & p);
    bool operator != (OverloadOperator & p);
    //  仿函数
    void operator() (std::string str);
    //  匿名对象
    void operator() (int a, int b);
    //  拷贝构造函数
    OverloadOperator(std::string str);
    OverloadOperator(const OverloadOperator& ol);
    ~OverloadOperator();

    OverloadOperator& operator=(std::string str);
    OverloadOperator& operator=(const OverloadOperator& ot);


    void printf_str();
private:
    char *str_;
    int len_;
};


#endif //MAIN_OVERLOADOPERATOR_H
