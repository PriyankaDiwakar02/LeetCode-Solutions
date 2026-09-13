class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        /*Intuition*/

        /*
            Suppose a 1 in img1 is at (i,j) and a 1 in img2 is at (x,y)

            If we want these two 1s to overlap, we need to move img2 by :

            (i-x , j-y);

            So every pair of 1s tells us one possible translation.

            Important Observations ->
                If multiple pairs of 1s produce the same translation , all those pairs will overlap after
                that shift.
            
            So we simply count how many times each translation occurs.

            And find the maximum among them -> That will be our answer.
        */

        /*Approach*/

        /*
            1. Store the coordinates of every 1 in img1 inside pos1.
            2. Store the coordinates of every 1 in img2 inside pos2.
            3. Take every 1 from img1 and pair it with every 1 from img2.
            4. Calculate the difference between row and column.
                a = pos1[i].first - pos2[j].first;
                b = pos1[i].second - pos2[j].second;
            5. (a,b) represents one particular translation.
            6. Store the frequeny of every transaltion in the map.
            7. The translation with the maximum frequency gives the maximum overlap.
        */

        /*Code*/

        int n = img1.size();
        //{x,y}
        vector<pair<int,int>>pos1,pos2;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1) pos1.push_back({i,j});
                if(img2[i][j]==1) pos2.push_back({i,j});
            }
        }
        //{x,y} -> count
        map<pair<int,int>,int> freq;

        //answer of the no. of overlapping 1's -> Try to maximize
        int maxi = 0;
        int x = pos1.size();
        int y = pos2.size();

        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                int a = pos1[i].first - pos2[j].first;
                int b = pos1[i].second - pos2[j].second;

                freq[{a,b}]++;
                maxi = max(maxi,freq[{a,b}]);
            }
        }
        return maxi;

        /*Time Complexity*/

        /*
            O(n^2)
                +
            O(x*y*log(xy))

            == O(n*n + x*y*log(xy))
        */
    }
};