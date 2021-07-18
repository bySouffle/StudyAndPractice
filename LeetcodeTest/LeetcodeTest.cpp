//
// Created by by Souffle on 2021/5/29.
//

#include "Sub1.h"
#include "gtest//gtest.h"

class GTestLeetcode :public testing::Test{
protected:
    virtual void SetUp(){
        m_test = new Sub1();
    }
    virtual void TearDown(){
        delete m_test;
    }
    Sub1 *m_test;
};

TEST_F(GTestLeetcode, lab4){
    std::vector<std::vector<int > > matrix = { {1,   4,  7, 11, 15},
                                               {2,   5,  8, 12, 19},
                                               {3,   6,  9, 16, 22},
                                               {10, 13, 14, 17, 24},
                                               {18, 21, 23, 26, 30}
                                               };
    int target ;
    target = m_test->findNumberIn2DArray(matrix, 15);
    EXPECT_TRUE(target);
    target = m_test->findNumberIn2DArray(matrix, 0);
    EXPECT_FALSE(target);
    target = m_test->findNumberIn2DArray(matrix, 60);
    EXPECT_FALSE(target);
    target = m_test->findNumberIn2DArray(matrix, 14);
    EXPECT_TRUE(target);



}