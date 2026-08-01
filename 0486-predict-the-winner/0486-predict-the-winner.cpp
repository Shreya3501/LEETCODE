class Solution {
public:

    int guess(int i , int j , vector<int>& nums , vector<vector<int>>& dp){

        if(i == j)
            return nums[i];

        if(dp[i][j] != -1)
            return dp[i][j];

        int takeL = nums[i] - guess(i + 1 , j , nums , dp);
        int takeR = nums[j] - guess(i , j - 1 , nums , dp);

        return dp[i][j] = max(takeL , takeR);
        
    }
    bool predictTheWinner(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(n , vector<int>(n , -1));

        return guess(0 , n - 1 , nums , dp) >= 0;
        
    }
};