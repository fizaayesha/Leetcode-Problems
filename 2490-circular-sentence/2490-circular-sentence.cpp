class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        int i=0;
        int n=sentence.length();
        while(sentence[i]!=' ' && i<n){
            i++;
        }
        if(sentence[0]!=sentence[n-1]) return false;
        if(sentence[i]==' ' && sentence[i-1]!=sentence[i+1]){
            return false;
        }
        return true;
    }
};