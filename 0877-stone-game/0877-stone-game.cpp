class Solution {
public:
    int f(vector<int>& p, int i, int j, vector<vector<int>>& dp) {
        if (i == j) return p[i];
        if (dp[i][j] != INT_MIN) return dp[i][j];
        return dp[i][j] = max(p[i] - f(p, i + 1, j, dp),
                              p[j] - f(p, i, j - 1, dp));
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        return f(piles, 0, n - 1, dp) > 0;
    }
};