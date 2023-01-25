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
    pair <bool,int> solve(TreeNode *root){
        if(root==NULL){
            pair<bool, int> p = make_pair(true,0);
            return p;
        }
        pair <bool, int> leftAns = solve(root->left);
        pair <bool, int> rightAns = solve(root->right);
        bool leftBool = leftAns.first;
        bool rightBool = rightAns.first;
        bool diff=abs(leftAns.second-rightAns.second)<=1;
        pair<bool,int> ans;
        ans.second = max(leftAns.second,rightAns.second)+1;
        if(leftBool && rightBool && diff){
            ans.first=true;
        }
        else{
            ans.second=false;
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        pair <bool,int> ans = solve(root);
        return ans.first;
    }
};