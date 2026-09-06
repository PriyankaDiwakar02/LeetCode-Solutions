class Solution {
public:
    int counter(int n,vector<int>& dp){
        if(n==0 || n==1) return dp[n] = n;

        if(dp[n]!=-1) return dp[n];
        
        dp[n] = n%2 + counter(n/2,dp);

        return dp[n];     
        
    }


    vector<int> countBits(int n) {
        vector<int>dp(n+1,-1);  
        for(int i=0;i<=n;i++)    
         {counter(i,dp);}
         return dp;
    }
};