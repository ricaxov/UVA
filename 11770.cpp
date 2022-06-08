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
vector<int>adj[100000];
vector<bool>vis(100000);
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
    for(int i : adj[v]){
        if(!vis[i]){
            dfs2(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,n,e,a,b,x=1; cin>>t;
    while(t--){
        int cont=0;
        cin>>n>>e;
        for(int i=0; i<e; i++){
            cin>>a>>b;
            a--; b--;
            adj[a].pb(b);
        }
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs1(i);
            }
        }
        for(int i=0; i<100000; i++){
            vis[i]=false;
        }
        while(!stk.empty()){
            int u=stk.top(); stk.pop();
            if(!vis[u]){
                cont++;
                dfs2(u);
            }
        }
        for(int i=0; i<100000; i++){
            adj[i].clear();
            vis[i]=false;
        }
        cout<<"Case "<<x++<<": "<<cont<<endl;
    }
}
