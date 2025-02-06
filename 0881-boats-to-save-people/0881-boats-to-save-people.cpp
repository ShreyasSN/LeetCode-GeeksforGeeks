class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size(), res =0;
        sort(people.begin(), people.end());
        for(int i=0, j=n-1; i<=j;){
            if(people[j] >= limit){
                res++;
                j--;
            }
            else if(people[i] + people[j] <= limit){
                res++;
                j--, i++;
            } else {
                cout << i << " " << j << '\n';
                res += (i == j ? 1 : 2);
                j--, i++;
            }
        }
        return res;
    }
};