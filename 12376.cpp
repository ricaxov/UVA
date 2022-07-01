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

int soma,dest,last;
vector<ii>adj[100];
vector<bool>vis(100);
void dfs(int v){
    int maior=0;
    vis[v]=true;
    for(auto i : adj[v]){
        if(i.s>maior){
            maior=i.s;
            dest=i.f;
        }
    }
    soma+=maior;
    if(!vis[dest]){
        last=dest;
        dfs(dest);
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,n,e,x,y,v=1; cin>>t;
    while(t--){
        soma=0;
        string fds; getline(cin,fds);
        cin>>n>>e;
        vector<int>values(n);
        for(int i=0; i<n; i++){
            cin>>values[i];
        }
        for(int i=0; i<e; i++){
            cin>>x>>y;
            adj[x].pb({y,values[y]});
        }
        dfs(0);
        cout<<"Case "<<v++<<": "<<soma<<" "<<last<<endl;
        for(int i=0; i<100; i++){
            adj[i].clear();
            vis[i]=false;
        }
    }
}
