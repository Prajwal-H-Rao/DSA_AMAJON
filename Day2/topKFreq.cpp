class Solution
{

public:
    struct Compare
    {
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        unordered_map<int, int> numbers;
        for (int num : nums)
        {
            numbers[num]++;
        }
        for (auto keys : numbers)
        {
            pq.push(keys);
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> answer;
        while (!pq.empty())
        {
            answer.push_back(pq.top().first);
            pq.pop();
        }
        return answer;
    }
};