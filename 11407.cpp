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

int dp[10005];
int f(int x){
    if(x==0) return 0;
    if(dp[x]!=-1) return dp[x];
    int ans=inf;
    for(int i=1; i*i<=x; i++){
        ans=min(ans, 1+f(x-i*i));
    }
    return dp[x]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    int t,x; cin>>t;
    while(t--){
        cin>>x;
        cout<<f(x)<<endl;
    }
}
