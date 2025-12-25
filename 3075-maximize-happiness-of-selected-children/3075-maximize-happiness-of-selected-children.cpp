class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
         sort(happiness.begin(), happiness.end());

    long long sum = 0;
    int reduction = 0;

    for (int i = happiness.size() - 1; i >= 0 && k > 0; i--) {
        int curr = happiness[i] - reduction;
        if (curr > 0)
            sum += curr;
        reduction++;
        k--;
    }

    return sum;
    }
};