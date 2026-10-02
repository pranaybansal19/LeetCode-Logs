class Solution {
public:
// in this i think we could use the recursion, so 
    void generate(int n, int cnt_open,int cnt_close,string s, vector<string> &res){
        if(!s.empty() && s.size()==2*n-1) {
            s+=')';
            res.push_back(s);
            return;
        }

        // Case 1: take the opening bracket if the cnt<n
        if(cnt_open<n){
            generate(n,cnt_open+1,cnt_close,s+'(',res);
        }
        if(cnt_open>0 && cnt_close<cnt_open)  generate(n,cnt_open,cnt_close+1,s+')',res);

        // Case 2: if the cnt==n then we could 

    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n,0,0,"",res);
        return res;
    }
};