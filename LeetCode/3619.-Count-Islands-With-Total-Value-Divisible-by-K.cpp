/*
 * LeetCode: 3619. Count Islands With Total Value Divisible by K
 * Difficulty: Medium
 * URL: https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/
 * Language: C++
 * Runtime: 35 ms | Memory: 83.9 MB
 * 
 * You are given an m x n matrix grid and a positive integer k. An island is a group of positive integers (representing land) that are 4-directionally connected (horizontally or vertically).
 * 
 * The total value of an island is the sum of the values of all cells in the island.
 * 
 * Return the number of islands with a total value divisible by k.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5
 * 
 * Output: 2
 * 
 * Explanation:
 * 
 * The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted in red do not.
 * 
 * Example 2:
 * 
 * Input: grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3
 * 
 * Output: 6
 * 
 * Explanation:
 * 
 * The grid contains six islands, each with a total value that is divisible by 3.
 * 
 *  
 * 
 * Constraints:
 * 
 * 	  - m == grid.length
 * 
 * 	  - n == grid[i].length
 * 
 * 	  - 1 <= m, n <= 1000
 * 
 * 	  - 1 <= m * n <= 10^5
 * 
 * 	  - 0 <= grid[i][j] <= 10^6
 * 
 * 	  - 1 <= k <= 10^6
 */

class Solution {
public:
    int rows, cols;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    long long dfs(int row, int col, vector<vector<int>>& grid) {
        long long sum = grid[row][col];
        grid[row][col] = 0;

        for (auto &dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (newRow >= 0 && newRow < rows &&
                newCol >= 0 && newCol < cols &&
                grid[newRow][newCol] > 0) {
                sum += dfs(newRow, newCol, grid);
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        rows = grid.size();
        cols = grid[0].size();

        int count = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] > 0) {
                    long long islandSum = dfs(row, col, grid);

                    if (islandSum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
