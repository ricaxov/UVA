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

ll coinchange(ll valor){
    ll resposta[valor+1]={1}, moedas[5]={1,5,10,25,50};
    for(ll i=0; i<5; i++){
        for(ll j=0; j<=valor; j++){
            if(j>=moedas[i]){
                resposta[j]+=resposta[j-moedas[i]];
            }
        }
    }
    return resposta[valor];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n;
    while(cin>>n){
        if(coinchange(n)==1){
            cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
        }
        else{
            cout<<"There are "<<coinchange(n)<<" ways to produce "<<n<<" cents change."<<endl;
        }
    }
}
