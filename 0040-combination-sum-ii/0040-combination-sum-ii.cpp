class Solution {
public:
    vector<vector<int>> ans;
    

    void sol(vector<int>& temp, vector<int>& nums, int tar, int idx) {
        if (tar == 0) {
                ans.push_back(temp);
            
            return;
        }

    
        for(int i = idx; i<nums.size(); i++){
            if(i>idx && nums[i] == nums[i-1]) continue;
            if(nums[i] > tar) break;

            temp.push_back(nums[i]);
            sol(temp, nums, tar-nums[i], i+1);
            temp.pop_back();

        }
        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        
        sol(temp, candidates, target, 0);
        return ans;
    }
};