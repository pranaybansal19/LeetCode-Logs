class Solution {
public:
    int binary(int target, vector<int>& arr2){
        int low=0;
        int n=arr2.size();
        int high=n-1;
        int ans=n;

        while(low<=high){
            int mid=(low+high)/2;
            if(arr2[mid]>target){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;

    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr2.size();
        sort(arr2.begin(),arr2.end());
        int cnt=0;

        for(int x:arr1){
            int k=binary(x,arr2);
            bool valid = true;

            if(k!=n && abs(arr2[k]-x)<=d){
                valid=false;
            }

            if(k!=0 && abs(arr2[k-1]-x)<=d){
                valid=false;
            }

            if(valid) cnt++;
        }

        return cnt;
        
    }
};