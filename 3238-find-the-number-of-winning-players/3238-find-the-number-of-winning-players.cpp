class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>>arr(n,vector<int>(11,0));
        int ans=0;
        for(int i=0;i<pick.size();i++){
            int player=pick[i][0];
            int color=pick[i][1];
            arr[player][color]++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=10;j++){
                if(arr[i][j] >i){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};