class Solution {
public:
    long long smallestNumber(long long num) {
        vector<long long> vec;
        long long n=num;
        while(num){
            vec.push_back(abs(num%10));
            // cout<<vec.back()<<" ";
            num=num/10;
        }
        // cout<<endl;
        sort(vec.begin(),vec.end());
        long long sz=vec.size();
        long long ans=0;

        if(n>0){
            long long nd=-1;
            for(long long i=0;i<sz;i++){
                if(vec[i]!=0){
                    nd=i;
                    break;
                }
            }
            ans=vec[nd];
            for(long long i=0;i<sz;i++){
                if(i!=nd){
                    ans=ans*10+vec[i];
                }
            }


        }else{
            for(long long i=sz-1;i>=0;i--){
                ans=ans*10+vec[i];
            }
            // cout<<ans;
            ans=ans*(-1);
        }

        return ans;
        
    }
};