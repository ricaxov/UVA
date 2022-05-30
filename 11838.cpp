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

stack<int>stk;
vector<bool>vis(2001);
vector<int>adj[2001],adjT[2001];
void dfs1(int v){
    vis[v]=true;
    for(int i : adj[v]){
        if(!vis[i]){
            dfs1(i);
        }
    }
    stk.push(v);
}
void dfs2(int v){
    vis[v]=true;
    for(int i : adjT[v]){
        if(!vis[i]){
            dfs2(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,e,a,b,x; cin>>n>>e;
    while(n!=0 || e!=0){
        int cont=0;
        for(int i=0; i<e; i++){
            cin>>a>>b>>x;
            a--; b--;
            adj[a].pb(b);
            adjT[b].pb(a);
            if(x==2){
                adj[b].pb(a);
                adjT[a].pb(b);
            }
        }
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs1(i);
            }
        }
        for(int i=0; i<2001; i++){
            vis[i]=false;
        }
        while(!stk.empty()){
            int u=stk.top(); stk.pop();
            if(!vis[u]){
                cont++;
                dfs2(u);
            }
        }
        if(cont==1){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
        for(int i=0; i<2001; i++){
            adj[i].clear();
            adjT[i].clear();
            vis[i]=false;
        }
        cin>>n>>e;   
    }
}
