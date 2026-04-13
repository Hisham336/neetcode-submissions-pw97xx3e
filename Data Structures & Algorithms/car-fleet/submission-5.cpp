class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector <pair<int, int>>  pair; // position, speed
        
        for(int i = 0; i < position.size(); i++){
            pair.push_back({position[i], speed[i]}); // linking position and speed of each ccar
        }

        sort(pair.rbegin(), pair.rend()); // sorting in descending order
        vector<double> stack;
        for(auto& p : pair){ // iterating thro each car
            stack.push_back((double)(target - p.first) / p.second); // adding the time 
                                                            //taken to reach destination

            if(stack.size() >= 2 && stack.back() <= stack[stack.size() - 2])
                                                    // checking if more than 2 car fleets exist
                                                    // and checking if any more can merge 
                                                    // to a single car fleet
            {   
                stack.pop_back(); // deleting redudant car from a particular fleet
            }
        }
        return stack.size();// returning number of car fleets
    }
};
