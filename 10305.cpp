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

vector<int>adj[100],ligacoes(100),ordenado(100);
void topoSort(int n){
    queue<int>q;
    for(int i=0; i<n; i++){
        for(int j : adj[i]){
            ligacoes[j]++;
        }
    }
    for(int i=0; i<n; i++){
        if(ligacoes[i]==0){
            q.push(i);
        }
    }
    int index=0;
    while(!q.empty()){
        int u=q.front(); q.pop();
        ordenado[index++]=u;
        for(int i : adj[u]){
            ligacoes[i]--;
            if(ligacoes[i]==0){
                q.push(i);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,e,x,y; cin>>n>>e;
    while(n!=0 || e!=0){
        for(int i=0; i<e; i++){
            cin>>x>>y;
            x--; y--;
            adj[x].pb(y);
        }
        topoSort(n);
        for(int i=0; i<n; i++){
            cout<<ordenado[i]+1;
            if(i<n-1){
                cout<<' ';
            }
        }
        cout<<endl;
        for(int i=0; i<100; i++){
            adj[i].clear();
            ligacoes[i]=ordenado[i]=0;
        }
        cin>>n>>e;
    }
}
