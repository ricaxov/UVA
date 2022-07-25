#include <bits/stdc++.h>
#define f first
#define s second
#define pi 3.14159
#define mod 1000000
#define pb push_back
#define tos to_string
#define inf 1000000000
#define inf64 1000000000000000000
#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int dp[101][101];
int f(int n, int k, int x){
    if(k==x) return dp[n][k]=1;
    if(dp[n][k]!=-1) return dp[n][k];
    int cont=0;
    for(int i=0; i<=n; i++){
        cont=((cont%mod)+(f(i,k,x+1)%mod))%mod;
    }
    return dp[n][k]=cont;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,k; cin>>n>>k;
    while(n!=0 || k!=0){
        for(int i=0; i<101; i++){
            for(int j=0; j<101; j++){
                dp[i][j]=-1;
            }
        }
        cout<<f(n,k,1)<<endl;
        cin>>n>>k;
    }
}
