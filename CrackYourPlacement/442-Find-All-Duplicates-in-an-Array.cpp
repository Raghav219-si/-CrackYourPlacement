class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        for(int i = 0;i<n;i++){
            nums[(nums[i]-1)%n] = nums[(nums[i]-1)%n]+n;
        }
        
        for(int i = 0;i<n;i++){
            if(nums[i] > 2*n)
                ans.push_back(i+1);
        }
        
        return ans;
    }
};