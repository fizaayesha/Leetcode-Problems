class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
     int l=sentences.size();
        int ans=0;
        for(int i=0;i<l;i++){
            string temp=sentences[i];
            int count=0;
            for(int j=0;j<temp.length();j++){
                if(temp[j]==' '){
                    count++;
                }
            }
            ans=max(ans,count+1);
        }
        return ans;
    }
};