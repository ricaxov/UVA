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

int vet[13];
vector<int>vec;
void f(int n, int x){
    if(vec.size()==6){
        for(int i=0; i<6; i++){
            cout<<vec[i];
            if(i<5){
                cout<<' ';
            }
        }
        cout<<endl;
        return ;
    }
    for(int i=x; i<n; i++){
        vec.pb(vet[i]);
        f(n,i+1);
        vec.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int v; cin>>v;
    bool ver=false;
    while(v!=0){
        if(ver){
            cout<<endl;
        }
        for(int i=0; i<v; i++){
            cin>>vet[i];
        }
        f(v,0);
        ver=true;
        cin>>v;
    }
}
