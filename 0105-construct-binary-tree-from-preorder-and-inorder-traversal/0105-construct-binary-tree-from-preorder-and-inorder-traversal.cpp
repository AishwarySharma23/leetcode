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
        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);
        int n = preorder.size();
        
        int j = 0;
        for(int i = 1;i<n;i++){
            TreeNode* child = new TreeNode(preorder[i]);
            TreeNode* node = st.top();
            if(node->val != inorder[j]){
                node->left = child;
            }
            else{
                while(!st.empty() && inorder[j] == st.top()->val){
                    node = st.top();
                    st.pop();
                    j++;
                }
                node->right = child;
            }
            st.push(child);
        }
        return root;
    }
};