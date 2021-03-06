/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :
    Rank :
    Complexity:
*/

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PQ priority_queue
#define PB push_back
#define SZ size()

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999
#define TO_DEG 57.29577951
#define PI 2*acos(0.0)

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = {-1, 0, 1, 0, -1, 1,  1, -1};
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1};

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2};

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_PRIME 10000000

ULL bitFlag[MAX_PRIME / 64 + 7];
VI primes;

void sieveBitwise()
{
    for (int i = 3; i*i <= MAX_PRIME; i += 2) {
        if ((bitFlag[i/64] & (1LL << (i%64))) == 0) {
            for (ULL j = i*i; j <= MAX_PRIME; j += 2*i) {
                bitFlag[(j/64)] |= (1L << (j%64));
            }
        }
    }
    primes.PB(2);
    for (ULL i = 3; i <= MAX_PRIME; i += 2)
        if ((bitFlag[i/64] & (1L << (i%64))) == 0) primes.PB(i);
}

bool isPrime(ULL n) {
    if (n < 2) return false;
    if (n != 2 && (n & 1) == 0) return false;
    if(n <= MAX_PRIME) return !(bitFlag[n/64] & (1L << (n%64)));
    int root = sqrt((double)n);
    for(int i = 0; primes[i] <= root; i++)
        if(n % primes[i] == 0) return false;
    return true;
}


int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();
    cl = clock() - cl;

    sieveBitwise();

    /*
    cout << primes.size() << endl;
    FOR(i, 0, 20) cout << primes[i] << endl;
    cout << isPrime(100000004987) << endl;
    */

    /*
    vector<LL> f = factorize(100000004987);
    FOR(i, 0, f.size()-1) cout << f[i] << endl;
    */

    /*
    vector<powerPrime> f = factorizeAsPower(100000004987);
    FOR(i, 0, f.size()-1) cout << f[i].p << " " << f[i].a << endl;
    */

    /*
    cout << primeFreq(5, 10) << endl;
    */

    //cout << countDivisors(36) << endl;
    //cout << sumDivisors(60) << endl;
    //cout << eulerPhi(36) << endl;

    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
