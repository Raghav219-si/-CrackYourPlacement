class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int sum = 0, ans = 0;
        map<int, int> mp;
        mp[0]++;
        
        for(int i = 0;i<n;i++){
            sum += nums[i];
            if(mp.find(sum-k) != mp.end()){
                ans += mp[sum-k];
            }
            mp[sum]++;
        }
        
        return ans;
    }
};