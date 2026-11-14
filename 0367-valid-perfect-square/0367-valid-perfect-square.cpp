class Solution {
public:
    bool isPerfectSquare(long long num) {
        long long x = num;
    while (x * x > num) {
        x = (x + num / x) / 2;
    }
    return x * x == num;

    }
};