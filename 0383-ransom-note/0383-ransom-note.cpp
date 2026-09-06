class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int count[26] = {0};

        for (char ch : ransomNote) {
            count[ch - 'a']++;
        }

        for (char ch : magazine) {
            count[ch - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                return false;
            }
        }

        return true;
    }
};