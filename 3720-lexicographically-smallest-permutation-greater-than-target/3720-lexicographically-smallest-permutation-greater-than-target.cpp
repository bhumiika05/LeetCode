class Solution {
public:
    string ans;
    vector<int> cnt;
    string target;
    int n;

    bool dfs(int pos) {
        if (pos == n)
            return false;

        int start = target[pos] - 'a';

        for (int c = start; c < 26; c++) {
            if (cnt[c] == 0) continue;

            cnt[c]--;
            ans.push_back(char('a' + c));

            if (c > start) {
                // Fill remaining with smallest letters
                for (int k = 0; k < 26; k++) {
                    while (cnt[k] > 0) {
                        ans.push_back(char('a' + k));
                        cnt[k]--;
                    }
                }
                return true;
            }

            if (dfs(pos + 1))
                return true;

            ans.pop_back();
            cnt[c]++;
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        this->target = target;
        n = s.size();

        cnt.assign(26, 0);
        for (char ch : s)
            cnt[ch - 'a']++;

        ans.clear();

        return dfs(0) ? ans : "";
    }
};