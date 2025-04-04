/*
v[] -> vetor a ser comparado o próximo e anterior menor
 */

void anterior_menor(){
    ant[0] = 0;
    for(int i=1; i<=n; i++){
        ant[i] = i-1;
        while(v[i]<=v[ant[i]]) ant[i] = ant[ant[i]];
    }
}

void proximo_menor (){

    v[n+1] = 0;
    for(int i=n; i>=1; i--){
        prox[i] = i+1;
        while(v[i]<=v[prox[i]]) prox[i] = prox[prox[i]];
    }
}