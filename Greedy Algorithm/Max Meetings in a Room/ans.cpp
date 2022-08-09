class meet{
    public:
    int start, end, pos;
    meet(int x, int y, int z){
        start = x;
        end = y;
        pos = z;
    }
};

static bool mycompare(meet &a, meet &b){
    if(a.end == b.end) return a.pos < b.pos;
    return a.end < b.end;
}

class Solution{
public:
    
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<meet> arr;
        for(int i = 0; i<S.size(); i++){
            meet t(S[i], F[i], i+1);
            arr.push_back(t);
        }
        
        sort(arr.begin(), arr.end(), mycompare);
        
        vector<int> ans;
        ans.push_back(arr[0].pos);
        meet prev = arr[0];
        for(int i = 1; i<N; i++){
            if(arr[i].start <= prev.end) continue;
            else{
                ans.push_back(arr[i].pos);
                prev = arr[i];
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};