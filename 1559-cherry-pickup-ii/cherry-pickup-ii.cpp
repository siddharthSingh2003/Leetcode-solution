class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Initialize DP array
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, INT_MIN)));
        
        // Iterate through rows
        for (int row = rows - 1; row >= 0; row--) {
            // Iterate through positions of both robots
            for (int col1 = 0; col1 < cols; col1++) {
                for (int col2 = 0; col2 < cols; col2++) {
                    // Calculate cherries collected by both robots at the current position
                    int cherries = grid[row][col1];
                    if (col1 != col2) cherries += grid[row][col2];
                    
                    // If not in the last row, consider all possible movements from the previous row
                    if (row != rows - 1) {
                        int maxCherries = 0;
                        for (int newCol1 = col1 - 1; newCol1 <= col1 + 1; newCol1++) {
                            for (int newCol2 = col2 - 1; newCol2 <= col2 + 1; newCol2++) {
                                if (newCol1 >= 0 && newCol1 < cols && newCol2 >= 0 && newCol2 < cols) {
                                    maxCherries = max(maxCherries, dp[row + 1][newCol1][newCol2]);
                                }
                            }
                        }
                        cherries += maxCherries;
                    }
                    
                    // Update DP array
                    dp[row][col1][col2] = cherries;
                }
            }
        }
        
        // Return maximum cherries collected for the initial positions of both robots
        return max(0, dp[0][0][cols - 1]);
    }
};