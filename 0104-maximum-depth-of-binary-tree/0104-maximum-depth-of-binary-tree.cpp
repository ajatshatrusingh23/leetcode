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
    void helper(TreeNode* root,int &ans,int depth){
        if(root == NULL) return;

        ans = max(ans,depth);
        helper(root->left,ans,depth+1);
        helper(root->right,ans,depth+1);
    }

    int maxDepth(TreeNode* root) {
        int ans = 0;
        helper(root,ans,1);
        return ans;
    }
};