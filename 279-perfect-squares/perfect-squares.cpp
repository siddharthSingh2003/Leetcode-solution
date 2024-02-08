class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; // Base case

        // Calculate the minimum number of perfect square numbers needed for each number from 1 to n
        for (int i = 1; i <= n; ++i) {
            // Try all possible perfect square numbers less than or equal to i
            for (int j = 1; j * j <= i; ++j) {
                // Update the minimum number of perfect square numbers needed for i
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};