Problem Link :- https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3369/

/*

Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6

*/

//Solution

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)
             return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
       /// return count;
    }
};