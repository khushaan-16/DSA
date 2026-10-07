class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        int rsum = 0;
        int n = cardPoints.size();
        for(int i=0; i<=k-1; i++){
            lsum = lsum + cardPoints[i];
        }
        int maxSum = lsum;
        int rightInd = n-1;

        for(int j = k-1; j>= 0; j--){
            lsum = lsum - cardPoints[j];
            rsum = rsum + cardPoints[rightInd];
            rightInd = rightInd -1;
            maxSum = max(maxSum, lsum + rsum);
        }
        return maxSum;
    }
};