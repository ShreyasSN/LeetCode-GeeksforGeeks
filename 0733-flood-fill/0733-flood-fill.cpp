class Solution {
    pair<int, int> dir[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    void solve(vector<vector<int>>& img, int i, int j, int c, int ic) {
        if (i < 0 || j < 0 || i >= img.size() || j >= img[0].size() || img[i][j] != ic) {
            return;
        }
        img[i][j] = c;   
        for (auto [di, dj] : dir) {
            int ni = i + di;
            int nj = j + dj;
            solve(img, ni, nj, c, ic);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iColor = image[sr][sc];
        if (iColor != color) { 
            solve(image, sr, sc, color, iColor);
        }
        return image;
    }
};
