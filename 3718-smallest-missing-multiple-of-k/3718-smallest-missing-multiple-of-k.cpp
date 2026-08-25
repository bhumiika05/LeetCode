class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;

        // Store all numbers
        for (int x : nums) {
            s.insert(x);
        }

        int multiple = k;

        // Find the smallest missing multiple
        while (s.count(multiple)) {
            multiple += k;
        }

        return multiple;
    }
};