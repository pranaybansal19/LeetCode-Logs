class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> vec(m);
        string s="";
        for(int i=0;i<n;i++) s+=".";
        vec[0]=s;
        for(int i=1;i<m;i++){
            s="";
            for(int j=0;j<n;j++){
                if(j==n-1) s+=".";
                else s+="#";
            }
            vec[i]=s;
        }
        return vec;
        
    }
};