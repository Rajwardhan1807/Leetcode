class Solution {
public:
    int reverse(int x) {
        int ans = 0; // Initialize the reversed number to 0
        while (x != 0) {
            int digit = x % 10; // Get the last digit of x
            
            // Check for overflow/underflow before updating ans
           if(ans > INT_MAX/10 || (ans == INT_MAX/10 && digit > 7)) return 0;
           
           if(ans < INT_MIN/10 || (ans == INT_MIN/10 && digit < -8)) return 0;
            
            ans = ans * 10 + digit; // Append the digit to the reversed number
            x = x / 10; // Remove the last digit from x
        }
        return ans; // Return the reversed number
    }
};