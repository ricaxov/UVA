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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m; cin>>n>>m;
    while(n!=0 || m!=0){
        int cont=0;
        while(n>0 && m>0){
            if(m>n){
                swap(n,m);
            }
            if(n%m==0 or n>2*m){
                n=m=0;
            }
            else{
                n%=m;
                cont++;
            }
        }
        if(cont%2==0){
            cout<<"Stan wins"<<endl;
        }
        else{
            cout<<"Ollie wins"<<endl;
        }
        cin>>n>>m;
    }
}
