const int mod1 = (int)1e9+7;
const int mod2 = 998244353;
const int primo = 37;
int potencias1[MAXN], potencias2[MAXN];

void calc_potencias(int n) {
	potencias1[0] = 1;
	potencias2[0] = 1;

	for (int i=1; i<=n; i++) {
		potencias1[i] = (potencias1[i-1]*primo)%mod1;
		potencias2[i] = (potencias2[i-1]*primo)%mod2;
	}
	return;
}

int calc_hash (string s, const int mod) {
	int hash = 0;
	for (int i=0; i<(int)s.size(); i++) {
		hash = (hash+((s[i]-'a'+1)*(mod==mod1?potencias1[i]:potencias2[i])))%mod;
	}
	return hash;
}

bool sao_iguais (string a, string b) {
	return (calc_hash(a, mod1) == calc_hash(b, mod1) && calc_hash(a, mod2) == calc_hash(b, mod2));
}
