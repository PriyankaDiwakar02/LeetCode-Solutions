class Solution {
public:
    int maxProfit(vector<int>& prices) {
        

        int ans = INT_MIN;
        int day = INT_MAX;

        for(int i = 0; i < prices.size(); i++){

            // pick the smallest day
            day = min(day, prices[i]);
            // after picking min day check to right, if we get the higher
            ans = max(ans, prices[i] - day);
         }
        return ans;
    }
};