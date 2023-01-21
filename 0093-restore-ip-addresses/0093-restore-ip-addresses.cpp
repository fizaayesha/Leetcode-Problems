class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int temp=256;
        int n=s.length();
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    for(int l=1;l<=3;l++){
                        if(i+j+k+l==n){
                            string s1 = to_string(stoi(s.substr(0,i)));
                            string s2 = to_string(stoi(s.substr(i,j)));
                            string s3 = to_string(stoi(s.substr(i+j,k)));
                            string s4 = to_string(stoi(s.substr(i+j+k,l)));
                            if(stoi(s1)<temp&&stoi(s2)<temp&&stoi(s3)<temp&&stoi(s4)<temp){
                                string d=s1+"."+s2+"."+s3+"."+s4;
                                if(d.length()==n+3){
                                    ans.push_back(d);
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};