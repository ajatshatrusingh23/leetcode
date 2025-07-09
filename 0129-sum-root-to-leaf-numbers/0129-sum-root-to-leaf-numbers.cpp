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
void helper(  TreeNode* root , long long currSum,long long& sum){
    if(root == NULL) return ;
    currSum = currSum*10+root->val ;
    if(root->left == NULL && root->right == NULL) {
        sum += currSum;
        return;
    }
    helper(root->left,currSum,sum);
    helper(root->right,currSum,sum);
}

    int sumNumbers(TreeNode* root) {
        
        long long sum = 0;
         
        helper(root,0,sum);
        return sum;
    }
};