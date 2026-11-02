#include <bits/stdc++.h>

#include "../include/inputHandler.h"

using namespace std;

class LengthOfLongestSubstring
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> freq;

        int longest = 0;
        int left = 0;

        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i]]++;

            while (freq[s[i]] > 1)
            {
                freq[s[left]]--;
                left++;
            }

            longest = max(longest, i - left + 1);
        }

        return longest;
    }
};

int main()
{
    LengthOfLongestSubstring obj;
    cout << obj.lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}