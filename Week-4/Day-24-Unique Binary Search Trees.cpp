Problem Link :- https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3370/

/*

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
*/

//Solution

class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};