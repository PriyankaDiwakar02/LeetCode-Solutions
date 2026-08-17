class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) 
    {
        int n = stoneValue.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        vector<int> psum(n+1);
        for(int i = 0 ; i < n ; i++)
        {
            psum[i+1] = psum[i] + stoneValue[i];
        }

        for(int len = 2 ; len <= n ; len++)
        {
            for(int i = 1 ; i + len -1 <= n ; i++)
            {
                int j = i + len - 1;

                for(int k = i ; k < j ; k++)
                {
                    int left = psum[k] - psum[i-1];
                    int right = psum[j] - psum[k];
                    if(left < right)
                    {
                        dp[i][j] = max(dp[i][j] , left + dp[i][k]);
                    }
                    else if(left > right)
                    {
                        dp[i][j] = max(dp[i][j] , right + dp[k+1][j]);
                    }
                    else
                    {
                        dp[i][j] = max(dp[i][j] , left + max(dp[i][k] , dp[k+1][j])); //left = right here
                    }
                }
            }
        }
        return dp[1][n];
    }
};