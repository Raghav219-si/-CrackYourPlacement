class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> >ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int i = 0;
        int j = 1;
        while(i < n){
            j = i+1;
            while(j < n){
                int sum = target-nums[i]-nums[j];
                int k = j+1;
                int l = n-1;
                while(k < l){
                    if(sum == nums[k]+nums[l]){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k-1])
                            k++;
                        while(l > k && nums[l] == nums[l+1])
                            l--;
                    }
                    else if(sum > nums[k]+nums[l])
                        k++;
                    else
                        l--;
                }
                j++;
                while(j < n && nums[j] == nums[j-1])
                    j++;
            }
            i++;
            while(i<n && nums[i] == nums[i-1])
                i++;
        }
        
        return ans;
    }
};