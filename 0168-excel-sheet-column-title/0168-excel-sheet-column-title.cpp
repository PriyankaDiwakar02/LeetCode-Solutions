class Solution {
public:
    string convertToTitle(int columnNumber) {
        string st;
        while(columnNumber)
        {
            columnNumber--;
            st += columnNumber % 26 + 'A';
            columnNumber /= 26;
        }

        reverse(st.begin(),st.end());
        return st;
    }
};