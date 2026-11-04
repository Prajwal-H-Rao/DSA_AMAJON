#include <bits/stdc++.h>
using namespace std;

class ReverseWordsInAString
{
public:
    string reverseWords(string s)
    {
        int left = 0;
        int right = 0;

        string reversed = "";
        string curr = "";

        while (right < s.size())
        {
            if (s[right] == ' ')
            {
                if (right > left)
                {
                    curr = s.substr(left, right - left);
                    reversed = curr + " " + reversed;
                }

                left = right + 1;
            }

            right++;
        }

        if (right > left)
        {
            curr = s.substr(left, right - left);
            reversed = curr + " " + reversed;
        }

        if (!reversed.empty())
            reversed.pop_back();

        return reversed;
    }
};

int main()
{
    ReverseWordsInAString r;

    cout << r.reverseWords("the sky is blue") << endl;

    return 0;
}