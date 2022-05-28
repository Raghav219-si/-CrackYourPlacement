class Solution {
public:
    bool isPalindrome(string s, int si, int ei){
        while(si < ei){
            if(s[si] != s[ei])
                return false;
            si++;
            ei--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n-1;
        
        while(i<j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
        }
        return true;
    }
};