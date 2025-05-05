class Solution {
public:
    bool isPalindrome(int x) {
        // Special cases:
        // When x < 0, it's not a palindrome
        // Also if the last digit is 0, in order to be a palindrome,
        // the first digit must also be 0 (only 0 satisfies this)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // When the length is odd, we can get rid of the middle digit by reversed/10
        // For example when the input is 12321, at the end of the loop we get x = 12, reversed = 123
        return x == reversed || x == reversed / 10;
    }
};