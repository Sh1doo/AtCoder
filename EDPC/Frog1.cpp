#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
    int n;cin >> n;
    int h[n];rep(i,n) cin >> h[i];

    int dp[n]; // dp[i] : 足場iにたどり着くための最小コスト
    dp[0] = 0; //       : 足場0にたどり着くための最小コスト = 0
    dp[1] = abs(h[1] - h[0]);
    for(int i=2;i<n;++i){
        dp[i] = min(dp[i-2] + abs(h[i]-h[i-2]),dp[i-1] + abs(h[i]-h[i-1]));
    }
    cout << dp[n-1] << endl;

    return 0;
}