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
    void helper(TreeNode* root,int& depth, int count){
        if(root == NULL) return ;
        count++;
        if(root->left == NULL && root->right == NULL) 
            depth = min(depth,count);

        helper(root->left,depth,count);
        helper(root->right,depth,count);
    }

    int minDepth(TreeNode* root) {

        if (root == NULL) return 0; 
        int mindepth = INT_MAX;
        helper(root,mindepth,0);
        return mindepth;
    }
};