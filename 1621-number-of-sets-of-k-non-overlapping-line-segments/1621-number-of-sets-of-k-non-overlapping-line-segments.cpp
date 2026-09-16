class Solution {
    int power(int a, int b, const int mod){
        int ans = 1;
        while(b){
            if(b & 1)ans = (ans * 1ll * a) % mod;
            a = (a * 1ll * a) % mod;
            b >>= 1;
        }
        return ans;
    }
public:
    int numberOfSets(int n, int k) {
        vector<int> f(n+1), inv(n+1);
        f[0] = f[1] = 1;
        const int mod = 1e9 + 7;
        for(int i = 2; i <= n; i++){
            f[i] = (i * 1ll * f[i - 1]) % mod;
        }
        for(int i = 0; i <= n; i++){
            inv[i] = power(f[i], mod - 2 , mod);
        }
        auto ncr = [&](int n, int r){
            if(r < 0 || r > n)return 0;
            int num = f[n];
            int den = (inv[r] * 1ll * inv[n - r]) % mod;
            int ans = (num * 1ll * den) % mod;
            return ans;
        };
        int ans = 0;
        for(int r = k + 1; r <= k<<1; r++){
            int x = r - k - 1;
            ans = (ans + (ncr(r - x - 2, x) * 1ll * ncr(n, r)) % mod) % mod;
        }
        return ans;
    }
};