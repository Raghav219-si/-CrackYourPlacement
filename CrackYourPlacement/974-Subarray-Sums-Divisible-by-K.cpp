class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int cnt = 0, sum = 0;
        int n = nums.size();
        
        map<int, int>mp;
        for(int i = 0;i<n;i++){
            sum = sum+nums[i];
            if(sum < 0)
                mp[(k-(abs(sum)%k))%k]++;
            else
                mp[sum%k]++;
        } 
        
        for(auto i : mp){
           // cout << i.first << " " << i.second << "\n";
            int num = i.second;
            cnt += (num*(num-1))/2;
            if(i.first == 0)
                cnt+=num;
        }
        
        return cnt;
    }
    
};