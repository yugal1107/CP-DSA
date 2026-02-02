#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(vector<ll>& a, int n){

    ll result = -1;

    vector<ll> sorted = a;
    sort(sorted.begin(), sorted.end());

    ll mini = sorted[0];
    ll maxi = sorted[n-1];

    // unordered_map<ll, ll> mp;

    // for (int i=0 ; i<n ; i++){
    //     mp[a[i]]=i;
    // }

    // cout << "Started debugging " << endl;
    for (int i=0 ; i<n ; i++){
        if (sorted[i]==a[i]) continue;
        ll diff = abs(sorted[i] - a[i]);
        ll ma = min(abs(a[i] - maxi), abs(sorted[i] - maxi));
        ll mi = min(abs(a[i] - mini), abs(sorted[i] - mini));

        ll ans = max(max(diff, ma), mi);

        // ll idx = mp[sorted[i]];
        // swap(a[i], a[idx]);
        // mp[sorted[i]] = i;
        // mp[a[idx]] = idx;

        // cout << diff << " " << ma << " " << mi << " " << ans << endl; 

        // cout << ans << " ";

        if (result == -1) result = ans;
        else result = min(result, ans);
    }
    // cout << "Ended debugging " << endl;

    cout << result << endl;
}

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (ll& i: a) cin >> i;
        solve(a, n);
    }
}