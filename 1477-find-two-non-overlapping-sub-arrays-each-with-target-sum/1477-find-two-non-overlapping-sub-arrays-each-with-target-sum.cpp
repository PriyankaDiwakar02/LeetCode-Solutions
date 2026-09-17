class Solution {
public:
    int minSumOfLengths(vector<int>& a, int target) {
        int n = a.size();

        vector<int> p;
        vector<int> len(n, 0);
        map<int, int> mp;

        mp[0] = -1;

        int s = 0;
        int mini = -1;
        int ans = n + 1;

        for (int i = 0; i < n; i++) {
            s += a[i];

            if (mp.count(s - target)) {
                int prev = mp[s - target];
                len[i] = i - prev;

                if (prev >= 0 && len[prev] > 0) {
                    ans = min(ans, len[i] + len[prev]);
                }

                if (mini == -1) {
                    mini = len[i];
                } else {
                    mini = min(mini, len[i]);
                }
            }

            if (mini > 0) {
                len[i] = mini;
            }

            mp[s] = i;
        }

        if (ans == n + 1) {
            return -1;
        }

        return ans;
    }
};