// problem link : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

class Solution {
private:
    int findMinTime( map<TreeNode*, TreeNode*>& parent_track, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*, bool> visited;
        visited[target] = true;
        int time = 0;

        while(!q.empty()) {
            int sz = q.size();
            int flag = 0;
            for(int i=0; i<sz; i++) {
                auto node = q.front();
                q.pop();

                if(node->left && !visited[node->left]) {
                    flag = 1;
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]) {
                    flag = 1;
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if(parent_track[node] && !visited[parent_track[node]]) {
                    flag = 1;
                    visited[parent_track[node]] = true;
                    q.push(parent_track[node]);
                }
            }
            if(flag) time++;
        }
        return time;
    }

    TreeNode* bfsToMapParent(TreeNode* root, map<TreeNode*, TreeNode*>& parent_track, int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;

        while(!q.empty()) {
            TreeNode* node = q.front();
            if(node->val == start) res = node;
            q.pop();
            if(node->left) {
                parent_track[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }

        return res;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> parent_track;
        TreeNode* target = bfsToMapParent(root, parent_track, start);
        int time = findMinTime(parent_track, target);
        return time;
    }
};