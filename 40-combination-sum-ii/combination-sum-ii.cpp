class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> pair;
        findCandidate(0, target, candidates, pair, result);
        return result;
    }
    void findCandidate(int ind, int target, vector<int>& candidates, vector<int>& pair, vector<vector<int>>& result){
        if(target == 0){
            result.push_back(pair);
            return;
        }
        for(int i = ind; i < candidates.size(); i++){
            if(i > ind && candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i] > target){
                break;
            }
            pair.push_back(candidates[i]);
            findCandidate(i+1, target - candidates[i], candidates, pair, result);
            pair.pop_back();
        }
    }
};