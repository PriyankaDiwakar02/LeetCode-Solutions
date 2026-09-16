class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(n, 1);
        vector<long long> prefixSums(n + 1, 0);

        for (int j = 0; j < n; j++) {
            prefixSums[j + 1] = (prefixSums[j] + dp[j]) % MOD;
        }

        for (int i = 0; i < k; i++) {
            dp[0] = 0;

            for (int j = 1; j < n; j++) {
                dp[j] = (dp[j - 1] + prefixSums[j]) % MOD;
            }

            prefixSums[0] = 0;

            for (int j = 0; j < n; j++) {
                prefixSums[j + 1] = (prefixSums[j] + dp[j]) % MOD;
            }
        }

        return dp[n - 1];
    }
};