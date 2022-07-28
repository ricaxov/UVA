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
typedef unsigned long long ull;

ull dp[62];
ull f(int n, int m){
    if(n<=1) return 1;
    if(dp[n]!=-1) return dp[n];
    ull ans=1;
    for(int i=1; i<=m; i++){
        ans+=f(n-i,m);
    }
    return dp[n]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,v=1; cin>>n>>m;
    while(n<=60){
        memset(dp, -1, sizeof(dp));
        cout<<"Case "<<v++<<": "<<f(n,m)<<endl;
        cin>>n>>m;
    }
}
