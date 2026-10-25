class Solution
{
    unordered_map<char, int> occur1, occur2;

public:
    bool isAnagram(string s, string t)
    {
        vector<int> chars(26, 0);
        if (s.length() != t.length())
            return false;
        for (char c : s)
        {
            chars[c - 'a']++;
        }
        for (char c : t)
        {
            chars[c - 'a']--;
        }
        for (int i : chars)
        {
            if (i != 0)
                return false;
        }
        return true;
    }
};