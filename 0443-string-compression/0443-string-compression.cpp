class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int cnt=0;
        int i=0;
        int strt=0;

        while(i<n){
            int freq=1;

            while(i<n-1 && chars[i+1]==chars[i]){
                freq++;
                i++;
            }

            chars[strt++]=chars[i];
            if(freq!=1){
                int st=strt;
                while(freq){
                    int num=freq%10;
                    chars[strt++]=(num+'0');
                    freq=freq/10;
                }
                reverse(chars.begin()+st,chars.begin()+strt);

            }
            i++;            
        }
        for(int j=strt;j<n;j++){
            chars.pop_back();
        }
        return chars.size();
        
    }
};