class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n = len(nums)

        if n == k:
            return max(nums)

        c = [0] * 51

        for i in nums:
            c[i] += 1

        if k == 1:
            for i in range(50, -1, -1):
                if c[i] == 1:
                    return i

            return -1

        res = -1

        if c[nums[0]] == 1:
            res = max(res, nums[0])

        if c[nums[-1]] == 1:
            res = max(res, nums[-1])

        return res