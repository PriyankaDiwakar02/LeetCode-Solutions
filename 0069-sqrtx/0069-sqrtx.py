class Solution:
    def mySqrt(self, x: int) -> int:
        bit_count = 0
        temp = x
        while  temp > 0:
             temp >>= 1
             bit_count += 1
        
        result = 0
        for i in range((bit_count + 1) // 2, -1, -1):
            result |= (1 << i)
            if result * result > x:
                result ^= (1 << i)
        
        return result
  