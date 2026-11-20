class Solution {
public:
    string compressedString(string word) {
        string ans="";

        int n=word.size();

        int i=0;
        while(i<n){
            int cnt=1;
            while(i<n-1 && word[i+1]==word[i] && cnt<9){
                cnt++;
                i++;
            }
            ans+=to_string(cnt)+word[i];
            i++;
        }
        return ans;
        
    }
};