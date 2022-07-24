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

int cuts[51], dp[51][51];
int f(int l, int r){
    if(l+1==r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    int ans=inf;
    for(int i=l+1; i<r; i++){
        int cutL=f(l,i);
        int cutR=f(i,r);
        int custo=cuts[r]-cuts[l];
        ans=min(ans, cutR+cutL+custo);
    }
    return dp[l][r]=ans;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,x; cin>>n;
    while(n!=0){
        cin>>x;
        cuts[0]=0;
        for(int i=1; i<=x; i++){
            cin>>cuts[i];
        }
        cuts[x+1]=n;
        for(int i=0; i<51; i++){
            for(int j=0; j<51; j++){
                dp[i][j]=-1;
            }
        }
        cout<<"The minimum cutting is "<<f(0,x+1)<<"."<<endl;
        cin>>n;
    }
}
