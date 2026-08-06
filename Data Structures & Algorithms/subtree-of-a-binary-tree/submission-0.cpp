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
    bool isSame(TreeNode* first, TreeNode* second){
        if(!first && !second) return true;
        if(!first || !second) return false;

        return ((first->val == second->val) && isSame(first->left, second->left) && isSame(first->right, second->right));
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            auto node  = q.front();
            q.pop();
            if(node->val == subRoot->val && isSame(node, subRoot)) return true;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return false;
    }
};
