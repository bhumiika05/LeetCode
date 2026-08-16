class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        // Count stones based on remainder modulo 3
        for (int x : stones) {
            cnt[x % 3]++;
        }

        int c0 = cnt[0];
        int c1 = cnt[1];
        int c2 = cnt[2];

        // Case 1: Even number of stones divisible by 3
        if (c0 % 2 == 0) {
            return c1 > 0 && c2 > 0;
        }

        // Case 2: Odd number of stones divisible by 3
        return abs(c1 - c2) > 2;
    }
};
