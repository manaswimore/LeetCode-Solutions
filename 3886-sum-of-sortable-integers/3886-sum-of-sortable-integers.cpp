class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        // For each divisor k, verify that every block can be
        // cyclically rotated into its corresponding sorted block.
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;

            for (int start = 0; start < n && ok; start += k) {
                int descents = 0;
                int descentIndex = -1;

                for (int i = start; i < start + k; i++) {
                    int next = (i + 1 == start + k) ? start : i + 1;
                    if (nums[i] > nums[next]) {
                        descents++;
                        descentIndex = i;
                    }
                }

                if (descents > 1) {
                    ok = false;
                    break;
                }

                int rotationStart =
                    (descentIndex == -1)
                        ? start
                        : (descentIndex + 1);

                // Check the rotated block against the corresponding
                // section of the globally sorted array.
                for (int j = 0; j < k; j++) {
                    if (nums[start + (rotationStart - start + j) % k]
                        != sorted[start + j]) {
                        ok = false;
                        break;
                    }
                }
            }

            if (ok) ans += k;
        }

        return ans;
    }
};