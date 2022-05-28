class Solution {
public:
    int strStr(string s, string pat) {
        
        int n = s.length();
        int m = pat.length();
        
        int lps[m];
        lps[0] = 0;
        int i = 1, j = 0;
        
        while(i<m){
            if(pat[i] == pat[j]){
                lps[i] = j+1;
                j++;
                i++;
            }
            else{
                if(j != 0)
                    j = lps[j-1];
                else{
                    lps[i] = 0;
                    i++;  
                }
            }
        }
        
        i = 0, j = 0;
        while(i<n){
            if(pat[j] == s[i]){
                i++;
                j++;
            }
            
            if(j == m)
                return i-j;
            else if(i < n && pat[j] != s[i]){
                if(j != 0)
                    j = lps[j-1];
                else{
                    i++;
                }
            }
        }
        
        return -1;
    }
};