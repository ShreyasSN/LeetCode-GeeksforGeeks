class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> a;
        get(root, a);
        for(int i=0, j=(int)a.size()-1; i<j;){
            if(a[i] + a[j] == k) return true;
            a[i]+a[j] < k ? i++ : j--; 
        }
        return false;
    }

    void get(TreeNode* r, vector<int>& a){
        if(!root) return;
        get(r->left, a);
        a.push_back(r->val);
        get(r->right, a);
    }
};