class Solution {
public:
    int compress(vector<char>& chars) {
        string ans = "";

        int i = 0;
        int n = chars.size();

        while (i < n) {

            char ch = chars[i];
            int count = 0;

            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            ans += ch;

            if (count > 1) {
                ans += to_string(count);
            }
        }

        // Copy compressed result back
        for (int i = 0; i < ans.size(); i++) {
            chars[i] = ans[i];
        }

        return ans.size();
    }
};