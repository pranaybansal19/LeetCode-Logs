class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> q;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') q.push('(');
            else{
                if(!q.empty()) q.pop();
                else cnt++;
            }
        }
        if(!q.empty()) cnt+=q.size();
        // for(int i)
        return cnt;
    }
};