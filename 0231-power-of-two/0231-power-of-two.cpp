class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool result = false;
        long rem = 1;

        if (n == 1) {
            result = true;
        } else {
            while (n > rem) {
                rem = rem * 2;
            }

            if (rem == n) {
                result = true;
            }
        }

        return result;
    }
};