/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        int l = 0, r = n;
        int m = (l+r)/2;

        int res = guess(m);

        while(res != 0){

            if(res > 0){
                l = m;
            } else {
                r = m;
            }

            m = (l+r)/2;
            res = guess(m);
        }

        return m;
    }
};