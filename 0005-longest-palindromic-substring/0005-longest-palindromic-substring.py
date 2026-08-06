class Solution:
    def expand_from_center(self, s: str, left: int, right: int) -> int:
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return right - left - 1

    def longestPalindrome(self, s: str) -> str:
        best_start = 0
        best_length = 1
        for i in range(len(s)):
            odd_length = self.expand_from_center(s, i, i)
            even_length = self.expand_from_center(s, i, i + 1)
            longer = max(odd_length, even_length)
            if longer > best_length:
                best_length = longer
                best_start = i - (longer - 1) // 2
        return s[best_start:best_start + best_length]