#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define INF 2147483647;
using namespace std;
typedef long long ll;

int main(){
    int n,k;cin >> n >> k;
    int h[n];rep(i,n) cin >> h[i];

    int dp[n]; // dp[i] : 足場iに到達するのに必要な最小コスト
    rep(i,n){
        dp[i] = INF;
    }

    dp[0] = 0; 

    for(int i=1;i<n;++i){
        for(int j=max(i-k,0);j<i;++j){
            dp[i] = min( dp[i] , dp[j] + abs(h[i] - h[j]) );
        }
    }

    cout << dp[n-1] << endl;
    return 0;
}