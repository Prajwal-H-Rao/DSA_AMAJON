#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "../include/inputHandler.h"

using namespace std;

class GroupAnagrams
{
private:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        int freq[26] = {0};

        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int count : freq)
        {
            if (count != 0)
                return false;
        }

        return true;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> groupedAnagrams;

        unordered_map<string, vector<string>> groups;

        for (string elements : strs)
        {
            // Store the copy to add to the solution (New thing learnt):
            // copy (string literal for each iteration s)= {"eat", "tea", "tan", "ate", "nat", "bat"} for each element
            string copy{elements};

            // Sort the original strings and the entire list to get the groups accordingly.
            sort(elements.begin(), elements.end());
            // s = {"aet", "aet", "ant", "aet", "ant", "abt"}

            groups[elements].push_back(copy);
        }

        // Iterate the group {map} to get the values
        // for (auto &[key, value] : groups)
        // groupedAnagrams.push_back(value);

        for (auto &it : groups)
            groupedAnagrams.push_back(it.second);

        return groupedAnagrams;
    }
};

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = GroupAnagrams().groupAnagrams(strs);

    for (vector groups : res)
    {
        cout << "{";
        for (string anagrams : groups)
        {
            cout << anagrams << ",";
        }
        cout << "}";
    }
    cout << endl;

    return 0;
}