class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        for (const string& word : words) {
            if (isPalindrome(word)) {
                return word;
            }
        }
        return "";
    }
    bool isPalindrome(const string& word) {
        int left = 0, right = word.length() - 1;
        while (left < right) {
            if (word[left] != word[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};