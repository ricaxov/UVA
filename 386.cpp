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
    for(int i=6; i<=200; i++){
        for(int j=2; j<=i; j++){
            for(int k=j+1; k<=i; k++){
                for(int l=k+1; l<=i; l++){
                    if(i*i*i==j*j*j+k*k*k+l*l*l){
                        cout<<"Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<l<<")"<<endl;
                    }
                }
            }
        }
    }
}
