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

int matrix[30][30], dx[8]={0,1,0,-1,1,-1,-1,1}, dy[8]={1,0,-1,0,1,-1,1,-1}, cont;
void floodfill(int x, int y, int max){
    matrix[x][y]=0;
    for(int i=0; i<8; i++){
        int ax=x+dx[i];
        int ay=y+dy[i];
        if(ax>=0 && ax<max && ay>=0 && ay<max && matrix[ax][ay]==1){
            floodfill(ax,ay,max);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,x=0;
    while(cin>>n){
        x++;
        cont=0;
        string str;
        for(int i=0; i<n; i++){
            cin>>str;
            for(int j=0; j<n; j++){
                matrix[i][j]=str[j]-48;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==1){
                    floodfill(i,j,n);
                    cont++;
                }
            }
        }
        cout<<"Image number "<<x<<" contains "<<cont<<" war eagles."<<endl;
    }
}
