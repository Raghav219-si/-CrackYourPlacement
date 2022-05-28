class Solution {
public:
    
    void helper(string s, int open, int close, vector<string>&ans){
        if(open == close && open == 0){
            ans.push_back(s);
        }
        
        if(open != 0)
            helper(s+'(', open-1, close, ans);
        if(open < close && close != 0)
            helper(s+')', open, close-1, ans);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper("", n, n, ans);
        return ans;
    }
};