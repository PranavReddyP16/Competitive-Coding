#include<bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    vector<int> primes;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(long long j=(long long)i*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return primes;
}

vector<int> spf_sieve(int n) {
    vector<int> spf(n+1);
    iota(spf.begin(), spf.end(), 0);
    for(int i=2;i*i<=n;i++) if(spf[i]==i)
        for(int j=i*i;j<=n;j+=i) if(spf[j]==j) spf[j]=i;
    return spf;
}

int main() {
    int n; cin>>n;
    auto primes=sieve(n);
    cout<<"Primes up to "<<n<<": "<<primes.size()<<"\n";
    auto spf=spf_sieve(n);
    int x; cin>>x;
    cout<<"Factorization of "<<x<<": ";
    while(x>1) { cout<<spf[x]<<" "; x/=spf[x]; }
}
// 9167000
// 5127000
// 8595000
// 1417877676
// 41699384
// 1874771648
// 2470394542
// 328639157
