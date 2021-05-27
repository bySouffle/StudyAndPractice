//
// Created by by Souffle on 2021/5/17.
//

#include "CharArrStr.h"


namespace bys_practice {
    int CharArrStr::copy_string(const char *src, char *dst) {
        if (src == nullptr || dst == nullptr) {
            return -1;
        }
        for (int i = 0; *(src + i) != 0; ++i) {
            dst[i] = src[i];
        }
        return 0;
    }

#define _func1_

    int CharArrStr::copy_string_while(const char *src, char *dst) {
        if (src == nullptr || dst == nullptr) {
            return -1;
        }
        int i = 0;
#ifndef _func1

        while (*src != '\0') {
            *dst = *src;
            *dst++;
            *src++;
        }
#else
        while (src[i] != '\0')
        {
            *dst = src[i];
            dst ++;
            i ++;

        }
#endif
        return 0;
    }

    int CharArrStr::cnt_substring(char *src, const char *sub) {

#define sub3
#ifdef sub1
        if(src==nullptr || sub==nullptr){
            return -1;
        }
        char *str = nullptr;
        int cnt = 0;
       while (1){
           src = strstr(src,sub);
           if(src != nullptr){
               cnt += 1;
           } else{
               break;
           }
           src += strlen(sub);
           }
       return cnt;
#endif
#ifdef sub2
        char *str = src;
        int cnt = 0;
        while ( str != nullptr )
        {
            str = strstr(str, sub);
            if(str!= nullptr){
                str += strlen(sub);
                cnt++;
            }
        }
        return cnt;

#endif
#ifdef sub3
        int cnt = 0;
        while ((src = m_strstr(src, sub)) != nullptr) {
            cnt++;
            src += strlen(sub);
        }
        return cnt;
    }

#endif

#ifdef sub4
#endif


    char *CharArrStr::m_strstr(char *src, const char *sub) {
        int stdlen = strlen(sub);
        int j = 0;

        for (int i = 0; i < strlen(src); ++i) {
            if (src[i] == sub[j]) {
                printf("[src[i] = %c] [dst[j] = %c]\n", src[i], sub[j]);
                j++;

            } else {
                j = 0;
            }
            if (j == stdlen) {
                return &src[i - stdlen];
            }
        }
        if (j < stdlen) {
            return nullptr;
        }


    }

    int CharArrStr::cnt_str_number(char *str) {
        if (strlen(str) == 0) {
            return 0;
        }

        int start = 0;
        int end = strlen(str) - 1;

        while ((str[start] == ' ') || (str[end] == ' ')) {
            if (str[start] == ' ') {
                start++;
            }
            if (str[end] == ' ') {
                end--;
            }
        }

        int len = end - start;
        return len;

    }

    int CharArrStr::cp_str_no_empty(char *str, char *dst) {
        if (strlen(str) == 0) {
            return 0;
        }

        int start = 0;
        int end = strlen(str) - 1;

        while ((str[start] == ' ') || (str[end] == ' ')) {
            if (str[start] == ' ') {
                start++;
            }
            if (str[end] == ' ') {
                end--;
            }
        }
        int len = end - start + 1;
        memcpy(dst, &str[start], len);
        dst[end + 1] = 0;
        return 0;
    }

    int CharArrStr::getStr1Str2(char *source, char **str1, char **str2) {
        *str1 = new char[128];
        *str2 = new char[128];
        int str_1_cnt = 0;
        int str_2_cnt = 0;

        for (int i = 0; i < strlen(source); ++i) {
            char a = source[i];
            int ctoi = a - '0';
            if (ctoi < 11) {
                if (ctoi % 2 == 0) {
                    (*str1)[str_1_cnt] = a;
                    str_1_cnt++;

                } else {
                    (*str2)[str_2_cnt] = a;
                    str_2_cnt++;

                }
            } else {

            }
        }
//        str1 = str_1;
//        str2 = str_2;
        return 0;
    }

