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
    int search(vector<int> &inorder, int start, int end, int curr)
    {
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}
    TreeNode *solve(int ind,vector<int> &preorder, vector<int> &inorder, int start, int end){
        if(ind>=preorder.size() || start>end){
            return NULL;
        }
        int curr=preorder[ind];
        TreeNode *root=new TreeNode(curr);
        if(start==end){
            return root;
        }
        int pos = search(inorder,start,end,curr);
        root->left=solve(ind+1,preorder,inorder,start,pos-1);
        root->right = solve(ind+pos-start+1,preorder,inorder,pos+1,end);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
       return solve(0,preorder,inorder,0,n-1);
    }
};