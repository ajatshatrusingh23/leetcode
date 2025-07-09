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
    void helper(string& ans,string path,TreeNode* root){
        if(root == NULL) return;

        path = char('a' + root->val) + path;


        if(root->left == NULL && root->right == NULL){
            if(ans.empty() || path<ans){
                ans= path;
            }
            return;
        }

        helper(ans,path,root->left);
        helper(ans,path,root->right);
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        helper(ans,"",root);
        return ans;
    }
};