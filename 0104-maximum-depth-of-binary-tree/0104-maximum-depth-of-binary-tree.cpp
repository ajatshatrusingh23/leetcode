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
    void helper(TreeNode* root,int& depth,int count){
        if(root == NULL) return ;
        count++;
        if(root->left == nullptr && root->right == nullptr)
            depth = max(depth,count);
        helper(root->left,depth,count);
        helper(root->right,depth,count);

       
        
    }

    int maxDepth(TreeNode* root) {
        int count = 0;
        helper(root,count,0);
        return count;
    }
};