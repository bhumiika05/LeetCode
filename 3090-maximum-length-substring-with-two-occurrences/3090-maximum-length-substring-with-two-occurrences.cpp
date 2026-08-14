class Solution {
public:
    int maximumLengthSubstring(string s) {
         int freq[26] = {0};
        
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {
            freq[s[right] - 'a']++;

            // If a character occurs more than 2 times
            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }

            // Calculate current substring length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};