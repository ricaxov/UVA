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

int cont;
vector<int>adj[10001];
vector<bool>vis(10001);
void dfs(int v){
    vis[v]=true;
    cont++;
    for(int i : adj[v]){
        if(!vis[i]){
            dfs(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,n,m,x,a,b,y;cin>>t;
    while(t--){
        cont=0;
        cin>>n>>m>>x;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            adj[a].pb(b);
        }
        for(int i=0; i<x; i++){
            cin>>y;
            if(!vis[y]){
                dfs(y);
            }
        }
        cout<<cont<<endl;
        for(int i=0; i<10001; i++){
            adj[i].clear();
            vis[i]=false;
        }
    }
}
