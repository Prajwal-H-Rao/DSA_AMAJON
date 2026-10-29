#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

#include "../include/inputHandler.h"

using namespace std;

class MinimumWindowSubstring
{
public:
    string minWindow(string s, string t)
    {
        if (t.empty() || s.empty() || t.size() > s.size())
            return "";

        unordered_map<char, int> table;

        for (char ele : t)
            table[ele]++;

        int left = 0;
        int required = t.size();
        int minWindowLength = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++)
        {
            if (table[s[right]] > 0)
                required--;

            table[s[right]]--;

            while (required == 0)
            {
                int windowLength = right - left + 1;

                if (windowLength < minWindowLength)
                {
                    minWindowLength = windowLength;
                    start = left;
                }

                table[s[left]]++;

                if (table[s[left]] > 0)
                    required++;

                left++;
            }
        }
        return minWindowLength == INT_MAX ? ""
                                          : s.substr(start, minWindowLength);
    }
};

int main()
{
    string s, t;
    Input().getString(s);
    Input().getString(t);

    cout << MinimumWindowSubstring().minWindow(s, t) << endl;
    return 0;
}