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

    map<int, vector<pair<int,int>>>coltable;

    void inorder(TreeNode* root,int row, int col){
        if(root == NULL) return;

        inorder(root->left,row+1,col-1);

        coltable[col].push_back({row,root->val});

        inorder(root->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        inorder(root,0,0);

        vector<vector<int>>result;

        for(auto &[col,nodes]: coltable){

            sort(nodes.begin(),nodes.end());

            vector<int>temp;

            for(auto &[row,val]:nodes){

                temp.push_back(val);
            }

            result.push_back(temp);
        }

        return result;




    }
};