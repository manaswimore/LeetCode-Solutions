
class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int insertions = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                // A closing pair needs two ')'.
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } else {
                    // Insert one ')' to complete the pair.
                    insertions++;
                }

                if (open > 0) {
                    open--;
                } else {
                    // Insert '(' to match this closing pair.
                    insertions++;
                }
            }
        }

        // Each unmatched '(' needs two ')'.
        insertions += open * 2;

        return insertions;
    }
};
