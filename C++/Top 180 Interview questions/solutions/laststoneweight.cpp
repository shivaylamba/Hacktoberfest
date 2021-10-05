class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        priority_queue<int> pq;
        for(int i = 0 ; i< arr.size(); i++)
        {
            pq.push(arr[i]);
        }
        while(pq.size()>1)
        {
            int second = pq.top();
            pq.pop();
            int first = pq.top();
            pq.pop();
            if(first != second)
                pq.push(second-first);
        }
        if(pq.empty())
            return 0;
        else
            return pq.top();
    }
};