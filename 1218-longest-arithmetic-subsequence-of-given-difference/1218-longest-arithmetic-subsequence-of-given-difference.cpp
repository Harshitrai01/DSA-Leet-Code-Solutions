class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map <int, int> len;
        int mxLen = 0;
        for(int i = 0; i < arr.size(); i++){
            len[arr[i]] = len[arr[i] - difference] + 1;
            mxLen = max(mxLen, len[arr[i]]);
        }
        return mxLen;
    }
};