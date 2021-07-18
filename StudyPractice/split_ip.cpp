//
// Created by by Souffle on 2021/7/15.
//

#include "split_ip.h"
#include "string"

int split_ip::spiit_ip2arr(char *ip_str, int *ip_arr) {
    if((ip_str == nullptr)){
        return -1;
    }
    char *sub_addr = nullptr;
    sub_addr = strtok(ip_str, ".");
    int n = 0;
    while (sub_addr != nullptr){
//        *(ip_str + n) = strtol(sub_addr, nullptr,10);

        *(ip_arr + n) = strtol(sub_addr, nullptr,10);
        printf("%s\n",(sub_addr));

        sub_addr = strtok(nullptr, ".");
        n++;
    }
    printf("%d.%d.%d.%d", ip_arr[0], ip_arr[1],ip_arr[2], ip_arr[3]);
    return 0;
}
