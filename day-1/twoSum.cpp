#include <iostream>
#include <vector>
#include <unordered_map>

#include "../include/inputHandler.h"

using namespace std;

class TwoSum
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // Brute Force Approach :
        // for (int i = 0; i < nums.size(); i++)
        //     for (int j = i + 1; j < nums.size() - 1; j++)
        //     {
        //         if (nums[i] + nums[j] == target)
        //         {
        //             return {nums[i], nums[j]};
        //         }
        //     }
        // return {};

        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            if (map.count(complement))
                return {complement, nums[i]};

            map[nums[i]] = complement;
        }
        return {};
    }
};

int main()
{
    vector<int> nums;
    Input().getIntegerVector(nums, 4);

    vector<int> res = TwoSum().twoSum(nums, 9);

    for (int i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}