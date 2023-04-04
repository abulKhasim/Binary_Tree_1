class Solution {
private:
    int maxPathDown(TreeNode* root, int& maxi) {
        if(root == NULL) return 0;

        int leftSum = max(0, maxPathDown(root->left, maxi));
        int rightSum = max(0, maxPathDown(root->right, maxi));

        maxi = max(maxi, leftSum + rightSum + root->val);
        return max(leftSum, rightSum) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
};