/*
 * @Author: andy 
 * @Date: 2019-08-17 18:51:18 
 * @Last Modified by: andy
 * @Last Modified time: 2019-08-17 19:41:32
 */

#include "stdlib.h"
#include "vector"
#include "unordered_map"
#include "iostream"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() <= 1)
            return vector<int>{};

        for (int i = 0; i < nums.size() - 1; i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target)
                    return vector<int>{i, j};
        return vector<int>{};
    }

    vector<int> twoSum_ans2(vector<int>& nums, int target) {
        unordered_map<int, int> mapping;

        for (int i = 0; i < nums.size(); i++) {
            mapping.insert({nums[i], i});
        }

        for (int i = 0; i < nums.size(); i++) {
            auto j = mapping.find(target - nums[i]);
            if (j != mapping.end() && j->second != i)
                return vector<int>{i, j->second};
        }
        return vector<int>{};
    }
};

int main() {
    Solution ss;

    vector<int>nums = {1, 2, 3};
    vector<int> result = ss.twoSum_ans2(nums, 3);

    for(int i=0; i<result.size(); i++) {
        printf("%d", result[i]);
    }
    return 0;
}