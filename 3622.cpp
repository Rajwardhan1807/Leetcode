class Solution {
public:
    bool checkDivisibility(int n) {
        int org = n;
        int sum = 0;
        int prod = 1;

        while(n > 0){
            int dig = n % 10;

            sum += dig;
            prod *= dig;

            n /= 10;
        }

        return org % (sum + prod) == 0;
    }
};