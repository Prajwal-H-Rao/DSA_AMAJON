#include <bits/stdc++.h>
using namespace std;

class LongestRepeatingCharacterReplacement
{
public:
    int characterReplacement(string s, int k)
    {
        int longest = 0, left = 0, maxFreq = 0;
        unordered_map<char, int> freqMap;

        string test = s;
        int it = k;
        for (int right = 0; right < test.size(); right++)
        {
            freqMap[s[right]]++;

            maxFreq = max(maxFreq, freqMap[s[right]]);

            // While the window is invalid ,keep moving left till the window is valid
            while ((right - left + 1) - maxFreq > k)
            {
                freqMap[s[left]]--;
                left++;
            }

            longest = max(longest, (right - left + 1));
        }
        return longest;
    }
};

int main()
{
    LongestRepeatingCharacterReplacement obj;
    cout << obj.characterReplacement("AABABBA", 1) << endl;
    return 0;
}