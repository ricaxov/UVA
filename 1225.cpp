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
    int t,x; cin>>t;
    while(t--){
        cin>>x;
        string str;
        int vet[10]={0};
        for(int i=1; i<=x; i++){
            str+=tos(i);
        }
        for(int i=0; i<str.size(); i++){
            vet[str[i]-'0']++;
        }
        for(int i=0; i<10; i++){
            cout<<vet[i];
            if(i<9){
                cout<<' ';
            }    
        }
        cout<<endl;
    }
}
