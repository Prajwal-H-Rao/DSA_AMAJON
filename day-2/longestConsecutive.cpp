#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <unordered_set>

#include "../include/inputHandler.h"

using namespace std;

class LongestConsecutive
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numberset(nums.begin(), nums.end());
        int longest = 0;

        for (int number : numberset)
        {
            if (numberset.find(number - 1) != numberset.end())
            {
                continue;
            }

            int length = 1;
            int current = number;
            while (numberset.find(current + 1) != numberset.end())
            {
                current++;
                length++;
            }

            longest = max(longest, length);
        }
        return longest;
    }
};

int main()
{
    // 100 4 200 1 3 2
    vector<int> nums;
    Input().getIntegerVector(nums, 2);
    cout << LongestConsecutive().longestConsecutive(nums) << endl;
    return 0;
}