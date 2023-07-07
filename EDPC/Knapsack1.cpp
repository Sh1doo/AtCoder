#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define INF 2147483647;
using namespace std;
typedef long long ll;

int main(){
    int N,W; cin >> N >> W;
    int w[N],v[N]; rep(i,N) cin >> w[i] >> v[i];
    ll dp[N][W+1]; // dp[i][j] : i番目までの品物を重さj以下で選ぶときの最大価値

    for(int j=0;j<=W;++j){
        dp[0][j] = (j-w[0]>=0)? v[0] : 0;
    }

    for(int i=1;i<N;++i){
        for(int j=0;j<=W;++j){
            if( j - w[i] >= 0 ) { //選ぶことができる
                dp[i][j] = max( dp[i-1][j-w[i]] + v[i], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[N-1][W] << endl;

    return 0;
}