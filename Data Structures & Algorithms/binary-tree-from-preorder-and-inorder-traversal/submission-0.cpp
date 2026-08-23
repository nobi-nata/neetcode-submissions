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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return nullptr;
        if(preorder.size() == 1) return new TreeNode(preorder[0]);

        TreeNode* node = new TreeNode(preorder[0]);
        int i = 0;
        for(; i < inorder.size(); i++){
            if(inorder[i] == preorder[0]) break;
        }

        vector<int> leftPre(preorder.begin()+1, preorder.begin()+1+i);
        vector<int> leftIn(inorder.begin(), inorder.begin()+i);
        vector<int> rightPre(preorder.begin()+1+i, preorder.end());
        vector<int> rightIn(inorder.begin()+i+1, inorder.end());

        node->left = buildTree(leftPre, leftIn);
        node->right = buildTree(rightPre, rightIn);
        return node;
    }
};
