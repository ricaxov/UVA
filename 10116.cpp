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

bool vis[10][10];
char matrix[10][10];
int dist[10][10],ciclo,cont;
void dfsCycle(int x, int y, int maxX, int maxY){
    cont++;
    int ax=x,ay=y;
    vis[x][y]=true;
    if(matrix[x][y]=='N') ax--;
    if(matrix[x][y]=='S') ax++;
    if(matrix[x][y]=='W') ay--;
    if(matrix[x][y]=='E') ay++;
    if(ax>=0 && ax<maxX && ay>=0 && ay<maxY){
        if(!vis[ax][ay]){
            dist[ax][ay]=dist[x][y]+1;
            dfsCycle(ax,ay,maxX,maxY);
        }
        else{
            dist[ax][ay]=dist[x][y]-dist[ax][ay];
            ciclo=dist[ax][ay]+1;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,x; cin>>n>>m>>x;
    while(n!=0 || m!=0 || x!=0){
        cont=ciclo=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>matrix[i][j];
            }
        }
        dfsCycle(0,x-1,n,m);
        cont-=ciclo;
        if(ciclo){
            cout<<cont<<" step(s) before a loop of "<<ciclo<<" step(s)"<<endl;
        }
        else{
            cout<<cont<<" step(s) to exit"<<endl;
        }
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                dist[i][j]=0;
                vis[i][j]=false;
            }
        }
        cin>>n>>m>>x;
    }
}
