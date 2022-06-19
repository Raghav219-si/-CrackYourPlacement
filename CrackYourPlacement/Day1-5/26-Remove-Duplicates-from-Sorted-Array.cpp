class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        while(true){
            while(j < n && nums[i]==nums[j])
                j++;
            if(j != n){
                nums[++i] = nums[j];
            }
            else{
                break;
            }
        }
        
        return i+1;
    }
};