class Solution {
public:
    bool dfs(vector<vector<int>> &edges, vector<int> &visited, vector<int> &st, int i){
        st[i] = 1;
        if(!visited[i]){
           visited[i] = true;
           for(auto x : edges[i]){
               if(!visited[x] && dfs(edges, visited, st, x)){
                   return true;
               }
               if(st[x] == 1) return true;
           }
        }
        st[i] = false;
        return false;
    }
    bool canFinish(int courses, vector<vector<int>>& pre) {
        vector<vector<int>> edges(courses);
        for(auto it : pre){
            edges[it[1]].push_back(it[0]);
        }
        vector<int> visited(courses, 0), st(courses, 0);
        bool cycle = false;

        for(int i = 0; i<courses; i++){
           if(!visited[i] && dfs(edges, visited, st, i)) cycle = true;
        }

        return !cycle;
    }
};