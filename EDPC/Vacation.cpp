#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define INF 2147483647;
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    int a[n],b[n],c[n]; rep(i,n) cin >> a[i] >> b[i] >> c[i];

    int dp[n][3]; // dp[i][j] : i日目に活動jをした時の幸福度の最大値

    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];

    for(int i=1;i<n;++i){
        dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]);
    }

    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;

    return 0;
}