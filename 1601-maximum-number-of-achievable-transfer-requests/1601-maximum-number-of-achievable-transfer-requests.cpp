class Solution {
public:
    int answer = 0;
    
    void maxrequest(vector<vector<int>>& request, vector<int>& indegree, int n, int index, int count){
        if(index == request.size()){
            for (int i = 0; i < n; i++) {
                if (indegree[i]) {
                    return;
                }
            }
            answer = max(answer, count);
            return;
        }
        
        indegree[request[index][0]]--;
        indegree[request[index][1]]++;
        
        maxrequest(request, indegree, n, index+1, count+1);
        
        indegree[request[index][0]]++;
        indegree[request[index][1]]--;
        
        maxrequest(request, indegree, n, index+1, count);
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegree(n, 0);
        maxrequest(requests, indegree, n, 0, 0);
        
        return answer;
    }
};