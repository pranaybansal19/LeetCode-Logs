class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt_5=0,cnt_10=0;

        for(int i:bills){
            if(i==5){
                cnt_5++;
            }else if(i==10){
                if(cnt_5>0){
                    cnt_5--;
                    cnt_10++;
                }else{
                    return false;
                }
            }else{
                if((cnt_5>0 && cnt_10>0)){
                    cnt_5--;
                    cnt_10--;
                    
                }else if(cnt_5>2){
                    cnt_5-=3;
                }else{
                    return false;
                }
            }
        }
        return true;
        
    }
};