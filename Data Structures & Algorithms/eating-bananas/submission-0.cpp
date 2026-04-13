class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int k= r;

        while(l <=r){
            int m = (l+r)/2;
            int hours = 0;
            for(int p: piles){
                hours += p/m;
                if (p % m != 0) {
                    hours++;
                }
            }
            if(hours <=h){
                k = min(k, m);
                r = m-1;
            }else{
                l = m+1;
            }
        }

        return k;
        
    }
};
