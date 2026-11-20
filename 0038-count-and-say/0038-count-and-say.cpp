class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string s = countAndSay(n-1);
        int sz=s.size();
        string ans="";
        int i=0;
        while(i<sz){
            int cnt=1;
            while(i<sz-1 && s[i+1]==s[i]){
                i++;
                cnt++;
            }
            ans+= to_string(cnt)+s[i];
            i++;

        }
        return ans;
        
    }
};