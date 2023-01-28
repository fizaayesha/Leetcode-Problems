class SummaryRanges {
private:
    set<int> set_t;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        set_t.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        int start=-1;
        int end=-1;
        for(auto &x:set_t){
            if(start==-1){
                start=x;
                end=x;
            }
            else if(x==end+1){
                end=x;
            }
            else{
                res.push_back({start,end});
                start=end=x;
            }
        }
        if(start!=-1){
            res.push_back({start,end});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */