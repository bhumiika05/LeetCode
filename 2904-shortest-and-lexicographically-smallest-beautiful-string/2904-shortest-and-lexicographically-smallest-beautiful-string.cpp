class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        int minLen = 101;

        // Check every substring
        for (int i = 0; i < n; i++) {
            int ones = 0;

            for (int j = i; j < n; j++) {
                if (s[j] == '1')
                    ones++;

                if (ones == k) {
                    string sub = s.substr(i, j - i + 1);

                    if (sub.length() < minLen) {
                        minLen = sub.length();
                        ans = sub;
                    }
                    else if (sub.length() == minLen && sub < ans) {
                        ans = sub;
                    }
                }

                // No need to continue if ones exceed k
                if (ones > k)
                    break;
            }
        }

        return ans; 
    }
};