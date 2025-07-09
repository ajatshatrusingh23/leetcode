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
    void helper(TreeNode* root,vector<vector<int>>& ans,int sum,int& targetSum,vector<int>& result){
        if(root == NULL) return ;
        result.push_back(root->val);
        sum += root->val;
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                ans.push_back(result);
            }
            
        }
         
        helper(root->left,ans,sum,targetSum,result);
        helper(root->right,ans,sum,targetSum,result);
        result.pop_back();

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> result;
        helper(root,ans,0,targetSum,result);
        return ans;
    }
};