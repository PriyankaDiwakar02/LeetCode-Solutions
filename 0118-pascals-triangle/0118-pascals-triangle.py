class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = []
        for a in range(numRows):
            listy = []
            i = 0
            while a >= i:
                listy.append(comb(a,i))
                i += 1
            ans.append(listy)
        return ans