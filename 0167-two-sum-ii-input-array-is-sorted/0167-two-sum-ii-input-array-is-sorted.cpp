class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size()-1;
        int sum = 0;

        while(start < end){
            sum = numbers[start] + numbers[end];

            if(sum == target){
                return {start + 1 , end + 1};
            }

            if(sum > target){
                end--;
                continue;
            }
            else{
                start++;
                continue;
            }

        }
        return{};
    }
};