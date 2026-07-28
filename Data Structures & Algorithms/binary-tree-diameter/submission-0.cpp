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
   int diameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;
    }
    int depth(TreeNode* node) 
    {
        if (node == nullptr) 
        {
            return 0;
        }

        int leftDep = depth(node->left);
        int rightDep = depth(node->right);

        int pathThroughNode = leftDep + rightDep;

        if (pathThroughNode > diameter) 
        {
            diameter = pathThroughNode;
        }

        if (leftDep > rightDep) 
        {
            return leftDep + 1;
        } 
        else 
        {
            return rightDep + 1;
        }
    };
};
