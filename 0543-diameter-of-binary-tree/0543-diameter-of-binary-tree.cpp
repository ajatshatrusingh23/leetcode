/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root,int &sum){
        if(root == NULL) return 0;
        int  left = helper(root->left,sum);
        int  right = helper(root->right,sum);

        sum = max(sum,left+right);

        return max(left,right)+1;
        
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int sum = 0;
        helper(root,sum);

        return sum; 
    }
};