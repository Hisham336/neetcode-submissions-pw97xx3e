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

    int preidx = 0;
    unordered_map<int, int> indexLookup;

    TreeNode* dfs(vector<int>& preorder, int l, int r){
    
    if(l > r){
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[preidx]);
    int mid = indexLookup[preorder[preidx++]];
    root->left = dfs(preorder,l, mid-1 );
    root->right = dfs(preorder, mid+1, r);
    return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for(int i = 0; i< inorder.size(); i++){
            indexLookup[inorder[i]] = i;
        }

        return dfs(preorder, 0, inorder.size()-1);
        
    }
};
