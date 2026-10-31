#include <bits/stdc++.h>

using namespace std;

#include "../include/inputHandler.h"

class MergeSorted
{
public:
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int idx = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[idx--] = nums1[i--];
            }
            else
            {
                nums1[idx--] = nums2[j--];
            }
        }

        while (j >= 0)
        {
            nums1[idx--] = nums2[j--];
        }
    }
};

int main()
{
    vector<int> nums1;
    vector<int> nums2;
    Input().getIntegerVector(nums1, 6);
    Input().getIntegerVector(nums2, 3);
    MergeSorted().merge(nums1, nums1.size(), nums2, nums2.size());

    for (int ele : nums1)
        cout << ele << " ";

    return 0;
}