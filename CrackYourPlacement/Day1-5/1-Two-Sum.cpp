class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>>nnums;
        for(int i = 0;i<nums.size();i++){
            nnums.push_back({nums[i], i});
        }
        sort(nnums.begin(), nnums.end());
        
        int i = 0, j = nums.size()-1;
        while(i < j){
            int sum = nnums[i].first+nnums[j].first;
            if(sum == target){
                return {nnums[i].second, nnums[j].second};
            }
            else if(sum > target){
                j--;
            }
            else if(sum < target){
                i++;
            }
        }
        return {};
    }
};