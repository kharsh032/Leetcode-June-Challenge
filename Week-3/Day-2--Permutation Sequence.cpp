Problem Link :-https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3366/

/*

The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"

*/



//Solution

class Solution {
public:
 
    string getPermutation(int n, int k) {
        vector<char> num({'1','2','3','4','5','6','7','8','9'});
        vector<int> fact(n+1,1);
        ///fact[0]=1;
        for(int i=2;i<=n;i++)
            fact[i]=fact[i-1]*i;
        k--;
        string ans;
        for(int i=0;i<n;i++)
        {
            int index=k/fact[n-i-1];
            ans+=num[index];
            num.erase(num.begin()+index);
            k-=(fact[n-i-1]*index);
        }
    return ans;
    }
};