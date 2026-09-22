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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *Node = root;

        vector<int> inorder;

        while(true){
            if(Node != NULL){
                st.push(Node);
                Node = Node-> left;

            }
            else{
                if(st.empty() == true) break;

                Node= st.top();
                st.pop();
                inorder.push_back(Node -> val);
                Node = Node-> right;
            }
        }
        return inorder;
    }
};