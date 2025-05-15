const int mx = 1e6;
int spf[mx + 1];
vector<int> primes;

void SPF() {
    for (int i = 2; i <= mx; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || i * p > mx) break;
            spf[i * p] = p;
        }
    }
}
