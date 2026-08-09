class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)

        # dp[i][m] = maximum stones the current player can collect
        # starting at index i with the current value of M equal to m
        dp = [[0] * (n + 1) for _ in range(n)]

        # suffix[i] = total stones from piles[i] to piles[n - 1]
        suffix = [piles[-1]] * n

        for i in range(n - 2, -1, -1):
            suffix[i] = suffix[i + 1] + piles[i]

        for i in range(n - 1, -1, -1):
            for m in range(n, 0, -1):
                # The current player can take every remaining pile
                if i + 2 * m >= n:
                    dp[i][m] = suffix[i]
                else:
                    for x in range(1, 2 * m + 1):
                        opponent = dp[i + x][max(m, x)]
                        dp[i][m] = max(
                            dp[i][m],
                            suffix[i] - opponent
                        )

        return dp[0][1]