#include <bits/stdc++.h>
#define inf 1e9
#define f first
#define s second
#define pi 3.14159
#define pb push_back
#define ll long long
#define ii pair<int,int>

using namespace std;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},cont;
char matrix[21][21];
void floodfill(int x, int y, int mx, int my, char agua, char terra){
    matrix[x][y]=agua;
    cont++;
    for(int i=0; i<4; i++){
        int ax=x+dx[i];
        int ay=y+dy[i];
        if(ay<0){
            ay+=my;
        }
        if(ax>=0 && ax<mx && ay>=0 && ay<my && matrix[ax][ay]==terra){
            floodfill(ax,ay,mx,my,agua,terra);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,x,y;
    while(cin>>n>>m){
    	int maior=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>matrix[i][j];
            }
        }
        cin>>x>>y;
        char terra=matrix[x][y];
        char agua=terra-1;
        floodfill(x,y,n,m,agua,terra);
        cont=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==terra){
                    floodfill(i,j,n,m,agua,terra);
                    if(cont>maior){
                        maior=cont;
                    }
                    cont=0;
                }
            }
        }
        cout<<maior<<endl;
    }
}
