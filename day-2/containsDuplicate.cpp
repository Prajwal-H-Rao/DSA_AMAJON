#include <iostream>
#include <unordered_set>

#include "../include/inputHandler.h"

using namespace std;

class ContainsDuplicate
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        // // Brute Force Approach :
        // for (int i = 0; i < nums.size(); i++)
        //     for (int j = i + 1; j < nums.size(); j++)
        //         if (nums[i] == nums[j])
        //             return true;

        // return false;

        // // Optimal Approach :
        unordered_set<int> seen;
        for (int element : nums)
        {
            if (seen.count(element))
                return true;
            seen.insert(element);
        }
        return false;
    }
};

int main()
{
    vector<int> nums;
    Input().getIntegerVector(nums, 5);
    bool res = ContainsDuplicate().containsDuplicate(nums);
    if (res)
        cout << "Duplicate found" << endl;
    else
        cout << "No Duplicates" << endl;
    return 0;
}