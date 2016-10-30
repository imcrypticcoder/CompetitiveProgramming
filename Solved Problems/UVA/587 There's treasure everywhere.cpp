/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :      0.016
    Rank :      1761
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

#define MAX_NODE 10001

struct Point{
    double x, y;
    Point() {}
    Point(double _x, double _y) {
        x = _x; y = _y;
    }
};

double dist2D(Point a, Point b)
{
    return sqrt(SQR(a.x-b.x)+SQR(a.y-b.y));
}

int main()
{
    READ("input.txt");
    //    WRITE("output.txt");
    int i, j, k;
    int TC, tc;
    string line, cmd;
    char dir[5];
    int len;
    double theta;
    Point p;

    tc = 1;
    while(getline(cin, line)) {
        if(line == "END") break;

        FOR(i, 0, line.length()-1) if(line[i] == ',' || line[i] == '.') line[i] = ' ';
        stringstream ss(line);

        p.x = 0;
        p.y = 0;

        while(ss >> cmd) {
            sscanf(cmd.c_str(), "%d%s", &len, dir);

            if(strcmp(dir, "E") == 0) {
                theta = 0;
            } else if(strcmp(dir, "NE") == 0) {
                theta = 45 * (PI / 180);
            } else if(strcmp(dir, "N") == 0) {
                theta = 90 * (PI / 180);
            } else if(strcmp(dir, "NW") == 0) {
                theta = 135 * (PI / 180);
            } else if(strcmp(dir, "W") == 0) {
                theta = 180 * (PI / 180);
            } else if(strcmp(dir, "SW") == 0) {
                theta = 225 * (PI / 180);
            } else if(strcmp(dir, "S") == 0) {
                theta = 270 * (PI / 180);
            } else if(strcmp(dir, "SE") == 0) {
                theta = 315 * (PI / 180);
            }

            p.x += len * cos(theta);        // cos(270) = perfect 0 outout ase na.
            p.y += len * sin(theta);        // tai nice fabs() diye check korchi.
        }
        if(fabs(p.x) < EPS) p.x = 0;
        if(fabs(p.y) < EPS) p.y = 0;

        double dist = dist2D(p, Point(0, 0));

        printf("Map #%d\n", tc++);
        printf("The treasure is located at (%.3lf,%.3lf).\n", p.x, p.y);
        printf("The distance to the treasure is %.3lf.\n\n", dist);

    }
    return 0;
}


