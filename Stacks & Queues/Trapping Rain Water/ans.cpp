class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0; i<n; i++){
            while(!st.empty() && height[st.top()] < height[i]){
                int t = st.top();
                st.pop();
                if(st.empty()) break;
                int h = min(height[st.top()], height[i]) - height[t];
                int len = i - st.top() -1;
                ans += (len*h);
            }
            st.push(i);
        }
        return ans;
    }
};