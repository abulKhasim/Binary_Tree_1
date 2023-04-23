class Solution {
private:
    void morrisTraversal(TreeNode* &root) {
        TreeNode* cur = root;

        while(cur != NULL) {
            if(cur->left != NULL) {
                TreeNode* prev = cur->left;
                while(prev->right) {
                    prev = prev->right;
                }
                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
public:
    void flatten(TreeNode* root) {
        morrisTraversal(root);
    }
};