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
vector<int>adj[50000];
vector<bool>vis(50000),marked(50000);
void dfs(int v){
    cont++;
    vis[v]=true;
    for(int i : adj[v]){
        if(!vis[i]){
            dfs(i);
        }
    }
    vis[v]=false;
    marked[v]=true;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,e,x,y,v=1,maior,ans; cin>>t;
    while(t--){
        cin>>e;
        cont=maior=0;
        for(int i=0; i<e; i++){
            cin>>x>>y;
            x--;y--;
            adj[x].pb(y);
        }
        for(int i=0; i<e; i++){
            cont=0;
            if(!marked[i]){
                dfs(i);
            }
            if(maior<cont){
                maior=cont;
                ans=i+1;
            }
        }
        cout<<"Case "<<v++<<": "<<ans<<endl;
        for(int i=0; i<50000; i++){
            adj[i].clear();
            vis[i]=false;
            marked[i]=false;
        }
    }
}
