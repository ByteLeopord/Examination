class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> pq;
        int len = arr.size();
        for(int i = 0; i < k; i++){
            pq.push(arr[i]);
        }
        for(int i = k; i < len; i++){
            pq.push(arr[i]);
            pq.pop();
        }
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
