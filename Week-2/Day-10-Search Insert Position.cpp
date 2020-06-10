Problem Link :- https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3356/

/*

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0


*/


//Solution

class Solution {
public:
    int searchInsert(vector<int>& a, int target) {
      
     
        int start=0,end=a.size()-1,mid;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(a[mid]<target)
                start=mid+1;
            else
                end=mid-1;
        }
        return start;
    }
};