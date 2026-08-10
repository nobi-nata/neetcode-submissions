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
        if(!root) return true;
        stack<TreeNode* > st;
        st.push(root);
        unordered_set<TreeNode*> visited;
        unordered_map<TreeNode* , int> dp;
        dp[nullptr] = 0;

        while(!st.empty()){
            auto node = st.top();
            if(node->left && visited.find(node->left) == visited.end()){
                st.push(node->left);
            }
            else if(node->right && visited.find(node->right) == visited.end()){
                st.push(node->right);
            }
            else{
                visited.insert(node);
                st.pop();
                int left = dp[node->left];
                int right = dp[node->right];
                if(abs(left - right) > 1) return false;
                dp[node] = 1 + max(left, right);
            }
        }
        return true;

    }
};
