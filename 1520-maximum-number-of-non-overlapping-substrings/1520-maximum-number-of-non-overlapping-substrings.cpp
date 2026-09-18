class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        
        // Step 1: Find first and last occurrence of each character
        vector<vector<int>> occurance(26, {n, -1});
        vector<vector<int>> intervals = {};
        for (int i = 0; i < n; i++){
            int c = s[i] - 'a';
            occurance[c][0] = min(occurance[c][0], i);
            occurance[c][1] = i;
        }
        
        // Step 2: Expand boundaries and collect valid intervals
        for (int i = 0; i < 26; i++){
            if (occurance[i][0] == n){
                continue; // Character doesn't exist in string
            }
            int left = occurance[i][0];
            int right = occurance[i][1];
            int j = left;
            bool valid = true;
            
            while (j <= right){
                int l = s[j] - 'a';
                // If an inner character starts before our left bound, it's invalid
                if (occurance[l][0] < left){
                    valid = false;
                    break;
                }
                // Expand right bound if the inner character goes further
                int last = occurance[l][1];
                if (right < last){
                    right = last;
                }
                j++;
            }
            if (valid){
                intervals.push_back({left, right});
            }
        }

        // Step 3: Greedily sort by length (Shortest first)
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            int valA = a[1] - a[0] + 1;
            int valB = b[1] - b[0] + 1;
            return valA < valB;
        });

        // Step 4: Pick intervals that don't overlap with already selected ones
        vector<vector<int>> selected_intervals = {};
        vector<string> ans = {};
        for (int i = 0; i < intervals.size(); i++){
            bool overlap = false;
            for (int j = 0; j < selected_intervals.size(); j++){
                // Check if current interval overlaps with any selected interval
                if (intervals[i][0] <= selected_intervals[j][1] && intervals[i][1] >= selected_intervals[j][0]) {
                    overlap = true;
                    break;
                }
            }
            if (!overlap){
                ans.push_back(s.substr(intervals[i][0], intervals[i][1] - intervals[i][0] + 1));
                selected_intervals.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        
        return ans;
    }
};