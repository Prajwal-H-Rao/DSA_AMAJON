class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> series;
        for (int num : nums)
        {
            series.insert(num);
        }
        int max_count = 0;
        for (const int &element : series)
        {
            if (series.find(element - 1) == series.end())
            {
                int val = element, count = 0;
                while (series.find(val) != series.end())
                {
                    val++;
                    count++;
                }
                max_count = max(count, max_count);
            }
        }
        return max_count;
    }
};