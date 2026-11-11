class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long mn = min(need1, need2);
        long long mx = max(need1, need2);
        long long ans = LLONG_MAX;

        if (cost1 + cost2 < costBoth) {
            ans = 1LL*need1 * cost1 + 1LL*need2 * cost2;
        } else {

            if (cost1 < costBoth && cost2 < costBoth) {
                ans = 1LL*mn * costBoth;
                if (mn == need1) {
                    ans +=1LL* (need2 - mn) * cost2;
                } else {
                    ans += 1LL*(need1 - mn) * cost1;
                }

            } else if (cost1 > costBoth && cost2<costBoth) {
                if(mn==need1){
                    ans=1LL*mn*costBoth + 1LL*(need2-mn)*cost2;
                }else{
                    ans=1LL*need1*costBoth;
                }                
            }else if(cost2 > costBoth && cost1<costBoth){
                if(mn==need2){
                    ans=1LL*mn*costBoth + 1LL*(need1-mn)*cost1;
                }else{
                    ans=1LL*need2*costBoth;
                }
            }else{
                ans=1LL*mx*costBoth;
            }
        }
        return ans;
    }
};