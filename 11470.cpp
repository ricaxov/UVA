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

vector<int>vec;
bool vis[11][11];
int matrix[11][11];
void floodfill(int x, int y, int maxSize){
    for(int i=0, j=maxSize-1; i<ceil(maxSize/2.0) && j>=0; i++, j--){
        int soma=0;
        for(int k=0; k<maxSize; k++){
            for(int l=0; l<maxSize; l++){
                if((k==i || k==j || l==i || l==j) && !vis[k][l]){
                    soma+=matrix[k][l];
                    vis[k][l]=true;
                }
            }
        }
        vec.pb(soma);
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,x=0; cin>>n;
    while(n!=0){
        x++;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>matrix[i][j];
            }
        }
        floodfill(0,0,n);
        cout<<"Case "<<x<<": ";
        for(int i=0; i<vec.size(); i++){
            cout<<vec[i];
            if(i<vec.size()-1){
                cout<<' ';
            }
        }
        cout<<endl;
        vec.clear();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                vis[i][j]=false;
            }
        }
        cin>>n;
    }
}
