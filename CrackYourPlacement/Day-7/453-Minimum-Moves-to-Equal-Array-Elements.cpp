class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, mi = nums[0];
        int n = nums.size();
        
        for(int i = 0;i<n;i++){
            sum += nums[i];
            mi = min(mi, nums[i]);
        }
        
        return sum-n*mi;
    }
};