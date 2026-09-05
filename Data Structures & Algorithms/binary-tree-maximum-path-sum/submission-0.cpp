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
            int resMax = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        

        maxPath(root);
        return resMax;
    }
private:

    int maxPath(TreeNode* node){

        if(!node){
            return 0;
        }

        int leftMax = max(maxPath(node->left), 0);
        int rightMax = max(maxPath(node->right), 0);

        resMax = max(resMax, node->val + leftMax + rightMax);
        return node->val + max(leftMax, rightMax);
    }
};
