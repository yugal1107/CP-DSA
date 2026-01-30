#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> dp;

ll mod = 1e9+7;

// Showing TLE using recursion
// ll recur(int t, int idx, vector<int>& coins){
//     int n = coins.size();

//     if (t<0 || idx == n) return 0;
//     if (t==0) return 1;

//     if (dp[t][idx]!=-1) return dp[t][idx]; 

//     ll take = recur(t-coins[idx], idx, coins);

//     ll nt = recur(t, idx+1, coins);

//     return dp[t][idx] = (take + nt)%mod;
// }

// ll solve(vector<int>& coins, int t){
//     dp.assign(t+1, vector<int>(coins.size(), -1));
//     return recur(t, 0, coins);
// }

// Using tabulation (This is also giving TLE)
ll solve(vector<int>& coins, int t){
    int n = coins.size();

    vector<vector<int>> dp(t+1, vector<int>(n, 0));

    for (int i=0 ; i<n ; i++){
        dp[0][i]=1;
    }

    for (int sum = 1 ; sum <= t ; sum++){
        for (int i = 0 ; i<n ; i++){
            dp[sum][i] = ((i-1>=0) ? dp[sum][i-1] : 0) + ((sum - coins[i]>=0) ? dp[sum - coins[i]][i] : 0);
            dp[sum][i]%=mod;
        }
    }

    return dp[t][n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // your code goes here
    int n,x;
    cin >> n >> x;

    vector<int> v(n);

    for (int& i: v) cin >> i;

    cout << solve(v, x) << endl;
}