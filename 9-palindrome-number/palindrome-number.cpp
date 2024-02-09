class Solution {
public:
    bool isPalindrome(int num) {
        if (num < 0) // Negative numbers cannot be palindromes
        return false;

    long long originalNum = num;
    long long reversedNum = 0;

    while (originalNum != 0) {
        int digit = originalNum % 10;
        reversedNum = reversedNum * 10 + digit;
        originalNum /= 10;
    }

    if(num == reversedNum){
        return true;
    }
    return false;
    }
};