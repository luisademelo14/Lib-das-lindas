/*
v[] -> vetor a ser comparado o próximo e anterior maior
 */
void anterior_maior(){
    v[0] = INF;

    for(int i=1; i<=n; i++){
        ant[i] = i-1;
        while(v[i]> v[ant[i]]) ant[i] = ant[ant[i]];
    }
}

void proximo_maior(){
    v[n+1] = INF;
    for(int i=n; i>=1; i--){
        prox[i] = i+1;
        while(v[i] > v[prox[i]]) prox[i] = prox[prox[i]];
    }
}