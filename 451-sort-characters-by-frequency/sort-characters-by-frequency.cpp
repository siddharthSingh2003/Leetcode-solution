class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }
        
        // Create a vector of pairs to store characters and their frequencies
        std::vector<std::pair<char, int>> freqVec(freqMap.begin(), freqMap.end());
        
        // Sort the vector based on frequency in decreasing order
        std::sort(freqVec.begin(), freqVec.end(), [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
            return a.second > b.second; // Sort by frequency in decreasing order
        });
        
        // Build the sorted string
        std::string result;
        for (const auto& pair : freqVec) {
            result += std::string(pair.second, pair.first); // Append character 'pair.first' 'pair.second' times
        }
        
        return result;
    }
};