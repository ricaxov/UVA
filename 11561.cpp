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

bool vis[50][50];
char matrix[50][50];
int gold, dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
void floodfill(int x, int y, int maxX, int maxY){
    vis[x][y]=true;
    if(matrix[x][y]=='G'){
        gold++;
    }
    for(int i=0; i<4; i++){
        int ax=x+dx[i];
        int ay=y+dy[i];
        if(matrix[ax][ay]=='T'){
            return;
        }
    }
    for(int i=0; i<4; i++){
        int ax=x+dx[i];
        int ay=y+dy[i];
        if(ax>=0 && ax<maxX && ay>=0 && ay<maxY && !vis[ax][ay] && matrix[ax][ay]!='#'){
            floodfill(ax,ay,maxX,maxY);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m;
    while(cin>>m>>n){
        gold=0;
        ii start;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>matrix[i][j];
                if(matrix[i][j]=='P'){
                    start={i,j};
                }
            }
        }
        floodfill(start.f,start.s,n,m);
        cout<<gold<<endl;
        for(int i=0; i<50; i++){
            for(int j=0; j<50; j++){
                vis[i][j]=false;
            }
        }
    }
}
