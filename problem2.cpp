// Time Complexity : O(m*n)
// Space Complexity : O(m*n)
// Did this code successfully run on Leetcode : yes
// Any problem you faced while coding this : no


// Your code here along with comments explaining your approach
// Start by putting all 0s in the queue for BFS, and flipping all 1s to -1s to make the distinction between element 1 and distance 1
// In the while loop, process all the nodes at that level at once and update the values of the -1s to the distances
// Return the updated matrix

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m  = mat.size(); int n = mat[0].size();

        queue<pair<int, int>> q;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] *= -1;
                }
            }
        }

        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                auto[r, c] = q.front();
                q.pop();
                for(auto& dir : dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && mat[nr][nc] == -1) {
                        mat[nr][nc] = mat[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return mat;
    }
};