class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n =  nums.size();
        vector<int> res(n - k + 1);
        deque<int> q;
        int l = 0, r = 0;

        while (r < n){

            while (!q.empty() && nums[q.back()] < nums[r]){ //keep deleting values
                                                            // from window that are not max
                q.pop_back();
            }

            q.push_back(r); //finally push index of new value 

            if (l > q.front()){ // if the value in the font of q
                                // is out of window bounds

                q.pop_front(); // delete index
            }

            if ((r+1) >= k){ //if windows size is met
                res[l] = nums[q.front()]; //update res with max value in current window
                l++;
            }
            r++;
        }
        return res;
    }
};
