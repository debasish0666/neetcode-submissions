class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // store frequency of each element
        unordered_map<int,int> mpp;

        for(int num : nums) {
            mpp[num]++;
        }

        // max heap
        // stores {frequency, element}
        priority_queue<pair<int,int>> pq;

        // put all frequencies into heap
        for(auto it : mpp) {

            // it.first  = element
            // it.second = frequency

            pq.push({it.second, it.first});
        }

        vector<int> ans;

        // take top k frequent elements
        while(k--) {

            // top().second gives element
            ans.push_back(pq.top().second);

            // remove current max frequency element
            pq.pop();
        }

        return ans;
    }
};