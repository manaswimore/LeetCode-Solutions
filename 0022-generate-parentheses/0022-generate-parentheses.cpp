class Solution {
public:

    void backtrack(string current, int open, int close,
                   int n, vector<string>& ans) {

        // Base case
        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // Add opening bracket
        if (open < n) {
            backtrack(current + "(", open + 1, close, n, ans);
        }

        // Add closing bracket
        if (close < open) {
            backtrack(current + ")", open, close + 1, n, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        backtrack("", 0, 0, n, ans);

        return ans;
    }
};