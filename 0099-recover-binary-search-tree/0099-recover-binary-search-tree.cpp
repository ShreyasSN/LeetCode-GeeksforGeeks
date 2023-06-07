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
    private:
    void traverse(TreeNode* root,TreeNode*& prev, TreeNode*& first, TreeNode*& end)
    {
        if(!root) return;
        traverse(root->left, prev, first, end);

        if(prev)
        {
            if(root->val < prev->val)
            {
                if(!first)
                    first = prev;
                end = root;
            }
            
        }
        prev = root;
        traverse(root->right, prev, first, end);
        
    }
public:
    void recoverTree(TreeNode* root) {
            TreeNode* prev = nullptr, *first = nullptr, * end = nullptr;
            traverse(root, prev, first, end);
            swap(first->val, end->val);
    }
};