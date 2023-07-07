#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define INF 2147483647;
using namespace std;
typedef long long ll;

int main(){
    int N,W; cin >> N >> W;
    int w[N],v[N]; rep(i,N) cin >> w[i] >> v[i];
    ll dp[N][100002];   // dp[i][j] : i番目までの品物を価値がjとなるように選ぶときの最小重さ
                        //すべての品物を選んだ時の価値の総和たかだか10^5程度

    for(int i=0;i<N;++i){
        for(int j=0;j<=100001;++j){
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;
    dp[0][v[0]] = w[0];

    for(int i=1;i<N;++i){
        dp[i][0] = 0;
        for(int j=0;j<=100001;++j){
            if( j >= v[i] ) { //選ぶことができる
                dp[i][j] = min( dp[i-1][j-v[i]] + w[i], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int ans = 100001;
    while(dp[N-1][ans] > W){
        ans--;
    }

    cout << dp[N-1][ans] << endl;

    return 0;
}