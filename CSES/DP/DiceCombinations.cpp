#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> dp;

ll mod = 1e9+7;

// Using recursion
// ll solve(int t){
//     if (t<0) return 0;
//     if (t==0) return 1;
    
//     if (dp[t]!=-1) return dp[t];
    
//     ll ans = 0;
//     for (int i=1 ; i<=6 ; i++){
//         ans+=solve(t-i)%mod;
//     }
    
//     return dp[t] = ans%mod;
// }

//Using bottom-up DP approach
ll solve(int n){
    vector<ll> dp(n+1, 0);
    dp[0]=1;

    for (int i=0 ; i<=n ; i++){
        for (int j=1 ; j<=6 ; j++){
             if (i+j>n) continue;
             dp[i+j]+=dp[i];
             dp[i+j]=dp[i+j]%mod;
        }
    }

    return dp[n]%mod;
}

int main() {
    // your code goes here
    int t;
    cin >> t;
    
    dp.assign(t+1, -1LL);
    cout << solve(t) << endl;
}