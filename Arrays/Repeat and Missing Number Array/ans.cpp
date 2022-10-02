vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    int n = A.size();
    vector<int> ans(2, -1);

    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x ^= A[i];
    }
    for (int i = 1; i <= n; i++)
    {
        x ^= i;
    }

    int a = 0, b = 0;
    int rsb = x & (-x);
    for (int i = 0; i < n; i++)
    {
        if ((rsb & A[i]) == 0)
        {
            a ^= A[i];
        }
        else
        {
            b ^= A[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if ((rsb & i) == 0)
        {
            a ^= i;
        }
        else
        {
            b ^= i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (A[i] == a)
        {
            return {a, b};
        }
        else if (A[i] == b)
        {
            return {b, a};
        }
    }

    return {-1, -1};
}
