class Solution {
private:
    void func(TreeNode* root, vector<string>& ans, string s) {
        s = s + to_string(root->val);
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(s);
            return;
        }
        
        if(root->left) {
            func(root->left, ans, s+"->");
        }
        if(root->right) {
            func(root->right, ans, s+"->");
        }
        // s.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = "";
        func(root, ans, s);
        return ans;
    }
};