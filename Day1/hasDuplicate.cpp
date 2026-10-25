#include "../Utils/Input.h"
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> occurance;
        for (int num : nums)
        {
            if (occurance.find(num) != occurance.end())
            {
                return true;
            }
            occurance[num] = 1;
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {1, 2, 4, 3, 4, 5};
    int size = nums.size();
    Solution s;
    cout << ((bool)s.containsDuplicate(nums)) << endl;
    return 0;
}