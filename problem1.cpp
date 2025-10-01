// Time Complexity : O(m*n)
// Space Complexity : O(m*n)
// Did this code successfully run on Leetcode : yes
// Any problem you faced while coding this : no


// Your code here along with comments explaining your approach
// Flip the color of the start cell and start dfs from starting row & col
// Explore the 4 neighbors, for all valid neighbors, flip the color and call dfs recursively
// Return updated image grid

class Solution {
private:
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void dfs(vector<vector<int>>& image, int r, int c, int orig, int color) {
        for(auto& dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if(nr >= 0 && nr < image.size() && nc >= 0 && nc < image[0].size() && image[nr][nc] == orig) {
                image[nr][nc] = color;
                dfs(image, nr, nc, orig, color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orig = image[sr][sc];
        if(orig == color) return image;
        image[sr][sc] = color;
        dfs(image, sr, sc, orig, color);

        return image;
    }
};