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

vector<int>dp(100000);
int fat(int x){
    if(x<2) return 1;
    if(dp[x]!=0) return dp[x];
    return dp[x]=x*fat(x-1);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    while(cin>>n){
        int cont=0,x=9;
        vector<int>vec;
        for(int i=0; i<10; i++){
           vec.pb(fat(i));
        }
        while(n>0){
            if(n>=vec[x]){
                n-=vec[x];
                cont++;
            }
            else{
                x--;
            }
        }
        cout<<cont<<endl;
    }
}
