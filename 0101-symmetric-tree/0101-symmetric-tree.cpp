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

    bool sym(TreeNode* p, TreeNode* q){
        if(p == NULL || q == NULL){
            return p == q;
        }

        bool leftside = sym(p->left, q->right);
        bool rightside = sym(p->right, q->left);

        return leftside && rightside && p->val == q->val;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return sym(root->left, root->right);
    }
};