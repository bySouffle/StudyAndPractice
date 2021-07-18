//
// Created by by Souffle on 2021/5/27.
//

#include "gtest/gtest.h"
#include "nnarr.h"
#include "split_ip.h"

class subtest_pp : public testing::Test {
protected:
    virtual void SetUp() {
        n = new nnarr();
        s = new split_ip();
    }

    virtual void TearDown() {
        delete n;
        delete s;
    }

    nnarr *n;
    split_ip *s;

};

TEST_F(subtest_pp, sub1) {
    Box_t **b = nullptr;
    n->create_box(&b);
    n->add_box(&b);
    n->out_box(&b);
    n->delete_box(&b);

}

TEST_F(subtest_pp, splt){
//    char *addr_ip = "192.168.0.138";
    char addr_ip[15] = {};
    memcpy(addr_ip, "192.168.0.138",15);
    int ip_arr[4] = {};
    s->spiit_ip2arr(addr_ip, ip_arr);
}


int sort_arr(int *arr, int n) {
#if 0
    for (int j = 0; j < n; ++j) {

        for (int i = 0; i < n - 1; ++i) {

            if (arr[i] > arr[i + 1]) {
                arr[i] = arr[i] + arr[i + 1];
                arr[i + 1] = arr[i] - arr[i + 1];
                arr[i] = arr[i] - arr[i + 1];
            }
        }
    }
#endif
#if 1
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[min] > arr[j]) {
                min = j;
                if (i != min) {
                    arr[i] = arr[i] ^ arr[min];
                    arr[min] = arr[i] ^ arr[min];
                    arr[i] = arr[i] ^ arr[min];


                }
            }
        }
    }
#endif

}


TEST(sort_arr, change) {
    int arr[] = {1, 4, 3, 2, 8};
//int arr[5] = {2,5,1,3,4};
    sort_arr(arr, 5);
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", arr[i]);
    }
}


//  字符串截取

int str_split_mid(char *str, char *rst){
    if(str== nullptr){
        rst = nullptr;
        return -1;
    }
    char *beg = strchr(str, '#');
    char *end = strchr(str, '@');
    memcpy(rst, beg + 1, end-beg - 1);
    return 0;

}

TEST(str_split_mid, split){
    char arr[48] = {};
    str_split_mid("123456#bysouffle@abcde", arr);
    ASSERT_STREQ("bysouffle", arr);
}

int reaserch_sub_str(char *str, char *sub_str){
    if((str == nullptr) || (sub_str == nullptr)){
        return 0;
    }
    int i = 0;
//    char *str1 = nullptr;
    while ((str = strstr(str, sub_str))!= nullptr){
        str+= strlen(sub_str);
        i++;
    }
    return  i;

}

TEST(reaserch_sub_str, split){
    char arr[48] = "12321232212123";
    int ret = reaserch_sub_str(arr, "123");
    EXPECT_EQ(ret, 3);
}



int struct_offset(){
    struct test_st{
        char name [20];
        char age [14];
        char z_name [14];
    } test_st_t;

    int index = offsetof(test_st, name);
    int index_2 = offsetof(test_st, age);
    int index_3 = offsetof(test_st, z_name);
    printf("name:%d  age:%d  z_name:%d\r\n", index, index_2, index_3);
}

TEST(struct_offset, offset){
    struct_offset();
}