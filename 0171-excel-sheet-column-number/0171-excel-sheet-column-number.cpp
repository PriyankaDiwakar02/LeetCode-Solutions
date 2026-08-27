class Solution {
public:
    int titleToNumber(string col) {
        int n = col.size();
        int ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            ans += (col[i] - 'A' + 1) * pow(26, n - i - 1);
        }
        return ans;
    }
};