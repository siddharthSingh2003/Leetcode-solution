class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        // Sort the input array
        std::sort(nums.begin(), nums.end());

        // dp[i] stores the size of the largest divisible subset ending at nums[i]
        std::vector<int> dp(n, 1);

        // parent[i] stores the index of the previous element in the largest divisible subset ending at nums[i]
        std::vector<int> parent(n, -1);

        int maxLen = 1, maxIndex = 0;

        // Compute dp array
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;

                    if (dp[i] > maxLen) {
                        maxLen = dp[i];
                        maxIndex = i;
                    }
                }
            }
        }

        // Reconstruct the largest divisible subset using parent array
        std::vector<int> result;
        while (maxIndex != -1) {
            result.push_back(nums[maxIndex]);
            maxIndex = parent[maxIndex];
        }

        return result;
    }
};