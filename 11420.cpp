#include <bits/stdc++.h>
#define f first
#define s second
#define pi 3.14159
#define pb push_back
#define tos to_string
#define inf 1000000000
#define inf64 1000000000000000000
#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

ll dp[70][70][2];
ll f(int n, int s, bool t){
    if(n==0) return (s==0 ? 1 : 0);
    if(s>n) return 0;
    if(dp[n][s][t]!=-1) return dp[n][s][t];
    ll ans=0;
    ans+=f(n-1,s-t,1);
    ans+=f(n-1,s,0);
    return dp[n][s][t]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,s; cin>>n>>s;
    while(n>=0 && s>=0){
        memset(dp, -1, sizeof(dp));
        cout<<f(n,s,1)<<endl;
        cin>>n>>s;
    }
}
