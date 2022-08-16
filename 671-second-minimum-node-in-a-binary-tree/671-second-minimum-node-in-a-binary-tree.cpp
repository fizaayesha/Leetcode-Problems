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
    void preorder(TreeNode *root, set<int> &s){
        if(root==NULL){
            return;
        }
        s.insert(root->val);
        preorder(root->left,s);
        preorder(root->right,s);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set <int> s;
        preorder(root,s);
        if(s.size()==1){
            return -1;
        }
        else{
            auto it=s.begin();
            it++;
            return (*it);
        }
    }
};