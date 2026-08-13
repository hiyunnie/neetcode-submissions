class Solution {
   public:
    bool dfs(int r, int c, vector<vector<char>>& board, string word, int index) {
        if (index == word.size()) {
            return true;
        }
        int m = board.size();
        int n = board[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[index]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        bool found = dfs(r, c - 1, board, word, index + 1) ||
                     dfs(r, c + 1, board, word, index + 1) ||
                     dfs(r - 1, c, board, word, index + 1) || dfs(r + 1, c, board, word, index + 1);

        // rollback
        board[r][c] = temp;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == word[0] && dfs(r, c, board, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

/**

## Clarification

- Can I reuse the same cell more than once in one path?
- Can the board contain duplicate letters?
- Is movement allowed only in four directions?

## Optimized Approach

Use DFS with backtracking.

1. Try every cell as a possible starting point.
2. If `board[r][c]` matches `word[index]`, continue searching in four directions.
3. Temporarily mark the current cell as visited so it cannot be reused in the same path.
4. After DFS returns, restore the original character.
5. If `index == word.size()`, the whole word has been matched.

## Complexity

Let the board size be `m x n` and the word length be `L`.

- Time: `O(m * n * 3^L)` approximately
- Space: `O(L)` for the recursion stack

## Edge Cases

1. Word starts from multiple possible cells
2. Same letter appears many times
3. A cell cannot be reused in the same path
4. Word is longer than the number of board cells

## Interview Explanation

I try every cell as a possible starting point.

When a cell matches the current character, I use DFS to search its four neighbors.

I temporarily mark the current cell as visited so I do not reuse the same cell in the current path.

After the recursive call returns, I restore the cell, which is the backtracking step.

The recursion depth is at most the length of the word.

## Follow-up

## Note


**/