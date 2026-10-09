class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = *min_element(nums.begin() , nums.end());
        int moves = 0;

        for(int a : nums){

            moves += a - min; 
        }
        return moves;
    }
};