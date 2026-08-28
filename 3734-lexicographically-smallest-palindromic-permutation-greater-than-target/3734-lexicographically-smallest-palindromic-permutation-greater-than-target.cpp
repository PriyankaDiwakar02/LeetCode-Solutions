class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> freq(26);

        for(char ch : s) {
            freq[ch - 'a']++;
        }

        int cntOddFreq = 0;
        char odd;

        for(int i = 0; i < 26; i++) {
            if(freq[i] % 2 == 1) {
                cntOddFreq++;
                odd = char('a' + i);
            }

            freq[i] /= 2;
        }

        if(cntOddFreq > 1) {
            return "";
        }

        string ans;

        // Build left half
        for(int i = 0; i < n / 2; i++) {
            int x = target[i] - 'a';

            // Try to keep prefix equal
            if(freq[x]) {
                ans += target[i];
                freq[x]--;
                continue;
            }

            // Try the smallest character greater than target[i]
            for(int c = x + 1; c < 26; c++) {
                if(!freq[c]) {
                    continue;
                }

                ans += char('a' + c);
                freq[c]--;

                // Fill remaining left half
                for(int j = 0; j < 26; j++) {
                    ans += string(freq[j], 'a' + j);
                }

                int size = ans.size();

                // Add middle character
                if(cntOddFreq == 1) {
                    ans += odd;
                }

                // Add right half
                for(int j = size - 1; j >= 0; j--) {
                    ans += ans[j];
                }

                return ans;
            }

            // Cannot continue, so backtrack
            while(!ans.empty()) {
                int prev = ans.back() - 'a';

                ans.pop_back();
                freq[prev]++;

                int pos = ans.size();
                int y = target[pos] - 'a';

                // Try to make this position greater
                for(int c = y + 1; c < 26; c++) {
                    if(!freq[c]) {
                        continue;
                    }

                    ans += char('a' + c);
                    freq[c]--;

                    // Fill remaining left half
                    for(int j = 0; j < 26; j++) {
                        ans += string(freq[j], 'a' + j);
                    }

                    int size = ans.size();

                    if(cntOddFreq == 1) {
                        ans += odd;
                    }

                    // Mirror
                    for(int j = size - 1; j >= 0; j--) {
                        ans += ans[j];
                    }

                    return ans;
                }
            }

            return "";
        }

        // Entire left half matched
        // Check whether the palindrome is already greater than target
        string temp = ans;

        if(cntOddFreq == 1) {
            temp += odd;
        }

        for(int i = ans.size() - 1; i >= 0; i--) {
            temp += ans[i];
        }

        if(temp > target) {
            return temp;
        }

        // Otherwise, backtrack
        while(!ans.empty()) {
            int prev = ans.back() - 'a';

            ans.pop_back();
            freq[prev]++;

            int pos = ans.size();
            int y = target[pos] - 'a';

            for(int c = y + 1; c < 26; c++) {
                if(!freq[c]) {
                    continue;
                }

                ans += char('a' + c);
                freq[c]--;

                // Fill remaining left half
                for(int j = 0; j < 26; j++) {
                    ans += string(freq[j], 'a' + j);
                }

                int size = ans.size();

                if(cntOddFreq == 1) {
                    ans += odd;
                }

                // Mirror
                for(int j = size - 1; j >= 0; j--) {
                    ans += ans[j];
                }

                return ans;
            }
        }

        return "";
    }
};