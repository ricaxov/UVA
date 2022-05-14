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

int dx[8]={0,1,0,-1,1,-1,-1,1}, dy[8]={1,0,-1,0,1,-1,1,-1}, cont;
char matrix[101][101];
void floodfill(int x, int y, int maxX, int maxY){
    matrix[x][y]='*';
    for(int i=0; i<8; i++){
        int ax=x+dx[i];
        int ay=y+dy[i];
        if(ax>=0 && ax<=maxX && ay>=0 && ay<=maxY && matrix[ax][ay]=='@'){
            floodfill(ax,ay,maxX,maxY);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m;cin>>n>>m;
    while(n!=0 || m!=0){
        cont=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>matrix[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='@'){
                    floodfill(i,j,n,m);
                    cont++;
                }
            }
        }
        cout<<cont<<endl;
        cin>>n>>m;
    }
}
