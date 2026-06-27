class Solution {
public:

    // Stores all possible combinations
    vector<string> ans;

    // Mapping of digits to letters
    vector<string> keypad = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    // Recursive backtracking function
    void solve(int index, string &digits, string current) {

        // Base Case:
        // If we've processed all digits,
        // current contains one complete answer.
        if(index == digits.size()) {
            ans.push_back(current);
            return;
        }

        // Current digit (example: '2')
        char digit = digits[index];

        // Convert character to integer
        // '2' -> 2
        int num = digit - '0';

        // Letters corresponding to this digit
        string letters = keypad[num];

        // Try every possible letter
        for(char ch : letters) {

            // Choose
            current.push_back(ch);

            // Explore next digit
            solve(index + 1, digits, current);

            // Undo choice (Backtrack)
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        // Edge case
        if(digits.empty())
            return {};

        solve(0, digits, "");

        return ans;
    }
};