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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        else if(p==NULL || q==NULL){
            return false;
        }
        else{
            bool cond1 = p->val==q->val;
            bool cond2 = isSameTree(p->left,q->left);
            bool cond3 = isSameTree(p->right,q->right);
            if(cond1 && cond2 && cond3){
                return true;
            }
            return false;
        }
    }
};