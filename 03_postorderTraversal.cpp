class Solution {
private:
    void LRN(TreeNode* root,  vector<int>& ans) {
        if(root == NULL) return;

        LRN(root->left, ans);
        LRN(root->right, ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        LRN(root, ans);
        return ans;
    }
};