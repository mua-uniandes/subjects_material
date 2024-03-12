#include <bits/stdc++.h>


using namespace std;

const long long maxU = 100000000;

int primes[maxU];

void sieve() {
    int i, j;
    for(i=2; i<maxU; ++i) {
      primes[i] = 1;
    }
    for(i=2 ; i<=maxU ; i++) 
        if(primes[i]==1) 
            for(j=2 ; i*j<=maxU ; j++) 
                primes[i*j]=0;
}

vector<int> primeFactors(long long N) { 
  vector<int> factors;
  long long index = 0;
  long long primeFactor = primes[index];
  while(primeFactor*primeFactor <=N) {
    while(N%primeFactor == 0) {
      N /= primeFactor;
      factors.push_back(primeFactor);
    }
    primeFactor = primes[++index];
  }
  if(N != 1)
    factors.push_back(N);
  return factors;
}