class Solution {
private:
    bool isLeave(Node* root) {
        return !root->left && !root->right;
    }
    void addLeftBoundary(Node* root, vector<int>& ans) {
        Node* cur = root->left;
        while(cur) {
            if(!isLeave(cur)) ans.push_back(cur->data);
            if(cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }
    
    void addLeaves(Node* root, vector<int>& ans) {
        if(isLeave(root)) {
            ans.push_back(root->data);
            return;
        }
        
        if(root->left) addLeaves(root->left, ans);
        if(root->right) addLeaves(root->right, ans);
    }
    
    void addRightBoundary(Node* root, vector<int>& ans) {
        vector<int> temp;
        Node* cur = root->right;
        while(cur) {
            if(!isLeave(cur)) temp.push_back(cur->data);
            if(cur->right) cur = cur->right;
            else cur = cur->left;
        }
        
        for(int i=temp.size()-1; i>=0; i--) {
            ans.push_back(temp[i]);
        }
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(!root)  return ans;
        if(!isLeave(root)) ans.push_back(root->data);
        
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);
        
        return ans;
    }
};