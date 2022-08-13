class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> mp;
        vector<int> ans;
        for(auto it : words){
            mp[it]++;
        }
        
        int n = s.size();
        int m = words.size();
        int len = words[0].size();
        
        for(int i = 0; i<n - len*m+1; i++){
            unordered_map<string, int> temp;
            for(int j = i; j<i+len*m; j+=len){
                string str = s.substr(j, len);
                temp[str]++;
            }
            
            bool flag = true;
            for(auto it : mp){
                if(mp[it.first] != temp[it.first]){
                    flag = false;
                    break;
                }
            }
            
            if(flag){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};