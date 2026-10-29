#include <bits/stdc++.h>
#include "../include/inputHandler.h"

using namespace std;

class MajorityElement
{
public:
    int majorityElement(vector<int> &nums)
    {
        int majority;
        int cnt = 0;
        for (int element : nums)
        {
            if (cnt == 0)
                majority = element;

            if (element == majority)
                cnt++;

            else
                cnt--;
        }
        return majority;
    }
};

int main()
{
    vector<int> nums;
    Input().getIntegerVector(nums, 10);

    cout << "MAJORITY ELEMENT : " << MajorityElement().majorityElement(nums) << endl;

    return 0;
}