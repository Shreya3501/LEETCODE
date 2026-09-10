class Solution {
public:
    bool ispossible(vector<int> &weights , int days, int mid){

        int dayscount = 1;
        int capacity = 0;

        for(int i = 0 ; i<weights.size(); i++){

            if(capacity + weights[i] <= mid){

                capacity += weights[i];

            }
            else{

                dayscount++;
                if(dayscount > days){

                    return false;
                }
                capacity = weights[i];
            }
        }
        return true;
    }
    
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int left = *max_element(weights.begin() , weights.end());
        int ans = -1;
        int sum = 0;

        for(int i =0; i<weights.size() ; i++){

            sum += weights[i];

        }

        int right = sum;

        while(left <= right){

            int mid = left + (right - left)/2;

            if(ispossible(weights, days, mid)){

                ans = mid;
                right = mid - 1;

            }
            else{

                left = mid + 1;

            }
        }

        return ans;
    }
};