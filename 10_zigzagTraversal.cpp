class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        // true = LeftToRight
        // false = RightToLeft
        bool leftToRight = true;

        while(!q.empty()) {
            int siz = q.size();
            vector<int> level(siz);
        
            for(int i=0; i<siz; i++) {
                TreeNode* node = q.front();
                q.pop();
            
                int index = (leftToRight) ? i : (siz - 1 - i);

                level[index] = node->val;
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            leftToRight = !leftToRight;
            ans.push_back(level);
        }

        return ans;
    }
};