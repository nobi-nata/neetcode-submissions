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
    int check(TreeNode* root, int &ans){
        if(!root) return 0;

        int left = check(root->left, ans);
        int right = check(root->right, ans);

        ans = max(ans, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> mp;
        mp[nullptr] = {0, 0};
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* node = st.top();

            if(node->left && mp.find(node->left) == mp.end()){
                st.push(node->left);
            }
            else if(node->right && mp.find(node->right) == mp.end()){
                st.push(node->right);
            }
            else{
                st.pop();

                auto [lh, ld] = mp[node->left];
                auto [rh, rd] = mp[node->right];

                int h = 1 + max(lh, rh);
                int d = max(lh+rh, max(ld, rd));

                mp[node] = {h, d};

            }
        }
        return mp[root].second;
    }
};
