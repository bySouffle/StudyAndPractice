//
// Created by by Souffle on 2021/5/27.
//

#include "nnarr.h"

int nnarr::create_box(Box_t ***box) {

    Box_t **m_box = (Box_t**) malloc(sizeof (Box_t*)*3);

    for (int i = 0; i < 3; ++i) {
        m_box[i] = (Box_t* )malloc(sizeof (Box_t) );
        m_box[i]->id = (char *) malloc(sizeof (char)*2);
        m_box[i]->small_box = (char **) malloc(sizeof (char *)*4);
        for (int j = 0; j <4; ++j) {
            m_box[i]->small_box[j] = (char *)malloc(sizeof (char )*5);
        }
    }
    *box = m_box;
    return 0;
}

int nnarr::delete_box(Box_t ***box) {
    Box_t **m_box = *box;
    if(box == nullptr){
        return 0;
    } else{
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 4; ++j) {
                free(m_box[i]->small_box[j]);
                m_box[i]->small_box[j]= nullptr;
            }
            free(m_box[i]->id);
            free(m_box[i]->small_box);
            m_box[i]->id= nullptr;
            m_box[i]->small_box= nullptr;

        }
        for (int i = 0; i < 3; ++i) {
            free(m_box[i]);
            m_box[i]= nullptr;
        }
    }
    free(m_box);
    m_box= nullptr;
    return 0;
}

int nnarr::add_box(Box_t ***box) {
    Box_t **m_box = *box;
    for (int i = 0; i < 3; ++i) {
        char id[2] = {};
        sprintf(id, "%c", 66+i);
        memcpy(m_box[i]->id, id, 2);
        for (int j = 0; j < 4; ++j) {
            char sbox[5] = {};
            sprintf(sbox, "%c%c%c%c", 97+i,97+i,97+i,97+i);
            memcpy(m_box[i]->small_box[j],sbox,5);
        }
    }
    return 0;
}

int nnarr::out_box(Box_t ***box) {
    Box_t **m_box = *box;
    for (int i = 0; i < 3; ++i) {
        printf("id [%d] %s\n",i, m_box[i]->id);
        for (int j = 0; j < 4; ++j) {
            printf("[%d][%d]%s\n",i, j, m_box[i]->small_box[j]);
        }
    }
    return 0;
}

nnarr::nnarr() {

}
