class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, ele = nums[0];
        
        for(int i = 0;i<n;i++){
            if(cnt == 0)
                ele = nums[i];
            
            if(nums[i] == ele)
                cnt++;
            else
                cnt--;
        }
        
        cnt = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == ele)
                cnt++;
        }
        
        if(cnt > n/2)
            return ele;
        return -1;
    }
};