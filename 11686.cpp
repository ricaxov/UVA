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

vector<int>adj[1000000],ligacoes(1000000),ordenado;
bool topoSort(int n){
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0; i<n; i++){
        if(ligacoes[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int u=pq.top(); pq.pop();
        ordenado.pb(u);
        for(int i : adj[u]){
            ligacoes[i]--;
            if(ligacoes[i]==0){
                pq.push(i);
            }
        }
    }
    return ordenado.size()==n;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,e,x,y; cin>>n>>e;
    while(n!=0 || e!=0){
        for(int i=0; i<e; i++){
            cin>>x>>y;
            x--; y--;
            adj[x].pb(y);
            ligacoes[y]++;
        }
        if(topoSort(n)){
            for(int i=0; i<n; i++){
                cout<<ordenado[i]+1<<endl;
            }
        }
        else{
            cout<<"IMPOSSIBLE"<<endl;
        }
        ordenado.clear();
        for(int i=0; i<1000000; i++){
            adj[i].clear();
            ligacoes[i]=0;
        }
        cin>>n>>e;
    }
}
