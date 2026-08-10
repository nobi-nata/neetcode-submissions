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
    int isIt(TreeNode* root, bool &ans){
        if(!root) return 0;

        int left = isIt(root->left, ans);
        if(!ans) return -1;
        int right = isIt(root->right, ans);
        if(!ans) return -1;

        ans = abs(left - right) > 1 ? false : true;
        return 1 + max(left, right);
        
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        isIt(root, ans);
        return ans;
    }
};