    int CharArrStr::getKeyByValue( char *k_v_buf, char *k_buf, char *v_buf, int *v_buf_len) {
        char *str_eq_after = nullptr;
        str_eq_after = strchr(k_v_buf, '=');
        printf("root %s\n", k_v_buf);
        if (str_eq_after == nullptr) {
            k_buf = nullptr;
            v_buf = nullptr;
            v_buf_len = 0;
            return 0;
        } else{
            int i = 0;
            int j = 0;
            while (k_v_buf[i] != '='){
                if(k_v_buf[i] != ' '){
                    k_buf[j] = k_v_buf[i];
                    j++;
                }
                i++;
            }
            i = 1; j = 0;
            while (str_eq_after[i] != 0){
                if(str_eq_after[i] != ' '){
                    v_buf[j] = str_eq_after[i];
                    j++;
                }
                i++;
            }
            *v_buf_len = j;
        }

        return 0;
    }
    int CharArrStr::double_arr() {
#if 0
        char a[2][4] = {{'a','b','c','d'},{'e','f','g','h'}};
        char*p = &a[0][0];
        char *p1 = a[0];
        printf("&a[0][0] = %s\n"
               "a[0] = %s\n", p, p1);
#endif
#if 0
        char a[3][4] = {{'a','b','c','d'},{'e','f','g','h'},{'e','f','g','h'}};
        char*p = &a[0][0];
        char *p1 = a[0];
        printf("&a[0][0] = %s\n"
               "a[0] = %s\n", p, p1);
#endif
#if 01
        char a[3][4] = {{"abc"},{"def"},{"ghi"}};
        char*p = &a[0][0];
        char *p1 = a[0];
        printf("&a[0][0] = %s\n"
               "a[0] = %s\n"
               "a = %d\n"
               "a+1 = %d\n", p, p1, a, a+1);
        for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) printf("a[i] = %s\n", a[i]);
#endif
        return 0;
    }

    int CharArrStr::double_arr_p() {
        int x = 4;
        int y = 3;
        char **xy = (char**) malloc (y*sizeof (char *));
    if(xy == nullptr){
        return 0;
    }


        for (int i = 0; i < x; ++i) {
            xy[i] = (char*) malloc(x * sizeof (char ));
        }
        for (int i = 0; i < x; ++i) {
            if(i%2==0){
                memcpy(xy[i],"zzz",4);
            } else{
                memcpy(xy[i],"xxx",4);
            }
        }
        for (int i = 0; i < x; ++i) {
            if(i%2==0){
                memcpy( *(xy+i), "vvv",4);
             } else{
                memcpy( *(xy+i), "ddd",4);

            }
        }

        for (int i = 0; i < 3; ++i) {
            printf("%s\n",xy[i]);
            printf("%s\n",*(xy+i));
        }


        char abc [5] = "1234";
        char*p = abc;
        printf("%s[%s]\n", p);



        return 0;
    }

    int CharArrStr::double_int_p() {
        int x = 4;
        int y = 3;
        int **p = (int **)malloc(y*sizeof (int *));
        for (int i = 0; i < y; ++i) {
            p[i] = (int *) malloc(x*sizeof (int));
        }
        p[1][2] = 10;
        (*(p+1))[3] = 11;

        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < x; ++j) {
                printf("%d ",p[i][j]);
            }
        }

        for (int i = 0; i < y; ++i) {
            free(p[i]);
            p[i]= nullptr;
        }
        free(p);
        p = nullptr;

        return 0;
    }


    int CharArrStr::mk_n2ArrChar_heap(char **&n2ArrChar, int rows, int cols) {
        n2ArrChar = (char**) malloc( rows *sizeof (char*));
        if(n2ArrChar == nullptr){
            return -1;
        }
        for (int i = 0; i < rows; ++i) {
            n2ArrChar[i] = (char *) malloc(cols*sizeof (char ));
            if(n2ArrChar[i] == nullptr){
                return -2;
            }
        }
        return 0;
    }

    int CharArrStr::free_n2Arr_heap(char **&n2Arr, int rows, int cols) {
        for (int i = 0; i < rows; ++i) {
            free(n2Arr[rows]);
            n2Arr[rows] = nullptr;
        }
        free(n2Arr);
        n2Arr = nullptr;
        return 0;
    }

    int CharArrStr::print_n2Arr(char **&n2Arr, int rows, int cols) {
        printf("\t=====\tStart\t=====\t\n");
        for (int i = 0; i < rows; ++i) {
            printf("\trow[%d]: %s\n", i, n2Arr[i]);
        }
        printf("\t=====\tend\t=====\t\n");
        return 0;
    }

    int CharArrStr::replaceSubstr(char *src, char *dst, char *sub, char *re_sub) {
//        dst = src;
        char* find_char = nullptr;
        while ( (find_char = strstr(src,sub)) != nullptr  ){
            memcpy(find_char,re_sub, strlen(re_sub));
            src += strlen(sub);
        }
        return 0;
    }

    int CharArrStr::spitString(const char *str, char c, char (*buf)[30], int *count) {
        char *sub = nullptr;
        char cs[4] = {c};
        int len = strlen(str) +1;
        char m_str[len];
        memcpy(m_str,str,len);

        sub = strtok(m_str,cs);
        int n = 0;
        while (sub!= nullptr){

            memcpy(buf[n],sub, strlen(sub)+1);
            n++;
            sub = strtok(NULL, cs);

        }
        int m = sizeof (*str);
        int nn = sizeof (&str[0]);
        *count = (sizeof (str))/(sizeof (str[0]));
        return 0;
    }

    int CharArrStr::spitString2(const char *str, char c, char **myp, int *count) {
        char **n2arr_heap = (char**) malloc(10*sizeof (char *));
        for (int i = 0; i < 10; ++i) {
            n2arr_heap[i] = (char *) malloc(30*sizeof (char ));
        }
        char* sub_str = nullptr;
        int i = 0;
        char spl[4] = {c};
//        spl[0] = c;
        char copy_str[100] = {};
        memcpy(copy_str, str, strlen(str)+1);
        sub_str = strtok(copy_str,spl);
        while (sub_str!= nullptr){
            strcpy(n2arr_heap[i], sub_str);
            sub_str = strtok(nullptr, spl);
        }
        myp = n2arr_heap;
//        *count = sizeof(n2arr_heap)/sizeof(n2arr_heap[0]);

        return 0;
    }

    int CharArrStr::replaceSubstr2(char *src, char *dst, char *sub, char *re_sub) {
        char *start = src;
        char *find = nullptr;
        char m_dst[128] = {};

        while ( (find = strstr(start, sub)) != nullptr ){
            strncat(m_dst, start, find-start);
            strcat(m_dst, re_sub);
            start=start+ strlen(sub)+(find-start);
        }
        strcat(m_dst, start);

        memcpy(dst, m_dst,sizeof (m_dst));

        return 0;
    }


}


