class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> ans;
        
        int minr = 0;
        int minc = 0;
        int maxr = m-1;
        int maxc = n-1;
        int cnt = 0;
        int total = n*m;
        
        while(cnt<total){
            for(int i = minc;i<=maxc && cnt<total;i++){
                ans.push_back(matrix[minr][i]);
                cnt++;
            }
            minr++;
            for(int i = minr;i<=maxr && cnt<total;i++){
                ans.push_back(matrix[i][maxc]);
                cnt++;
            }
            maxc--;
            for(int i = maxc;i>=minc && cnt<total;i--){
                ans.push_back(matrix[maxr][i]);
                cnt++;
            }
            maxr--;
            for(int i = maxr;i>=minr && cnt<total;i--){
                ans.push_back(matrix[i][minc]);
                cnt++;
            }
            minc++;
        }
        
        return ans;
        
    }
};