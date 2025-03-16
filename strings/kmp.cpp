// complexidade O(n+m)

// constroi vetor com os tamanhos dos maiores prefixos pattern[0...i] que
// tambem sao sufixos (nao vale a string inteira)
void construct_lps(string &pattern, vector<int> &lps){
    int len = 0;

    lps[0] = 0;

    int i = 1;

    int m = pattern.length();

    while(i < m){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }

        else{
            if(len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}


// retorna vetor com os indices do texto em que o padrao
// ocorre (indices do primeiro char do padrao)
vector<int> kmp(string &pattern, string &text){
    int n = text.length();
    int m = pattern.length();

    vector<int> lps(m);
    vector<int> res; 

    construct_lps(pattern, lps);

    int i = 0; // pointer pro texto
    int j = 0; // pointer pro padrao

    while(i < n){ // percorrendo texto
        if(text[i] == pattern[j]){
            i++;
            j++;

            if(j == m){ // chegou ao final do padrao
                res.push_back(i-j);
                j = lps[j-1];
            }
        }

        else{
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }
    return res;
}
