class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> answer(nums.size(), 1);
        int curProd = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            answer[i] = curProd;
            curProd *= nums[i];
        }
        curProd = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            answer[i] = answer[i] * curProd;
            curProd *= nums[i];
        }
        return answer;
    }
};