class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Start from the last digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // If digit is 9, make it 0 and carry forward
            digits[i] = 0;
        }

        // If all digits were 9, add a leading 1
        digits.insert(digits.begin(), 1);

        return digits;
    }
};