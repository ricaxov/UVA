#include <bits/stdc++.h>
#define f first
#define s second
#define pi 3.14159
#define pb push_back
#define tos to_string
#define inf 2147483648
#define inf64 1000000000000000000
#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int cont;
vector<pair<int,ll>>adj[501];
vector<bool>vis(501);
void dfs(int v, ll maior){
    cont++;
    vis[v]=true;
    for(auto i : adj[v]){
        if(!vis[i.f] && i.s==maior){
            dfs(i.f,maior);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll p,maior;
    int n,e,a,b,ans; cin>>n>>e;
    while(n!=0 || e!=0){
        cont=ans=0;
        maior=-inf;
        for(int i=0; i<e; i++){
            cin>>a>>b>>p;
            a--;b--;
            adj[a].pb({b,p});
            adj[b].pb({a,p});
            maior=max(maior,p);
        }
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i,maior);
            }
            ans=max(ans,cont);
            cont=0;
        }
        cout<<ans<<endl;
        for(int i=0; i<501; i++){
            adj[i].clear();
            vis[i]=false;
        }
        cin>>n>>e;
    }
}
