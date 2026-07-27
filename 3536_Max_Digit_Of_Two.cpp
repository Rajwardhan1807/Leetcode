class Solution {
public:
    int maxProduct(int n) {
        int fst = 0;
        int sec = 0;

        while(n>0){
            int digit = n % 10; //To get Digit number 
            n = n / 10; // To separate digit from n

            if(digit > fst){
                sec = fst;
                fst = digit;
            }

            else if(digit > sec) sec = digit;

        }
            return fst * sec;
    }
};