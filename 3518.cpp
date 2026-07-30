class Solution {
public:
    using ll = long long;

    // Count distinct permutations from remaining frequencies
    ll countPerm(vector<int>& freq, int total) {
        long double res = 1.0;

        for (int i = 2; i <= total; i++)
            res *= i;

        for (int f : freq) {
            for (int i = 2; i <= f; i++)
                res /= i;
        }

        const ll LIMIT = (ll)1e18;
        if (res > LIMIT) return LIMIT;

        return (ll)(res + 0.5);
    }

    string kthPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string mid = "";
        vector<int> half(26, 0);
        int halfLen = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2)
                mid += char('a' + i);

            half[i] = freq[i] / 2;
            halfLen += half[i];
        }

        string left = "";

        for (int pos = 0; pos < halfLen; pos++) {

            bool found = false;

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                ll ways = countPerm(half, halfLen - pos - 1);

                if (ways >= k) {
                    left += char('a' + c);
                    found = true;
                    break;
                }

                k -= ways;
                half[c]++;
            }

            if (!found)
                return "";
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};