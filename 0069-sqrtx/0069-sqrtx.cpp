class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
            return x;

        int L = 1;
        int R = x / 2;
        int ans = 1;

        while (L <= R) {
            int M = L + (R - L) / 2;

            if (M <= x / M) {
                ans = M;
                L = M + 1;
            } else {
                R = M - 1;
            }
        }

        return ans;
    }
};