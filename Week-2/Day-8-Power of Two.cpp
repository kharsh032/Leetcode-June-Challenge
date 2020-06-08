Problem Link :- https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3354/

/*

Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false

*/


//Solution

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0||n==INT_MIN||n==INT_MAX)
            return false;
        return !(n&(n-1));
    }
};