//
// Created by by Souffle on 2021/5/11.
//

#include "DictionarySearch.h"
namespace bys_dict {


    int DictionarySearch::init_dict(DictKV **dict, int num) {
        if (*dict == nullptr) {
            *dict = (DictKV *) malloc(num * sizeof(DictKV));
        }

        return 0;
    }

    int DictionarySearch::add_dict(DictKV **dict, const char *key, const char *value) {
        if (*dict == nullptr) {
            return kEmptyDict_;
        }
        (*dict)[offset_].key = (char *) malloc(strlen(key) + 1);
        strcpy((*dict)[offset_].key, key);
        (*dict)[offset_].value = (char *) malloc(strlen(value) + 1);
        strcpy((*dict)[offset_].value, value);
        offset_ += 1;
        return 0;
    }

    int DictionarySearch::find_dict_insert_index(DictKV **dict) {
        free((*dict)[offset_].key);
        free((*dict)[offset_].value);
        offset_--;

        if (!offset_) {
            delete *dict;
        }

        return 0;
    }

    int DictionarySearch::del_dict(DictKV **dict) {
        delete (*dict)[offset_].key;
        delete (*dict)[offset_].value;
        offset_--;
        return 0;

        return 0;
    }

    int DictionarySearch::current_word_cnt() {
        return offset_;
    }

    int DictionarySearch::file_to_dict(DictKV **dict, const char *filename) {
        if (*dict == nullptr) {
            return kEmptyDict_;
        }

        char key_buf[kSaveWordSize_] = {};
        char value_buf[kSaveWordSize_] = {};

        count_file_word(filename);

        FILE *m_file = fopen(filename, "r");


        while (true) {
            fgets(key_buf, kSaveWordSize_, m_file);
            fgets(value_buf, kSaveWordSize_, m_file);

            add_dict(dict, key_buf, value_buf);

            memset(key_buf, 0, kSaveWordSize_);
            memset(value_buf, 0, kSaveWordSize_);

            if (feof(m_file)) {
                break;
            }
        }
        return 0;
    }

    int DictionarySearch::count_file_word(const char *filename) {
        FILE *m_file = fopen(filename, "r");
        char buf[kSaveWordSize_] = {};
        int count = 0;
        while (!feof(m_file)) {
            fgets(buf, kSaveWordSize_, m_file);
            fgets(buf, kSaveWordSize_, m_file);
            count++;

        }
        fclose(m_file);
        m_file = nullptr;
        return count;
    }

    int DictionarySearch::print_dict(DictKV **dict) {
        for (int i = 0; i < offset_; ++i) {
            printf("key[%s] value[%s]\n", (*dict)[i].key, (*dict + i)->value);

        }
        return 0;
    }

    DictionarySearch::DictionarySearch() : dict_(nullptr), offset_(0) {
        init_dict(&dict_, 5);
    }

    int DictionarySearch::search_dict(DictKV **dict, char *key) {
        for(int i = 0; i < offset_;++i)
        {
            if(strcmp(((*dict+i)->key),key)==0)
            {
                printf("value: [%s]\n", (*dict[i]).value);
            }
        }
        return 0;
    }

}