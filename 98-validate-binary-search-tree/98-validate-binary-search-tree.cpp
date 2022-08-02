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
    bool isBST(TreeNode *root, long min, long max){
        if(root==NULL){
            return true;
        }
        else if(root->val>min && root->val<max){
            bool leftSide = isBST(root->left,min,root->val);
            bool rightSide = isBST(root->right,root->val,max);
            return leftSide && rightSide;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root,LONG_MIN,LONG_MAX);
    }
};