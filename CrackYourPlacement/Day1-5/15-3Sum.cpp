class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        int i = 0, n = nums.size();
        while(i<n){
            int sum = -1*nums[i];
            int l = i+1, h = n-1;
            while(l < h){
                if(sum < nums[l]+nums[h]){
                    int k = h-1;
                    while(k > l && nums[h] == nums[k])
                        k--;
                    h = k;
                }
                else if(sum > nums[l]+nums[h]){
                    int k = l+1;
                    while(k < h && nums[l] == nums[k])
                        k++;
                    l = k;
                }
                else{
                    ans.push_back({nums[i], nums[l], nums[h]});
                    int k = l+1;
                    while(k < h && nums[l] == nums[k])
                        k++;
                    l = k;
                    
                    k = h-1;
                    while(k > l && nums[h] == nums[k])
                        k--;
                    h = k;
                }
            }
            
            int k = i+1;
            while(k < n && nums[k] == nums[i])
                k++;
            i = k;
        }
        
        return ans;
    }
};