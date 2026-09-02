class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // count_odd == 0  →  "all even" works (keep everything)
        // count_odd >= 1  →  "all odd" works (even elems subtract any odd elem)
        // These two cases cover every possible input → always true
        return true;
    }
};