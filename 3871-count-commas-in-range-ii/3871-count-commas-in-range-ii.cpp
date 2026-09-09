class Solution {
public:
    long long countCommas(long long n) {
        long long commasCount = 0;
        long long baseNumber = 999;
        long long threshold = 999;

        if (n <= 999) {
            return 0;
        }

        while (threshold < n) {
            commasCount += n - threshold;
            threshold = threshold * 1000 + baseNumber;
        }

        return commasCount;
    }
};