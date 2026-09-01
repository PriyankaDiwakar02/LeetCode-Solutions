class Solution {
public:
    /*
    Intuition => 
    We need to collect all the litter in minimum no. of moves

    And for each move cost is 1, we have to indirectly find the shortest path (BFS)

    But like here is a catch

    (x,y)

    So we also need to know which litter has already been collected

    We can use bitmask (1111111111) => max

    L0 -> bit 0 => 1
    L1 -> bit 1 => 1

    mask  = 101 
    L0 and L2 are collected

    (x,y,mask) => We can reach the same state with different amounts of remaining energy

    (x,y,mask) = 2
    (x,y,mask) = 7 

    best_possible_remaining_energy [x][y][mask] => stores the maximum energy with which we have reached that state

    So the main idea is : 

    Use Bfas for the minimum moves,a bitmask to track collected litter and also u have to maintain best_possible_remaining_energy to discard states that are strictly worse.

    */

    /*Approach
    S -> starting point
    assign every litter 
    L0 -> bit 0 => 1
    L1 -> bit 1 => 1

    Then we have to create the full mask -> How many litter are collected
    t -> total no. of litter pieces
    fullmask = (1<<t)-1;

    t = 3 
    fullmask = (1<<3)= 1000-1 = 111

    Initializa BFS ->
    (startX,startY,0,energy,0);

    All 4 directions we have to consider ->

    vector<int>dx = {-1,0,1,0};
    vector<int>dy = {0,-1,0,1}; 
    (nx,ny) = (startX + dx[i] , startY + dy[i])

    New cell we came across had litter => so have to make its corresponding bit set.

    new Mask = mask | (1<<k)

    newEnergy = energy - 1;

    But if we are on an 'R' cell

    newEnergy = energy

    bestEnergy[nx][ny][newMask] (best_possible_remaining_energy) => So we have to skip that part as I said

    newMask == fullMask (return moves)

    return -1;
    */

    //According to me this is a HARD problem
    int minMoves(vector<string>& c, int energy) {
        //c = classroom
        int m = c.size();
        int n = c[0].size();

        int sx = -1 , sy = -1; //starting position 'S'
        int k = 0; // basically no. of litter

        //Assign ID to every litter cell
        vector<vector<int>> litterID(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(c[i][j]=='S'){
                    sx = i;
                    sy = j;
                }

                if(c[i][j]=='L'){
                    litterID[i][j] = k++;
                }
            }
        }

        // All k litter pieces when collected we get full mask
        int fullmask = (1<<k) - 1;

        if(fullmask == 0) return 0;

        /*
            bestEnergy[x][y][mask] = maximum energy with which we have reached
            (x,y) after collecting the mask
        */

        vector<vector<vector<int>>> bestEnergy(m,vector<vector<int>>(n,vector<int>(1<<k,-1)));

        //x,y,mask,remaining energy, steps
        queue<array<int,5>>q;

        q.push({sx,sy,0,energy,0});

        bestEnergy[sx][sy][0]=energy;

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty()){
            auto [x,y,mask,e,steps] = q.front();
            q.pop();

            for(int d=0;d<4;d++){
                int nx = x + dx[d];
                int ny = y + dy[d];

                //It should be inbounds
                if(nx < 0 || nx >= m || ny < 0 || ny >= n){
                    continue;
                }

                //Cannot enter obstacle
                if(c[nx][ny]=='X') continue;

                int newEnergy = e - 1;

                if(c[nx][ny]=='R'){
                    newEnergy = energy;
                }
                int newMask = mask;
                //Collect the litter if this cell contains one
                if(c[nx][ny] == 'L'){
                    int id = litterID[nx][ny];
                    newMask |= (1<<id);
                }

                //Whether we have collected everything or not
                if(newMask == fullmask){
                    return steps + 1;
                }

                //Energy is exhausted and we are not on a reset cell
                if(newEnergy <=0 && c[nx][ny] != 'R'){
                    continue;
                }
                

                //If we have already reached the same (position,mask) with more energy
                //this state is useless

                if(newEnergy <= bestEnergy[nx][ny][newMask]){
                    continue;
                }

                bestEnergy[nx][ny][newMask] = newEnergy;

                q.push({nx,ny,newMask,newEnergy,steps+1});
            }
        }
        return -1;
    }
};