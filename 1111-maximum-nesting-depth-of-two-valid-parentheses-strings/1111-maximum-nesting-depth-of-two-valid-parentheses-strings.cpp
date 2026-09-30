class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        int cnt1=0;
        int cnt2=0;
        vector<int> arr(n);

        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                if(cnt1<cnt2){
                    cnt1++;
                    arr[i]=0;
                } 
                else{
                    cnt2++;
                    arr[i]=1;

                } 
            }
            else{
                if(cnt1>cnt2){
                    cnt1--;
                    arr[i]=0;
                }else{
                    cnt2--;
                    arr[i]=1;
                }
            }

        }
        return arr;
        
    }
};