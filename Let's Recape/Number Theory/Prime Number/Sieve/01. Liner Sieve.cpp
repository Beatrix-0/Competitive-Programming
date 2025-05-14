const int N = 1e6;
int spf[N + 1];
vector<int> primes;

void computeSPF() {
    for (int i = 2; i <= N; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || i * p > N) break;
            spf[i * p] = p;
        }
    }
}
