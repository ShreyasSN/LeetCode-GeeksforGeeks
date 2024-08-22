class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());
        
        long long totalCost = 0;
        int h = 0, v = 0; 
        int hSegments = 1, vSegments = 1;

        while (h < horizontalCut.size() && v < verticalCut.size()) {
            if (horizontalCut[h] >= verticalCut[v]) {
                totalCost += (long long)horizontalCut[h] * vSegments;
                hSegments++;
                h++;
            } else {
                totalCost += (long long)verticalCut[v] * hSegments;
                vSegments++;
                v++;
            }
        }
        
        while (h < horizontalCut.size()) {
            totalCost += (long long)horizontalCut[h] * vSegments;
            h++;
        }

        while (v < verticalCut.size()) {
            totalCost += (long long)verticalCut[v] * hSegments;
            v++;
        }
        
        return totalCost;
    }
};