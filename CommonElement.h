//
// Created by by Souffle on 2021/5/4.
//

#ifndef STUDYANDPRACTICE_COMMONELEMENT_H
#define STUDYANDPRACTICE_COMMONELEMENT_H

#include <string>

namespace bys_common
{

    class CommonElement {

 };

    inline void AddHead( std::string title ) {
        printf("1========= %s ===========\n",title.data());

    }

    inline void AddEnd() {
        printf("2=========================\n\n");

    }

}




#endif //STUDYANDPRACTICE_COMMONELEMENT_H
