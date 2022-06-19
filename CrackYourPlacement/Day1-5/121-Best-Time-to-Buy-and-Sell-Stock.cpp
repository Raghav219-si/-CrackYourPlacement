class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mx[n];
        mx[n-1] = prices[n-1];
        for(int i = n-2;i>=0;i--){
            mx[i] = max(mx[i+1], prices[i]);
        }
        int ans = INT_MIN;
        for(int i = 0;i<n;i++){
            ans = max(mx[i]-prices[i], ans);
        }
        
        return ans;
    }
};