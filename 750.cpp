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

int rainhas[8],cont;
bool isSafe(int x, int y){
    for(int i=0; i<y; i++){
        if(rainhas[i]==x || abs(rainhas[i]-x)==abs(i-y)){
            return false;
        }
    }
    return true;
}
void backtracking(int x, int n, int m){
    if(x==8 && rainhas[m]==n){
        printf("%2d      %d", cont, rainhas[0]+1);
        cont++;
        for(int i=1; i<8; i++){
            printf(" %d", rainhas[i]+1);
        }
        printf("\n");
    }
    for(int i=0; i<8; i++){
        if(isSafe(i,x)){
            rainhas[x]=i;
            backtracking(x+1,n,m);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,n,m; scanf("%d", &t);
    while(t--){
        cont=1;
        scanf("%d %d", &n, &m);
        n--; m--;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtracking(0,n,m);
        if(t>0){
            printf("\n");
        }
        for(int i=0; i<8; i++){
            rainhas[i]=0;
        }
    }
}
