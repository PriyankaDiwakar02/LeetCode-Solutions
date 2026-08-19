class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = prices[0]
        profit = 0
        for i in prices:
            min_price = min(i,min_price)
            current_profit = i - min_price
            profit = max(current_profit,profit)
        
        return profit