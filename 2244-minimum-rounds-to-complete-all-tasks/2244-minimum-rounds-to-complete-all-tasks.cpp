class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        unordered_map<int,int> mp;
        int n=tasks.size();
        for(int i=0;i<n;i++){
            mp[tasks[i]]++;
        }
        int count=0;
        for(auto itr:mp){
            if(itr.second==1){
                return -1;
            }
            count+=itr.second/3;
            if(itr.second%3!=0){
                count++;
            }
        }
        return count;
    }
};