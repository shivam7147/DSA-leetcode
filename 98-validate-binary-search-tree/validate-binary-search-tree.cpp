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
    bool check(TreeNode* root ,long long int maxi , long int mini)
    {
        if( (root->val < maxi) && (root->val >mini) )
        {   bool r =true , l = true;
            if(root->right)
            {
                r = check(root->right , maxi , root->val);
            }

            if(root->left)
            {
                l = check(root->left , root->val , mini);
            }

            return r && l;
        }
        else return false;

        return false;
    }

    bool isValidBST(TreeNode* root) {
        int maxi = INT_MAX;
        int mini = INT_MIN;

       return check(root, LLONG_MAX, LLONG_MIN);
    }
};