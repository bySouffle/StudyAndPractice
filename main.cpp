//
// Created by by Souffle on 2021/5/1.
//

#include "SCompositeType.h"
#include "FileOperate.h"
#include "DictionarySearch.h"
#include "heap_stack_global.h"
#include "istream"
#include "stdio.h"
#include "vector"
#include "LogSystem.h"
#include "CharArrStr.h"
int main() {
#if 0
    {
    SCompositeType sct;
    sct.s_struct_arr();
    sct.s_struct_p();
    sct.heap_stack_direction();
    }
#endif
#if 0
    {
        FileOperate f;
        bys_dict::DictionarySearch d;
        bys_dict::DictKV *dic;
        {
            bys_code_analytics::heap_stack_global h;
            char *str = nullptr;
            str = h.get_str_from_static();
            printf("%s", str);
            str = nullptr;
            str = h.get_str_from_stack();
            printf("%s", str);
            str = nullptr;
            str = h.get_str_from_heap();
            printf("%s", str);

        }

    }
#endif
#if 0
    {
        int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int *arr_t = arr;
        printf("\nvalue %d\n", arr_t[2]);
        printf("\n*arr_t size = %ld\n", sizeof(arr) / sizeof(int));
        std::string sss = {("111")};
        printf("int string %s\n", sss.data());
        {
            std::vector<int> id_list_;
            std::vector<std::string> dirname_list_;

            for (int i = 0; i < 8; ++i) {
                if (i < 4) {
                    id_list_.push_back(0x10 + i);
                    dirname_list_.push_back(std::string("UartLog_") + std::to_string(i));
                    printf("idididid:::%x\n", id_list_.at(i));
                    printf("dararar:::%s\n", dirname_list_.at(i).data());
                }

                if (i > 3) {
                    id_list_.push_back(0x20 + i - 4);
                    dirname_list_.push_back(std::string("UartLog_") + std::to_string(i - 4));
                    printf("idididid:::%x\n", id_list_.at(i));
                    printf("darara:::%s\n", dirname_list_.at(i).data());

                }
            }

        }
    }
#endif
#if 0
    {
        bys_dict::DictionarySearch d;
        bys_dict::DictKV_t *dic;
        d.init_dict(&dic, 16);
        d.add_dict(&dic, "doge", " 狗币");
        d.add_dict(&dic, "shibe", " shi币");


        d.print_dict(&dic);
        d.search_dict(&dic, "doge");

    }
    {
        FileOperate f;
        f.m_close_win_out();
        f.m_fopen();
        f.m_fputc();
        f.m_fgetc();
        f.m_cat("b.txt");
        f.m_vi("b.txt");
        f.m_fputs();
        f.m_fgets();
        f.m_rand_num_file();
        f.m_read_file_arr();
        f.m_fgets_read();
        f.m_fwrite_fread();

        f.m_fcopy("c.txt", "cp.txt");
        f.m_fopt_random();
        f.m_pstruct_rw();
    }
#endif

#if 0
    {
        //  test log system
        RockLogSystem *logsys = RockLogSystem::get_instance();
        int i = 0;
        while (true) {
            logsys->add_log_info_item(logsys->trans_id(0, 0), std::string(32, 'a').data());
            logsys->add_log_info_item(logsys->trans_id(1, 0), std::string(32, 'b').data());
            logsys->add_log_info_item(logsys->trans_id(2, 0), std::string(32, 'c').data());
            logsys->add_log_info_item(logsys->trans_id(3, 0), std::string(32, 'd').data());

            logsys->add_log_info_item(logsys->trans_id(0, 1), std::string(32, 'e').data());
            logsys->add_log_info_item(logsys->trans_id(1, 1), std::string(32, 'f').data());
            logsys->add_log_info_item(logsys->trans_id(2, 1), std::string(32, 'g').data());
            logsys->add_log_info_item(logsys->trans_id(3, 1), std::string(32, 'h').data());
            i++;
            if (i == 1000) {
                break;
            }
        }

    }
#endif

    {
        //  字符串
       bys_practice::CharArrStr c;
       char bec[24] = {};
       c.copy_string("hello world!", bec);
        printf("be copy: %s\n", bec);
        memset(bec,0,sizeof bec);
        c.copy_string_while("hello world!", bec);
        printf("be copy: %s\n", bec);
        int cnt = c.cnt_substring("12332123123122312","123");
        printf("sub cnt = %d\n", cnt);
        int len = c.cnt_str_number("   zzzrrrrrrsadada  ");
        printf("len = %d\n", len);

        char dst[64] = {};
        c.cp_str_no_empty(" sssssd  ", dst);
        printf("copy dst: %s\n", dst);

        char *str_odd = nullptr;
        char *str_even = nullptr;
        c.getStr1Str2("1a2b3c4dz", &str_even, &str_odd);
        printf("even: %s odd:%s\n", str_even, str_odd);

        char k_v_buf[32] = "    key1  = 9 ";
        char k_buf[32] = {};
        char v_buf[32] = {};
        int v_len = 0;
        c.getKeyByValue(k_v_buf, k_buf, v_buf, &v_len);
        printf("k_v_buf = %s\n"
               "k_buf = %s\n"
               "v_buf = %s\n"
               "vlen = %d", k_v_buf,k_buf,v_buf,v_len);

        }
}