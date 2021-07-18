//
// Created by by Souffle on 2021/7/15.
//

#ifndef MAIN_SPLIT_IP_H
#define MAIN_SPLIT_IP_H


class split_ip {
public:
    char *ip_addr;
    int ip_addr_arr[4];

    int spiit_ip2arr(char* ip_str, int * ip_arr);
};

#endif