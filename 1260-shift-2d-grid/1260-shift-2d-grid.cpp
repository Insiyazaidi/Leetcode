class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int i =0;
        int j = 0;
        int m = grid.size();
        int n = grid[0].size();
vector<vector<int>>newgrid(m , vector<int>(n));
for(int i = 0 ; i<m; i++){
    for(int j = 0 ; j<n ; j++){
        int idx = i*n+j ; //  index = row × columns + column  .. converting 2d into 1 d 
       int newidx = (idx + k) % (m * n); // in cse sfit krke out of bound hogya 
     //   Division tells us which row block we're in.
          // Modulo tells us how far into that row we are.

int row = newidx/n;
int col = newidx%n;
newgrid[row][col] = grid[i][j];

    }
}
return newgrid;

  
    }
};