#include <iostream>
#include <vector>

#include "../include/inputHandler.h"

using namespace std;

class FindDuplicate
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        int slow2 = 0;

        while (slow2 != slow)
        {
            slow2 = nums[slow2];
            slow = nums[slow];
        }

        return slow;
    }
};

int main()
{
    vector<int> nums;
    Input().getIntegerVector(nums, 5);
    cout << FindDuplicate().findDuplicate(nums) << endl;

    return 0;
}