class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        if(lh == rh) return (1<<lh) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findLeftHeight(TreeNode* root) {
        int ht = 0;
        while(root) {
            ht++;
            root = root->left;
        }
        return ht;
    }

    int findRightHeight(TreeNode* root) {
        int ht = 0;
        while(root) {
            ht++;
            root = root->right;
        }
        return ht;
    }
};