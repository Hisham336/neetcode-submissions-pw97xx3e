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

    int good = 0;

    int goodNodes(TreeNode* root) {

        int curr = INT_MIN;
        isGood(root, curr);
        return good;
    }


    void isGood(TreeNode* node, int maxVal){

        if(!node){
            return;
        }

        if(node->val >= maxVal){
            good++;
            maxVal = node->val;
        }

        isGood(node->left, maxVal);
        isGood(node->right, maxVal);
    }
};
