class Solution {
public:

    bool isValid(string s) {
        int balance = 0;

        for (char c : s) {

            if (c == '(') {
                balance++;
            }
            else if (c == ')') {
                balance--;

                if (balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;

        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {

            string current = q.front();
            q.pop();

            // Check current string
            if (isValid(current)) {
                ans.push_back(current);
                found = true;
            }

            // If valid strings are found at this level,
            // don't generate strings with more removals.
            if (found)
                continue;

            // Try removing each parenthesis
            for (int i = 0; i < current.length(); i++) {

                if (current[i] != '(' &&
                    current[i] != ')')
                    continue;

                string next =
                    current.substr(0, i) +
                    current.substr(i + 1);

                if (visited.find(next) == visited.end()) {

                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return ans;
    }
};