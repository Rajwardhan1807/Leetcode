class Solution {
public:
    int smallestNumber(int n, int t) {
        while(1){
            int prod = 1;
            // Find digit and multiply 

            int copy = n;

            while(copy != 0){
                int rightMostDig = copy % 10;
                prod = prod * rightMostDig;
                copy = copy / 10;
            }

            if(prod % t == 0) return n;
            n++;
        }
        return 1;
    }
};