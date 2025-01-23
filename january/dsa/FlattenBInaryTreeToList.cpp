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
//  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/?envType=problem-list-v2&envId=depth-first-search

class Solution
{
public:
    TreeNode *doit(TreeNode *root)
    {
        if (!root)
            return NULL;
        TreeNode *left = root->left, *right = root->right;
        TreeNode *end = root;
        if (left)
        {
            root->right = left;
            root->left = NULL;
            end = doit(left);
            end->right = right;
        }

        if (!right)
            return end;
        return doit(right);
    }
    void flatten(TreeNode *root)
    {
        doit(root);
    }
};