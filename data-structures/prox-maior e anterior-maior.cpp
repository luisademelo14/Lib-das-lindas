void anterior_maior(){
    v[0] = {0,inf};

    for(int i=1; i<=n; i++){
        ant[i] = i-1;
        while(v[i].second > v[ant[i]].second) ant[i] = ant[ant[i]];
    }
}

void proximo_maior(){
    v[n+1] = {0,inf};
    for(int i=n; i>=1; i--){
        prox[i] = i+1;
        while(v[i].second > v[prox[i]].second) prox[i] = prox[prox[i]];
    }
}