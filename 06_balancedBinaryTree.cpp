class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return heightOfBT(root) != -1;
    }

    int heightOfBT(TreeNode* root) {
        if(root == NULL) return 0;

        int leftHeight = heightOfBT(root->left);
        if(leftHeight == -1) return -1;
        int rightHeight = heightOfBT(root->right);
        if(rightHeight == -1) return -1;

        if(abs(leftHeight - rightHeight) > 1) return -1;
        return max(leftHeight, rightHeight) + 1;
    }
};