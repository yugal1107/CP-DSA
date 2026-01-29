#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(int n){
    vector<int> a(n);
    int ptr = n-1;

    int val = n;

    while(ptr>=0){
        a[ptr] = val;
        val--;
        ptr-=2;
    }

    ptr = n-2;
    val = 1;

    while(ptr>=0){
        a[ptr] = val;
        val++;
        ptr-=2;
    }

    for (int& i: a) cout << i << " ";
    cout << endl;

}

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        solve(n);
    }

}