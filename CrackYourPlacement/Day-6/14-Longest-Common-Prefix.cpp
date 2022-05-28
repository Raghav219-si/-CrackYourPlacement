class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string first = strs[0];
        int cnt = 0;
        
        string pre = "";
        
        for(int i = 0;i<first.length();i++){
            char ch = first[i];
            for(int j = 0;j<strs.size();j++){
                if(i<strs[j].length() && ch == strs[j][i]){
                    
                }
                else{
                    return pre;
                }
            }
            pre += ch;
        }
        
        return pre;
    }
};