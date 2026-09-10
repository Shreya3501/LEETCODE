class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int mid) {

    int dayCount = 1;
    int weightSum = 0;

    for(int i = 0; i < weights.size(); i++) {

        if(weightSum + weights[i] <= mid) {

            weightSum += weights[i];

        }
        else {

            dayCount++;

            if(dayCount > days) {
                return false;
            }

            weightSum = weights[i];
        }
    }

    return true;
}
    int shipWithinDays(vector<int>& weights, int days) {

    int left = *max_element(weights.begin(), weights.end());

    int right = 0;
    for(int x : weights) {
        right += x;
    }

    int ans = -1;

    while(left <= right) {

        int mid = left + (right - left) / 2;

        if(isPossible(weights, days, mid)) {

            ans = mid;
            right = mid - 1;

        }
        else {

            left = mid + 1;
        }
    }

    return ans;
}};