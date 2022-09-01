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
    void inorder(TreeNode *root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode* arrayToTree(TreeNode *root, vector<int> &ans){
        int n=ans.size();
        TreeNode *temp=NULL;
        TreeNode *res=NULL;
        for(int i=0;i<n;i++){
            if(i==0){
                res=new TreeNode(ans[i]);
                temp=res;
            } 
            else{
                temp->right=new TreeNode(ans[i]);
                temp=temp->right;
            }
        }
        return res;
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector <int> ans;
        inorder(root,ans);
        return arrayToTree(root,ans);
    }
};