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
    int sum(TreeNode* root, int &count){
        if(root==NULL){
            return 0;
        }
        count++;
        return root->val+sum(root->left,count)+sum(root->right,count);
    }
    void avg(TreeNode *root, int &ans){
        if(root==NULL){
            return;
        }
        int count=0;
        int data=(sum(root,count)/count);
        if(root->val==data){
            ans++;
        }
        avg(root->left,ans);
        avg(root->right,ans);
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        avg(root,ans);
        return ans;
    }
};