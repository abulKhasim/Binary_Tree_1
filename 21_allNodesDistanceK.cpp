class Solution {
private:
    void markParent(TreeNode* root, TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parent_track){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if(current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParent(root, target, parent_track);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int distance = 0;

        while(!q.empty()) {
            int size = q.size();
            if(distance++ == k) break;

            for(int i=0; i<size; i++) {
                TreeNode* current = q.front(); q.pop();
                if(current->left && !visited[current->left]) {
                    visited[current->left] = true;
                    q.push(current->left);
                }
                if(current->right && !visited[current->right]) {
                    visited[current->right] = true;
                    q.push(current->right);
                }
                if(parent_track[current] && !visited[parent_track[current]]) {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            TreeNode* current = q.front(); q.pop();
            ans.push_back(current->val);
        }

        return ans;
    }
};