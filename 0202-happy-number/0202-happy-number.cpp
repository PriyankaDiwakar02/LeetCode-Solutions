class Solution {
public:
    int squareSum(int n){
        int ans=0;
        while(n>0){
            ans=ans+pow((n%10),2);
            n=n/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n!=1){
            if(seen.count(n)==1){
                return false;
            }else{
                seen.insert(n);
            }
            n=squareSum(n);
        }
        return true;
    }
};