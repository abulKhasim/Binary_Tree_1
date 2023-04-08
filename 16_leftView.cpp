void func(Node* root, int level, vector<int>& ans) {
    if(root == NULL) return;
    
    if(ans.size() == level) ans.push_back(root->data);
    func(root->left, level+1, ans);
    func(root->right, level+1, ans);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   vector<int> ans;
   func(root, 0, ans);
   return ans;
}