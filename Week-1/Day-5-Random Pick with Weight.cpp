Problem Link :- https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3351/

/*

Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
Example 2:

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.

*/

//Solution

class Solution 
{
    vector<int> acm;
    int total = 0;
public:
    Solution(vector<int> w) 
    {
        for (int i : w) 
        {
            total += i;
            acm.push_back(total);
        }
    }
    
    int pickIndex() 
    {
        int r=rand()%total;
        int start=0,end=acm.size()-1;
        int ans;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(r<acm[mid])
            {
                ans=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return ans;
    }
};