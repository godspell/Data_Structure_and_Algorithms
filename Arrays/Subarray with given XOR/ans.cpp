int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> mp;
    int ans = 0, curr_sum = 0;
    mp[0] = 1;
    for(auto x : A){
       curr_sum = curr_sum ^ x;
       if(mp.find(curr_sum ^ B) != mp.end()){
           ans += mp[curr_sum^B];
       }
       mp[curr_sum]++;
    }
    return ans;
}