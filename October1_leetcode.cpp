class RecentCounter {
    private:
    std::queue<int> ans;
public:
    RecentCounter(){}
        
    int ping(int t) {
        ans.push(t);
        while (ans.front() < t-3000)
        {ans.pop();}
        return ans.size();
        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
