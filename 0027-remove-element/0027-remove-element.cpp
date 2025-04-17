class Solution {
public:
    int removeElement(vector<int>& a, int v) {
        int k=0;
        for(int i=0; i<a.size(); i++){
            if(a[i] != v) a[k++] = a[i];
        }
        return k;
    }
};