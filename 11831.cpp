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

char matrix[100][100];
int figs,dx[4]={-1,1,0,0},dy[4]={0,0,1,-1};
void floodfill(int &x, int &y, int maxX, int maxY, int direction){
    x+=dx[direction];
    y+=dy[direction];
    if(x>=0 && x<maxX && y>=0 && y<maxY && matrix[x][y]!='#'){
        if(matrix[x][y]=='*'){
            figs++;
        }
        matrix[x][y]='.';
    }
    else{
        x-=dx[direction];
        y-=dy[direction];
    }
}
void modify(int &direction, char move){
    if(direction==0){
        direction=(move=='D' ? 2 : 3);
    }
    else{
        if(direction==1){
            direction=(move=='D' ? 3 : 2);
        }
        else{
            if(direction==2){
                direction=(move=='D' ? 1 : 0);
            }
            else{
                direction=(move=='D' ? 0 : 1);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,v; cin>>n>>m>>v;
    while(n!=0 || m!=0 || v!=0){
        figs=0;
        string moves;
        int x,y,direcao;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>matrix[i][j];
                if(matrix[i][j]!='.' && matrix[i][j]!='*' && matrix[i][j]!='#'){
                    map<char,int>mp; mp['N']=0,mp['S']=1,mp['L']=2,mp['O']=3;
                    direcao=mp[matrix[i][j]];
                    x=i,y=j;
                }
            }
        }
        cin>>moves;
        for(int i=0; i<v; i++){
            if(moves[i]=='F'){
                floodfill(x,y,n,m,direcao);
            }
            else{
                modify(direcao,moves[i]);
            }
        }
        cout<<figs<<endl;
        cin>>n>>m>>v;
    }
}
