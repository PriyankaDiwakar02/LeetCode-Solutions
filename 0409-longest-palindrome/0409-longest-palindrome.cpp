class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        int ans = 0;
        bool hasOdd = false;

        // Step 1: Count the frequency of each character
        for (int i = 0; i < n; i++) {
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (s[i] == s[j]) {
                    count++;
                }
            }

            // Step 2: Process each character only once
            bool alreadyProcessed = false;

            for (int j = 0; j < i; j++) {
                if (s[i] == s[j]) {
                    alreadyProcessed = true;
                    break;
                }
            }

            if (alreadyProcessed) continue;

            // Step 3: Add pairs to the answer
            if (count % 2 == 0) {
                ans += count;
            }
            else {
                ans += count - 1;
                hasOdd = true;
            }
        }

        // Step 4: Add one middle character if available
        if (hasOdd) {
            ans++;
        }

        return ans;
    }
};