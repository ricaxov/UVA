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

int dist[101][101];
void floydWarshall(int n){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,n,e,a,b,start,finish,cont,v=1; cin>>t;
    while(t--){
        cont=0;
        cin>>n>>e;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j]=(i==j ? 0 : inf);
            }
        }
        for(int i=0; i<e; i++){
            cin>>a>>b;
            dist[a][b]=dist[b][a]=1;
        }
        cin>>start>>finish;
        floydWarshall(n);
        for(int i=0; i<n; i++){
            cont=max(cont,dist[start][i]+dist[finish][i]);
        }
        cout<<"Case "<<v++<<": "<<cont<<endl;
    }
}
