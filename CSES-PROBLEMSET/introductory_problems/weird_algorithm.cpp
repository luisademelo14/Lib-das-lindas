#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
    long long int numero;
    cin >> numero;
    cout << numero << ' ';
    while(numero != 1){
        if(numero%2){
            numero = numero * 3 + 1;
            cout << numero << ' ';
        }
        else{
            numero = numero/2;
            cout << numero << ' ';
        }
    }
}
 
int main(){
    solve();
    return 0;
}
