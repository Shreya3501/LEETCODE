class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();

        int low = 1;
        int high = *max_element(bloomDay.begin(),bloomDay.end());

        if((long long)m*k>n)
            return -1;

        while(low<high){

            int mid = low +(high - low )/2;

            int flower=0;
            int bouquet=0;

            for(int i =0; i<n ; i++){

                if(bloomDay[i]<=mid)
                    flower++;

                   else
                    flower=0;

                if(flower==k){
                    bouquet++;
                    flower=0; 
                }   
            }

            if(bouquet>= m)
                high=mid;
            
            else
                low = mid +1;
            
        }
        return low;
    }
};