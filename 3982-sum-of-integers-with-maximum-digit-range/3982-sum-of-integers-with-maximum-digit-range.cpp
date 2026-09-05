class Solution {
public:
    int getRange(int num) {
        int largest = 0;
        int smallest = 9;

        while (num > 0) {
            int digit = num % 10;

            largest = max(largest, digit);
            smallest = min(smallest, digit);

            num /= 10;
        }

        return largest - smallest;
    }

    int maxDigitRange(vector<int>& nums) {
        int maxRange = -1;
        int answer = 0;

        for (int num : nums) {
            int range = getRange(num);

            if (range > maxRange) {
                maxRange = range;
                answer = num;
            }
            else if (range == maxRange) {
                answer += num;
            }
        }

        return answer;
    }
};