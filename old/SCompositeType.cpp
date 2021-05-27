//
// Created by by Souffle on 2021/5/1.
//

#include "SCompositeType.h"

void SCompositeType::AddHead(std::string title) {
    printf("1========= %s ===========\n",title.data());
}

void SCompositeType::AddEnd() {
    printf("2=========================\n\n");
}

void SCompositeType::s_struct_arr() {
    AddHead("结构体数组");

    struct Student
    {
        int age;
        bool gender;
        char name[8];
    };


    Student my_class[5];
    my_class[0].age = 8;
    my_class[0].gender = 0;
    // 结构体数组[1]的name的地址
    strcpy(my_class[0].name, "loli");

    // 结构体首地址+1
    (my_class+1)->age = 9;
    (*(my_class+1)).gender = 1;
    strcpy((my_class+1)->name,my_class[0].name);

    printf("(my_class+1)->name = %s\n", (my_class+1)->name);

    // 指针
    Student * p_stu = (my_class + 2);
    Student * p_stu1 = &my_class[2];

    p_stu->age = 18;
    p_stu->gender = 0;
    strcpy(p_stu->name, "oni");

    printf("my_class[2].name = %s\n",my_class[2].name);

    AddEnd();
}

void SCompositeType::s_struct_p() {
    AddHead("结构体数组一级指针");

    struct Student{
        int age;
        int render;
        char* name;
    };

    Student * stu = (Student*)malloc( sizeof (Student));
    stu->name = (char*) malloc( 8*sizeof (char));
    strcpy( stu->name, "lolita"); // name 的空间未分配
    printf("stu->name = %s\n",stu->name);
    if ( stu != nullptr )  {
        free(stu);
    }

    if ( stu->name )  {
        free(stu->name);
    }

    AddEnd();

}

void SCompositeType::s_union_() {
    AddHead("共用体");



    AddEnd();

}

void SCompositeType::heap_stack_direction() {
    AddHead("堆栈的增长方向");
    long stack_a = 0x1122334455667788;
    int stack_b = 0;
    printf("stack_a=%#x\n"
           "stack_b=%#x\n", &stack_a,&stack_b);

    char *heap_a = (char *) malloc(sizeof (char) * 4);
    char *heap_b = (char *) malloc(sizeof (char) * 4);
    strcpy(heap_a,"abc");
    strcpy(heap_b,"ABC");

    printf("heap_a=%d\n"
           "heap_b=%d\n", &(*heap_a),&(*heap_b));

    free(heap_a);
    free(heap_b);

    int a = 0x11;
    int b = 0x22;
    AddEnd();
}

char SCompositeType::cpu_arch(unsigned long n) {
    printf("*((char*)(&n)) = %#x", *((char*)(&n)));
    return *((char*)(&n)) == 0x88;
}

