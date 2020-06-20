Problem Link :- https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3365/

/*

Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

 

Example 1:

Input: "banana"
Output: "ana"
Example 2:

Input: "abcd"
Output: ""
 

Note:

2 <= S.length <= 10^5
S consists of lowercase English letters.

*/

//Solution (Rabin Karp algo)

class Solution {
public:
    string longestDupSubstring(string S) {
        string ans;
        int l = 1, r = S.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2, 
            i = search(S, m);
            if (i >= 0)
            {
                ans = S.substr(i, m);
                l = m + 1;
            } 
            else
            {
                r = m - 1;
            }
        }
        return ans;
    }
private:
    int search(string s, int l) {
        long h = 0, p = 1, M = 10e11;
        unordered_set<long> st;
        for (int i = 0; i < s.size(); i++)
        {
            h = (h * 26 + (s[i] - 'a')) % M;
            if (i >= l) {
                h = (h - (s[i - l] - 'a') * p % M + M) % M;
            } else {
                p = p * 26 % M;
            }
            if (i >= l - 1 && st.find(h)!=st.end()) 
            {
                return i - l + 1;
            }
            st.insert(h);
        }
        return -1;
    }
};