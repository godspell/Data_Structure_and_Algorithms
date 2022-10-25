static bool mycompare(pair<int,int> &a, pair<int,int> &b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> meet;
        for(int i = 0; i<n; i++){
            meet.push_back({start[i], end[i]});
        }
        sort(meet.begin(), meet.end(), mycompare);
        int count = 1;
        int k = meet[0].second;
        for(int i = 1; i<n; i++){
            if(meet[i].first > k){
                count++;
                k = meet[i].second;
            }
        }
        return count;
    }