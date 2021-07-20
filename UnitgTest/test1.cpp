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


void ip_calc_ipchecksum(void *pack_info){
    int8_t* m_pack_info = (int8_t*)pack_info  ;
    m_pack_info[24] = 0;
    m_pack_info[25] = 0;

    m_pack_info = &m_pack_info[13];
    printf("m_pack_info: %x\r\n", *m_pack_info++);
    int index = 0;
    int ip_index = 0;

    int32_t calc_sum = 0;
    int16_t ip_head[10] = {};
    int16_t cksum = 0;

    while (index != 20)
    {
        /* code */
        ip_head[ip_index] = ( ip_head[ip_index] |( m_pack_info[index] & 0xFF) ) << 8;
        printf("m_pack_info[%d] = %x\r\n", index,  m_pack_info[index] );

        ip_head[ip_index] = ( ip_head[ip_index] | (m_pack_info[index+1] & 0xFF) );
        printf("m_pack_info[%d] = %x\r\n", index+1,  m_pack_info[index+1] );
        printf("ip_head[%d] = %x\r\n",ip_index,  ip_head[ip_index] );
        calc_sum += (ip_head[ip_index] & 0xffff );
        printf("zzzzzzzzzzz%d %x %x\r\n", index, ip_head[ip_index], calc_sum);
        index += 2;
        ip_index += 1;
    }
    if(index == 20){
        calc_sum=(calc_sum>>16)+(calc_sum&0xffff);  //把高位的进位，加到低八位，其实是32位加法
        calc_sum+=(calc_sum>>16);  //add carry
        cksum=~calc_sum;   //取反\

        printf("1111111ck_sum = %x\r\n", calc_sum);
        printf("2222222ck_sum = %x\r\n", cksum);
    }


}

void ip_calc_ipchecksum_1(void *pack_info){
    int8_t* m_pack_info = (int8_t*)pack_info  ;
    m_pack_info[24] = 0;
    m_pack_info[25] = 0;

    m_pack_info = &m_pack_info[13];
    printf("m_pack_info: %x\r\n", *m_pack_info++);
    int index = 0;
    int ip_index = 0;

    int32_t calc_sum = 0;
    int16_t ip_head[10] = {};
    int32_t cksum = 0;

    while (index != 20)
    {
        /* code */
        ip_head[ip_index] = ( ip_head[ip_index] |( m_pack_info[index] & 0xFF) ) << 8;
        printf("m_pack_info[%d] = %x\r\n", index,  m_pack_info[index] );

        ip_head[ip_index] = ( ip_head[ip_index] | (m_pack_info[index+1] & 0xFF) );
        printf("m_pack_info[%d] = %x\r\n", index+1,  m_pack_info[index+1] );

        printf("ip_head[%d] = %x\r\n",ip_index,  ip_head[ip_index] );

        calc_sum += (ip_head[ip_index] & 0xffff );


        printf("zzzzzzzzzzz%d %x %x\r\n", index, ip_head[ip_index], calc_sum);
        index += 2;
        ip_index += 1;
    }
    if(index == 20){
        calc_sum=(calc_sum>>16)+(calc_sum&0xffff);  //把高位的进位，加到低八位，其实是32位加法
        calc_sum+=(calc_sum>>16);  //add carry
         calc_sum = 0x1e21;
//        calc_sum = 0xd997;
        cksum = ( ((0x000F-(calc_sum)&0xF000) >> 12) << 12 |
                  ((0x000F-(calc_sum)&0x0F00) >> 8 ) << 8  |
                  ((0x000F-(calc_sum)&0x00F0) >> 4 ) << 4  |
                  (0x000F-(calc_sum)&0x000F)   );

        printf("%x %x %x %x\r\n", ((0x000F-(calc_sum)&0xF000) >> 12) ,
               ((0x000F-(calc_sum)&0x0F00) >> 8 ),
               ((0x000F-(calc_sum)&0x00F0) >> 4 ),
               (0x000F-(calc_sum)&0x000F));
        // cksum=~calc_sum;   //取反\

        printf("1111111ck_sum = %x\r\n", calc_sum);
        printf("2222222ck_sum = %x\r\n", cksum);
    }


}


TEST(ip_calc_ipchecksum, check){
uint8_t iphead[] = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff,

        //  Type
        0x45, 0x00,
        //  Length
        0x00, 0x25,
        //  Identification
        0xd4, 0xc3,
        //  flag offset
        0x00, 0x00,
        //  TTL Protocol
        0x80, 0x11,
        //  CheckSum    !!!!!
        0x11, 0x11,
        //  src ip
        0xc0, 0xa8, 0x01, 0x6f,
        //  dst ip
        0xc0, 0xa8, 0x01, 0x65,

        //  padding
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};
    ip_calc_ipchecksum_1(iphead);

}
