#include <iostream>
#include <vector>

using namespace std;

int dropeggs(int k, int n)
{
    // first dimension means times of dropping eggs
    // second dimension means number of eggs
    // dp[i][j] means maximum floor we can check when dropping j eggs in i times
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    int m = 0;

    while(dp[m][k] < n)
    {
        m += 1;

        for(int i = 1; i <= k; i++)
            dp[m][i] = dp[m - 1][i - 1] + 1 + dp[m - 1][i];
    }

    return m;
}

int main()
{
    int k, n;
    cin >> k >> n;
    int res = dropeggs(k, n);
    cout << res << endl;
    return 0;
}