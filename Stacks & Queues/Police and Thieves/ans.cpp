#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int catchThieves(char arr[], int n, int k)
    {
        // Code here
        queue<int> police, thief;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 'T')
            {
                thief.push(i);
            }
            else
            {
                police.push(i);
            }
        }

        while (!police.empty() && !thief.empty())
        {
            int p = police.front();
            int t = thief.front();
            if (abs(p - t) <= k)
            {
                ans++;
                police.pop();
                thief.pop();
            }
            else if (t > p)
            {
                police.pop();
            }
            else
            {
                thief.pop();
            }
        }

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        char arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.catchThieves(arr, n, k) << endl;
    }
    return 0;
}
