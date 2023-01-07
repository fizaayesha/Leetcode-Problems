class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalGas=0,totalCost=0;
        for(int i=0;i<n;i++){
            totalGas+=gas[i];
            totalCost+=cost[i];
        }
        if(totalCost>totalGas){
            return -1;
        }
        int start=0;
        int remainGas=0;
        for(int i=0;i<n;i++){
            remainGas+=(gas[i]-cost[i]);
            if(remainGas<0){
                start=i+1;
                remainGas=0;
            }
        }
        return start;
    }
};