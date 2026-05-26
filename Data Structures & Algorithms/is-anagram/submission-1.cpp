class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mpp;
        for(auto ch:s){
            mpp[ch]++;
        }
        for(auto ch1:t){
            if(mpp.find(ch1)!=mpp.end()){
                mpp[ch1]--;
                if(mpp[ch1]==0){
                    mpp.erase(ch1);
                }
            }
            else{
                return false;
            }
        }
        if(mpp.size()==0){
            return true;
        }
        return false;
        
    }
};
