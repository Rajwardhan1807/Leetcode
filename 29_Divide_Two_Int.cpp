class Solution {
public:
    int divide(int dd, int ds) {
        
        if(dd == INT_MIN && ds == -1) return INT_MAX;
        if(dd == INT_MIN && ds == 1) return INT_MIN;

        long long dn = abs((long long)dd);
        long long dv = abs((long long)ds);

        int ans = 0;

        while(dv <= dn){
            long long sum = dv, count = 1;

            while(sum <= dn - sum){
                sum += sum;
                count += count;
            }

            ans += count;

            dn -= sum;
        }

        if((dd < 0 && ds > 0) || (dd > 0 && ds < 0)) return -ans;

        return ans;
    }
};