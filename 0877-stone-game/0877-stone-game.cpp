class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& piles, int i, int j)
    {
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int takei = piles[i] + min(solve(piles, i + 2, j), solve(piles, i + 1, j - 1));
        int takej = piles[j] + min(solve(piles, i, j - 2),solve(piles, i + 1, j - 1));

        return dp[i][j] = max(takei, takej);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n, -1));
        int sum = accumulate(begin(piles), end(piles), 0);
        int alice = solve(piles, 0, n - 1);
        return alice > sum / 2;
    }
};