// #include <bits/stdc++.h>
// using namespace std;
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
class Solution
{
public:
//     TreeNode *left;
//     TreeNode *right;
//     int data;
//     TreeNode(int data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
    string postorderStrings(TreeNode *root, vector<TreeNode *> &strArr, unordered_map<string, int> &subTrees)
    {
        if (root == NULL)
        {
            return "#";
        }
        string sLeft = postorderStrings(root->left, strArr, subTrees);
        string sRight = postorderStrings(root->right, strArr, subTrees);
        string s = sLeft + "," + sRight + "," + to_string(root->val);
        if (subTrees[s] == 1)
        {
            strArr.push_back(root);
        }
        subTrees[s]++;
        return s;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        unordered_map<string, int> subTrees;
        vector<TreeNode *> strArr;
        postorderStrings(root, strArr, subTrees);
        return strArr;
    }
};

// 4 2 1 4 2 3 4
// 2 1 1
// 3 2 2 3 2
// int main()
// {
//     // TreeNode *root = new TreeNode(2);
//     // root->left = new TreeNode(1);
//     // root->right = new TreeNode(1);
//     TreeNode *root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->right->left = new TreeNode(2);
//     root->right->right = new TreeNode(4);
//     root->right->left->left = new TreeNode(4);
//     vector<TreeNode *> strArr;
//     unordered_map<string, int> subTrees;
//     // cout << root->postorderStrings(root, strArr, subTrees);
//     return 0;
// }