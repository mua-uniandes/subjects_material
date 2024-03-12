
#include<string>


using namespace std;
 
const long long maxU = 100000000;

int primechk[maxU];

void sieve() {
    int i, j;
    for(i=2 ; i<=maxU ; i++) {
        primechk[i]=1;
    }
    for(i=2 ; i<=maxU ; i++) {
        if(primechk[i]==1) {
            for(j=2 ; i*j<=maxU ; j++) {
                primechk[i*j]=0;
            }
        }
    }
}


int main() {
    sieve();
    int i, cnt=0;
    for(i=2 ; i<=100000000; i++) {
        if(primechk[i]==1) {
            cnt++;
            printf("%d is the %dth prime!\n",i,cnt);
        }
    }
    return 0;
}
