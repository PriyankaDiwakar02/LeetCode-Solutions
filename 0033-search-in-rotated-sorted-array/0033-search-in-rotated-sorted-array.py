class Solution:
    def search(self, x: List[int], target: int) -> int:
        n=len(x)
        
        def findK():
            if n==1:
                return 0
            return bisect_right(x, False, key=lambda y: y<x[0])
        
        k=findK()
        
        if target>=x[0]:
            i=bisect_left(x, target, hi=k)
            if i<n and x[i]==target:
                return i
            return -1
        else:
            i=bisect_left(x, target, lo=k)
            if i<n and x[i]==target:
                return i
            return -1