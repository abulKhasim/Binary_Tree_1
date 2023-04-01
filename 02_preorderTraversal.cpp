class Solution {
private:
    void NLR(TreeNode* root,  vector<int>& ans) {
        if(root == NULL) return;

        ans.push_back(root->val);
        NLR(root->left, ans);
        NLR(root->right, ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        NLR(root, ans);
        return ans;
    }
};