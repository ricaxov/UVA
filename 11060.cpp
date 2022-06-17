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

vector<string>adj[150];
vector<int>ligacoes(150);
map<string,int>aux;
map<int,string>ordenado;
void topoSort(vector<string>&bebidas){
    priority_queue<int, vector<int>, greater<int>>q;
    for(int i=0; i<bebidas.size(); i++){
        if(ligacoes[aux[bebidas[i]]]==0){
            q.push(i);
        }
    }
    int index=0;
    while(!q.empty()){
        int u=q.top(); q.pop();
        ordenado[index++]=bebidas[u];
        for(string i : adj[aux[bebidas[u]]]){
            ligacoes[aux[i]]--;
            if(ligacoes[aux[i]]==0){
                q.push(aux[i]);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,e,v=1;
    while(cin>>n){
        string drink,a,b;
        vector<string>vec;
        for(int i=0; i<n; i++){
            cin>>drink;
            vec.pb(drink);
            aux[drink]=i;
        }
        cin>>e;
        for(int i=0; i<e; i++){
            cin>>a>>b;
            adj[aux[a]].pb(b);
            ligacoes[aux[b]]++;
        }
        topoSort(vec);
        cout<<"Case #"<<v++<<": Dilbert should drink beverages in this order: ";
        for(int i=0; i<ordenado.size(); i++){
            cout<<ordenado[i];
            if(i<ordenado.size()-1){
                cout<<' ';
            }
        }
        cout<<'.'<<endl<<endl;
        aux.clear();
        ordenado.clear();
        for(int i=0; i<150; i++){
            adj[i].clear();
        }
        
    }
}
