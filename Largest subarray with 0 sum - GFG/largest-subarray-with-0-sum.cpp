//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int, int> prefix_sum;
        int sum = 0, maxlen = 0;
        
        prefix_sum[0] = -1;
        for(int i=0; i<n; i++)
        {
            sum += A[i];
            if(prefix_sum.count(sum) > 0) maxlen = max(maxlen, i-prefix_sum[sum]);
            else prefix_sum[sum] = i;
        }
        return maxlen;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends