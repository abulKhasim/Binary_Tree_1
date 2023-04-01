class Solution {
private:
    void LNR(TreeNode* root,  vector<int>& ans) {
        if(root == NULL) return;

        LNR(root->left, ans);
        ans.push_back(root->val);
        LNR(root->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        LNR(root, ans);
        return ans;
    }
};