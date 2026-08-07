class Solution:
    def convert(self, s: str, numRows: int) -> str:
        ans = ""
        if numRows == 1:
            return s
        
        s = list(s)
        n = 2*numRows-2

        lst = [[] for _ in range(numRows)]
    
        for i in range(0, len(s), n):
    
            group = s[i:i + n]
    
            for l in range(min(numRows, len(group))):
                lst[l].append(group[l])
    
            for j in range(numRows, len(group)):
                lst[n-j].append(group[j])
    
        for m in lst:
            ans += "".join(m)
        
        return ans
    