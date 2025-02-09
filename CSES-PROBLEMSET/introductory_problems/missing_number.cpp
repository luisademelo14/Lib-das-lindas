#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
    int numero, componente;
    set <int> componentes;
    cin >> numero;
    for(int i=1; i<=numero; i++){
        componentes.insert(i);
    }
    for(int i=0; i<numero-1; i++){
        cin >> componente;
        componentes.erase(componente);
    }
    cout << *componentes.begin();
 
}
 
int main(){
    solve();
    return 0;
}
