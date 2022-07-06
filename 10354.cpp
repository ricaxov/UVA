#include <bits/stdc++.h>
#define f first
#define s second
#define pi 3.14159
#define pb push_back
#define tos to_string
#define inf 100000000
#define inf64 1000000000000000000
#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

bool vis[100];
int eu[100][100], chefe[100][100];
void floydWarshall(int n, int dist[100][100]){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!vis[k]){
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,e,boss,office,home,market,a,b,p;
    while(cin>>n>>e>>boss>>office>>home>>market){
        boss--;office--;home--;market--;
        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                chefe[i][j]=eu[i][j]=(i==j ? 0 : inf);
            }
        }
        for(int i=0; i<e; i++){
            cin>>a>>b>>p;
            a--;b--;
            chefe[a][b]=chefe[b][a]=eu[a][b]=eu[b][a]=p;
        }
        floydWarshall(100, chefe);
        for(int i=0; i<n; i++){
            if(chefe[boss][office]==chefe[boss][i]+chefe[office][i]){
                vis[i]=true;
            }
        }
        floydWarshall(100, eu);
        if(eu[home][market]==inf || vis[home] || vis[market]){
            cout<<"MISSION IMPOSSIBLE."<<endl;
        }
        else{
            cout<<eu[home][market]<<endl;
        }
        for(int i=0; i<100; i++){
            vis[i]=false;
        }
    }
}
