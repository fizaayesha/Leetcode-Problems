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
    void inorder(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        unordered_map<int,int>mp;
        for(int i:ans){
            mp[i]++;
        }
        int maxi=INT_MIN;
        vector<int> res;
        for(auto x:mp){
            if(x.second>maxi){
                maxi=x.second;
            }
        }
        for(auto &i:mp){
            if(i.second==maxi){
                res.push_back(i.first);
            }
        }
        return res;
    }
};