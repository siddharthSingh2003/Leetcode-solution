class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();

        // Edge case: needle is an empty string, return 0
        if (n == 0) {
            return 0;
        }

        // Iterate through the haystack string
        for (int i = 0; i <= m - n; ++i) {
            // Check if substring of haystack starting from index i matches needle
            if (haystack.substr(i, n) == needle) {
                return i;  // Return the index of the first occurrence
            }
        }

        return -1;
    }
};