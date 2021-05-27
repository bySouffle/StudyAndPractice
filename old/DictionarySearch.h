//
// Created by by Souffle on 2021/5/11.
//

#ifndef STUDYANDPRACTICE_DICTIONARYSEARCH_H
#define STUDYANDPRACTICE_DICTIONARYSEARCH_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
namespace bys_dict {


    typedef struct DictKV
    {
        char *key;
        char *value;
    }DictKV_t;

    enum Return_Status{
        kEmptyDict_ = -1,

    };

    enum SizeParam{
        kSaveWordSize_ = 36,
    };

    class DictionarySearch {
    public:

        DictionarySearch();


        int init_dict(DictKV **dict, int num);
        int count_file_word(const char *filename);
        int current_word_cnt();
        int find_dict_insert_index(DictKV **dict);
        int add_dict(DictKV **dict, const char*key, const char *value);
        int del_dict(DictKV **dict);
        int file_to_dict(DictKV **dict, const char * filename);
        int print_dict(DictKV **dict);
        int search_dict(DictKV **dict, char *key);
        DictKV *dict_;

    private:
        int offset_;

    };


}

#endif //STUDYANDPRACTICE_DICTIONARYSEARCH_H
