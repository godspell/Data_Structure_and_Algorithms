class Solution
{
    public:
    static bool mycompare(pair<int,int> &a, pair<int,int> &b){
        return (double)a.first/a.second > (double)b.first/b.second;
    }

    double fractionalKnapsack(int W, Item arr[], int n){
        vector<pair<int, int>> bag;
        for(int i = 0; i<n; i++){
            bag.push_back({arr[i].value, arr[i].weight});
        }
        sort(bag.begin(), bag.end(), mycompare);
        double ans = 0;
        
        for(int i = 0; i<n; i++){
            while(W > 0){
                if(bag[i].second <= W){
                    W -= bag[i].second;
                    ans += bag[i].first;
                    break;
                }
                else{
                  double curr = (double)bag[i].first/(double)bag[i].second;
                  ans += (curr*W);
                  W = 0;
                }
            }
        }
        return ans;
    }     
};