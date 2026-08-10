class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         vector<int> last(256, -1);
        
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            // If character was already seen inside the current window
            if (last[s[right]] >= left) {
                left = last[s[right]] + 1;
            }

            // Update last position of the character
            last[s[right]] = right;

            // Calculate current window length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};