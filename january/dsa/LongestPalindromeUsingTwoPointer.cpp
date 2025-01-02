// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/description/?envType=problem-list-v2&envId=two-pointers

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int start = 0, length = 1;
        for (int i = 0; i < s.size(); ++i)
        {
            // handling the odd length
            int left = i - 1, right = i + 1, x = 1, index;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                index = left;
                x += 2;
                --left, ++right;
            }

            if (length < x)
            {
                length = x;
                start = index;
            }

            // cout<<left<<" "<<right<<" == ";

            left = i;
            right = i + 1;
            x = 0;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                x += 2;
                index = left;
                --left, ++right;
            }

            // cout<<left<<" "<<right<<endl;

            if (length < x)
            {
                length = x;
                start = index;
            }
        }

        cout << length << " " << start << endl;
        return s.substr(start, length);
    }
};