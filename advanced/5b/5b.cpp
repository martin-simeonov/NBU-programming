#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

#define N 8

int N1;
int a[N][N];

static int cx[N] = {2, 1, -1, -2, -2, -1, 1, 2};
static int cy[N] = {1, 2, 2, 1, -1, -2, -2, -1};



const unsigned startX = 3;
const unsigned startY = 1;

const unsigned maxDiff = 8;
unsigned newX, newY;

bool limits(int x, int y) {
    return ((x >= 0 && y >= 0) && (x < N1 && y < N1));
}

bool isempty(int x, int y) {
    return (limits(x, y)) && (a[x][y] < 0);
}

int getDegree(int x, int y) {
    int count = 0;
    for (int i = 0; i < N1; ++i)
        if (isempty((x + cx[i]), (y + cy[i])))
            count++;

    return count;
}

int last_min_deg = 0;
int lastMoveX = 0, lastMoveY = 0;

bool nextMove(int *x, int *y, bool f) {
    int min_deg_idx = -1, c, min_deg = (N + 1), nx, ny;

    int start = rand()%N;
    for (int count = 0; count < N; ++count) {
        nx = *x + cx[count];
        ny = *y + cy[count];
        if ((isempty(nx, ny)) && (c = getDegree(nx, ny)) < min_deg) {
            min_deg_idx = count;
            min_deg = c;
        }
    }

    if (min_deg_idx == -1) {
        //cout << nx << " " << ny << endl;
        //cout << lastMoveX << " " << lastMoveY << endl;
       return false;
       //extMove(x, y, true);
    }

    last_min_deg = min_deg;

    nx = *x + cx[min_deg_idx];
    ny = *y + cy[min_deg_idx];

    a[nx][ny] = a[*x][*y] + 1;

    *x = nx;
    *y = ny;

    return true;
}

void print() {
    for (int i = N1 - 1; i >= 0; --i) {
        for (int j = 0; j < N1; ++j) cout << setw(2) << a[j][i] << " ";
        cout << endl;
    }
}


bool findTour(int sx, int sy) {
    for (int i = 0; i < N1; ++i) {
        for (int k = 0; k < N1; ++k)
            a[i][k] = -1;
    }

    int x = sx, y = sy;
    a[x][y] = 1; // Mark first move.

    int i;
    int count = 0;
    for (i = 0; i < N1*N1-1; ++i) {
        if (nextMove(&x, &y, false) == 0) {
           return false;
        }
        lastMoveX = x;
        lastMoveY = y;
    }

    print();
    return true;
}

int main() {
    srand(time(NULL));

    int x, y;
    int k = 0;
    while (cin >> N1 >> x >> y) {
        findTour(x - 1, y - 1);
        cout << endl;
    }
    cout << k << endl;

    return 0;
}
