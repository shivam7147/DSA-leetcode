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
    int z = 0;
    int  f(TreeNode* root )
    {
        if(!root) return 0;
        int l =  f(root->left);
        // if(root->left) l++;
        int r =  f(root->right);
        // if(root->right) r++;

        z = max(z ,  abs(l+r) );
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        f(root);
        return z;
    }
};