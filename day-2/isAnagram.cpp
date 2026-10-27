#include <iostream>
#include <string>
#include <unordered_map>

#include "../include/inputHandler.h"

using namespace std;

class IsAnagram
{
public:
    bool isAnagram(string s, string t)
    {
        // // Sub-Optimal Approach :
        // unordered_map<char, int> seen;
        // if (s.size() != t.size())
        //     return false;
        // for (char character : s)
        //     seen[character]++;

        // for (char character : t)
        // {
        //     if (seen[character] == 0)
        //         return false;

        //     seen[character]--;
        // }
        // return true;

        // Optimal Approach :
        // Create a frequency array:
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
};

int main()
{
    string s, t;
    Input().getString(s);
    Input().getString(t);

    bool res = IsAnagram().isAnagram(s, t);

    if (res)
        cout << "Anagram" << endl;
    else
        cout << "Not an Anagram" << endl;
    return 0;
}