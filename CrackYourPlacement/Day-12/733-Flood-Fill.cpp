class Solution {
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)
            return image;
        
        int n = image.size();
        int m = (n)?image[0].size():0;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int dirs[] = {0,1,0,-1,0};
        int ocolor = image[sr][sc];
        
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            image[p.first][p.second] = color;
            for(int i = 0;i<4;i++){
                int r = p.first+dirs[i];
                int c = p.second+dirs[i+1];
                if(r<0 || r>=n || c<0 || c>=m || image[r][c] != ocolor)
                    continue;
                q.push({r, c});
            }
        }
        
        return image;
    }
};