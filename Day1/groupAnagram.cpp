class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        unordered_map<string, vector<string>> map;
        for (string s : strs)
        {
            string copy{s};
            sort(s.begin(), s.end());
            map[s].push_back(copy);
        }
        vector<vector<string>> answer;
        for (auto &[key, value] : map)
        {
            answer.push_back(value);
        }
        return answer;
    }
};