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

    vector<int> res;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        postOrder(root);
        return res;
    }

private:

    void postOrder(TreeNode* node){

        if(!node){
            return;
        }

        postOrder(node->left);
        postOrder(node->right);
        res.push_back(node->val);
    }
};