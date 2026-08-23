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
    int kthSmallest(TreeNode* root, int k) {
        return preorder(root, k);
    }

    int preorder(TreeNode* root, int& k){
        if(!root) return 0;

        int left = preorder(root->left, k);
        if(left) return left;
        if(k == 1) return root->val;
        k--;
        int right = preorder(root->right, k); 
        if(right) return right;
        return 0;
    }
};
