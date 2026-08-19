class Solution {
   public:
    void dfs(int r, int c, vector<vector<char>>& grid)  // 渲染
    {
        int m = grid.size();
        int n = grid[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1') return;
        grid[r][c] = '0';

        dfs(r + 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r - 1, c, grid);
        dfs(r, c - 1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int island_cnt = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == '1') {
                    island_cnt++;
                    dfs(r, c, grid);
                }
            }
        }
        return island_cnt;
    }
};
