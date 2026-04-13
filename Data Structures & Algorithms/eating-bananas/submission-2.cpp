class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int k = *max_element(piles.begin(), piles.end());
        int l = 1, r = k;

        while(l<=r){

            int m = (l+r)/2;
            int time= 0;

            for(int p: piles){
                time += (p / m);

                if(p%m != 0){
                    time++;
                }
            }
            if(time > h){
                l = m+1;
            }else{
               k = min (k, m);
               r = m-1;
            }
        }

        return k;
        
    }
};
