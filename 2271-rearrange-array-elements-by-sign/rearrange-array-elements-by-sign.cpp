class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive, negative;

        // Separate positive and negative integers
        for (int num : nums) {
            if (num > 0)
                positive.push_back(num);
            else
                negative.push_back(num);
        }

        // Sort positive and negative vectors
        // sort(positive.begin(), positive.end());
        // sort(negative.begin(), negative.end());

        vector<int> result;
        int i = 0, j = 0;

        // Alternate between positive and negative vectors while combining
        while (i < positive.size() && j < negative.size()) {
            result.push_back(positive[i++]);
            result.push_back(negative[j++]);
        }

        // Add remaining elements from the longer vector if any
        while (i < positive.size())
            result.push_back(positive[i++]);
        while (j < negative.size())
            result.push_back(negative[j++]);

        return result;
    }
};