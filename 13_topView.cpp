class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL) return ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* temp = it.first;
            int line = it.second;
            
            if(mp.find(line) == mp.end()) {
                mp[line] = temp->data;
            }
            
            if(temp->left) {
                q.push({temp->left, line-1});
            }
            
            if(temp->right) {
                q.push({temp->right, line+1});
            }
        }
        
        for(auto i : mp) {
            ans.push_back(i.second);
        }
        
        return ans;
    }

};