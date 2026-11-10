class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        dp = [float('inf')] * (n + 1) # initialization 
        dp[0] = 0 # o stair 0 cost
        for i in range(n):
            for j in range(1,4): #since j is 1,2,3
                if i + j <= n: # boundry check 
                    dp[i + j] = min(dp[i + j], dp[i] + costs[i  + j - 1] + j**2) # eq given in question
        return dp[n] # last idx has the ans 