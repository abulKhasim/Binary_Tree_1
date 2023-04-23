class Solution {

public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> inorder;
        TreeNode* cur = root;

        while(cur != NULL) {
            if(cur->left == NULL) {
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else {
                TreeNode* rightMostNode = cur->left;
                while(rightMostNode->right && rightMostNode->right != cur) {
                    rightMostNode = rightMostNode->right;
                }
                if(rightMostNode->right == NULL){
                    rightMostNode->right = cur;
                    cur = cur->left;
                }
                else {
                    rightMostNode->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }

        return inorder;
    }
};