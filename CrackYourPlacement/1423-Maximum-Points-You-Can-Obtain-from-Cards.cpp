class Solution {
public:

    int maxScore(vector<int>& nums, int k) {
        int ans = 0, sum = 0, nsum = 0;
        int n = nums.size();
        for(int i = 0;i<n-k;i++){
            sum += nums[i];
            nsum += nums[i];
        }
        ans = sum;
        
        for(int i = n-k;i<n;i++){
            sum = sum+nums[i]-nums[i-n+k];
            ans = min(ans, sum);
            nsum += nums[i];
        }
        
        return nsum-ans;
    }
};