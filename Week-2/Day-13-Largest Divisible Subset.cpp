Problem Link :- https://leetcode.com/explore/featured/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3359/

/*

Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]

*/


//Solution

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
     
        int n=nums.size();
        if(n==1||n==0)
            return nums;
        sort(nums.begin(),nums.end());
        vector<int> v(n,1);
        vector<int> arr(n,0);
        int larg=0,index=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]%nums[j]==0&&v[i]<(v[j]+1))
                {
                    v[i]=v[j]+1;
                    arr[i]=j;
                }
            }
            if(v[i]>larg)
            {
                        larg=v[i];
                        index=i;
            }
        }
        vector<int> ans;
        for(int i=0;i<larg;i++)
        {
            ans.push_back(nums[index]);
            index=arr[index];
        }
        return ans;
    }
};