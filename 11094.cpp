#include <bits/stdc++.h>
#define f first
#define s second
#define pi 3.14159
#define pb push_back
#define ll long long
#define ii pair<int,int>

using namespace std;

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},cont,maior;
char matrix[21][21];
void terras(int x, int y, int mx, int my, int agua, int terra){
	matrix[x][y]='X';
	cont++;
	for(int i=0; i<4; i++){
        int ax=x+dx[i];
        int ay=y+dy[i];
        if(ax>=0 && ax<mx && ay>=0 && ay<my && matrix[ax][ay]==terra){
            terras(ax,ay,mx,my,agua,terra);
        }
    }
}
void elimina(int x, int y, int mx, int my, char agua, char terra){
    matrix[x][y]=agua;
    for(int i=0; i<4; i++){
        int ax=x+dx[i];
        int ay=y+dy[i];
        if(ax>=0 && ax<mx && ay>=0 && ay<my && matrix[ax][ay]==terra){
            elimina(ax,ay,mx,my,agua,terra);
        }
    }
}
void floodfill(int x, int y, int mx, int my, char agua, char terra){
    matrix[x][y]=agua;
    cont++;
    for(int i=0; i<4; i++){
        int ax=x+dx[i];
        int ay=y+dy[i];
        if(matrix[x][0]==terra && matrix[x][my-1]==terra){
        	//cout<<"aosidjaosidj"<<endl;
        	terras(ax,my-1,mx,my,agua,terra);
        	terras(ax,0,mx,my,agua,terra);
        	//break;
		}
        if(ax>=0 && ax<mx && ay>=0 && ay<my && matrix[ax][ay]==terra){
            floodfill(ax,ay,mx,my,agua,terra);
        }
    }
    if(cont>maior){
		maior=cont;
		cont=0;
	}
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,x,y;
    while(cin>>n>>m){
    	cont=0,maior=0;
		char agua,terra;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>matrix[i][j];
            }
        }
        //teste de matriz
        //cout<<"matriz antes do ff"<<endl;
        //for(int i=0; i<n; i++){
        //    for(int j=0; j<m; j++){
        //        cout<<matrix[i][j]<<" ";
        //    }
        //    cout<<endl;
        //}
        cin>>x>>y;
        terra=matrix[x][y];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]!=terra && matrix[i][j]!='\0'){
                    agua=matrix[i][j];
                    i=n;
                }
            }
        }
		elimina(x,y,n,m,agua,terra);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==terra){
                    floodfill(i,j,n,m,agua,terra);
                }
            }
        }
        //teste da matrix
        //cout<<"matriz dps do ff"<<endl;
        //for(int i=0; i<n; i++){
        //    for(int j=0; j<m; j++){
        //        cout<<matrix[i][j]<<" ";
        //    }
        //    cout<<endl;
        //}
        cout<<maior<<endl;
    }
}
