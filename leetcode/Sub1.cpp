//
// Created by by Souffle on 2021/5/29.
//

#include "Sub1.h"
#include "map"

bool Sub1::findNumberIn2DArray(std::vector<std::vector<int>> &matrix, int target) {
//    int row = 0;
#define function0

#ifdef function0
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.at(0).size(); ++j) {
            if (matrix.at(i).at(j) == target){
                return true;
            }
        }
    }
    return false;

#elif function1

    int col = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.at(i).size(); ++j) {
            if(matrix.at(i).at(j) >= target){
                if(matrix.at(i).at(j)==target){
                    return true;
                } else{
                    col = j;
                    break;
                }
            }

        }
        if(matrix.at(i).at(col)>=target){
            if(matrix.at(i).at(col)==target){
                return true;
            } else{
                return false;
            }
        }
    }

    return false;

#endif
}


std::vector<int> Sub1::twoSum(std::vector<int> &nums, int target) {
    std::map<int, int>dict;
    for (int i = 0; i < nums.size(); ++i) {
        //  map::count 判断重复 返回0 1
        if( dict.count(target - nums.at(i) ) ) {
            return {dict[target-nums[i]], i};
        }
        dict[nums[i]] = i;
    }

    return std::vector<int>();  // {}
}
