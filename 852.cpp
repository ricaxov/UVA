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

char matrix[9][9];
bool preto, branco;
int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0},pts;
void floodfill(int x, int y){
    pts++;
    matrix[x][y]='V';
    for(int i=0; i<4; i++){
        int ax=x+dx[i];
        int ay=y+dy[i];
        if(ax>=0 && ax<9 && ay>=0 && ay<9){
            if(matrix[ax][ay]=='.'){
                floodfill(ax,ay);
            }
            else{
                if(matrix[ax][ay]=='X'){
                    preto=true;
                }
                else{
                    if(matrix[ax][ay]=='O'){
                        branco=true;
                    }
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,b,p; cin>>t;
    while(t--){
        b=p=0;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cin>>matrix[i][j];
                if(matrix[i][j]=='X'){
                    p++;
                }
                else{
                    if(matrix[i][j]=='O'){
                        b++;
                    }
                }
            }
        }
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(matrix[i][j]=='.'){
                    pts=0;
                    branco=preto=false;
                    floodfill(i,j);
                    if(branco && !preto){
                        b+=pts;
                    }
                    else{
                        if(!branco && preto){
                            p+=pts;
                        }
                    }
                }
            }
        }
        cout<<"Black "<<p<<" White "<<b<<endl;
    }
}
