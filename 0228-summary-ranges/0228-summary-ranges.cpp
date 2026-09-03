class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int currentIndex = 0;
        if(nums.size() == 0){
            return result;
        }
        for(int i = 0; i<nums.size()-1; i++){
          if((long long)nums[i+1]- nums[i] != 1){
            if(i == currentIndex){
                result.push_back(to_string(nums[currentIndex]));
                currentIndex = i+1;
            }
            else{
               result.push_back( 
                to_string(nums[currentIndex]) +
                "->" +
                to_string(nums[i]));
                currentIndex = i+1;
            }
          }
        }
        
        if(currentIndex == nums.size()-1){
            result.push_back(to_string(nums[currentIndex]));
        }
        else{
            result.push_back( 
                to_string(nums[currentIndex]) +
                "->" +
                to_string(nums[nums.size()-1]));
        }

        return result;
    }
};