class Solution {
   public:
    void dfs(int r, int c, vector<vector<bool>>& visited, int prevHeight,
             vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || heights[r][c] < prevHeight) {
            return;
        }

        visited[r][c] = true;  // 標記為海水可到達

        // 四個方向擴展
        dfs(r + 1, c, visited, heights[r][c], heights);
        dfs(r - 1, c, visited, heights[r][c], heights);
        dfs(r, c + 1, visited, heights[r][c], heights);
        dfs(r, c - 1, visited, heights[r][c], heights);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // 1. 從左右兩側邊緣發動 DFS
        for (int r = 0; r < m; r++) {
            dfs(r, 0, pacific, heights[r][0], heights);           // 太平洋左邊界
            dfs(r, n - 1, atlantic, heights[r][n - 1], heights);  // 大西洋右邊界
        }

        // 2. 從上下兩側邊緣發動 DFS
        for (int c = 0; c < n; c++) {
            dfs(0, c, pacific, heights[0][c], heights);           // 太平洋上邊界
            dfs(m - 1, c, atlantic, heights[m - 1][c], heights);  // 大西洋下邊界
        }

        // 3. 找出交集（兩邊都能到達的點）
        vector<vector<int>> result;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};
// 逆向思考（海水倒灌）
// 記錄所有太平洋海水能到達的格子 vector<vector<bool>>
// 記錄所有大西洋海水能到達的格子 vector<vector<bool>>
// 找交集