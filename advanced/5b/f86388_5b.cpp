#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

#define N 8

int N1;
int a[N][N];

static int cx1[N] = {1, 1, 2, 2, -1, -1, -2, -2};
static int cy1[N] = {2, -2, 1, -1, 2, -2, 1, -1};

static int cx2[N] = {-2, -2, -1, -1, 2, 2, 1, 1};
static int cy2[N] = {1, -1, 2, -2, 1, -1, 2, -2};

static int cx3[N] = {2, 1, -1, -2, -2, -1, 1, 2};
static int cy3[N] = {1, 2, 2, -1, -1, -2, -2, -1};

const unsigned startX = 3;
const unsigned startY = 1;

const unsigned maxDiff = 8;
unsigned newX, newY;

bool exitFlag;

int j = 0;

bool limits(int x, int y) {
    return ((x >= 0 && y >= 0) && (x < N1 && y < N1));
}

bool isempty(int x, int y) {
    return (limits(x, y)) && (a[x][y] < 0);
}

int getDegree(int x, int y) {
    int count = 0;
    for (int i = 0; i < N1; ++i)
        if (isempty((x + cx1[i]), (y + cy1[i])))
            count++;

    return count;
}

bool nextMove(int *x, int *y) {
    int min_deg_idx = -1, c, min_deg = (N + 1), nx, ny;

    int start = rand()%N;
    for (int count = 0; count < N; ++count) {
        nx = *x + cx1[count];
        ny = *y + cy1[count];
        if ((isempty(nx, ny)) && (c = getDegree(nx, ny)) < min_deg) {
            min_deg_idx = count;
            min_deg = c;
        }
    }

    if (min_deg_idx == -1)
        return false;

    nx = *x + cx1[min_deg_idx];
    ny = *y + cy1[min_deg_idx];

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
        if (nextMove(&x, &y) == 0)
           return false;
    }

    print();
    return true;
}

void second(unsigned X, unsigned Y, unsigned i, bool f) {
    unsigned k;
    a[X][Y] = i;
    if (exitFlag) return;
    if (i == N1 * N1) { print(); exitFlag = true; return;}
    for (k = 0; k < maxDiff; k++) {
        if (f) {
            newX = X + cx2[k]; newY = Y + cy2[k];
        } else {
            newX = X + cx1[k]; newY = Y + cy1[k];
        }
        if ((newX >= 0 && newX < N1 && newY >= 0 && newY < N1) && (0 == a[newX][newY])) {
            second(newX, newY, i + 1, f);
        }
    }
    a[X][Y] = 0;
}

void clear_arr() {
    for (int i = 0; i < N1; i++)
        for (int j = 0; j < N1; j++) a[i][j] = 0;
}

int main() {
    srand(time(NULL));

    int x, y;
    while (cin >> N1 >> x >> y) {
        exitFlag = false;
        clear_arr();
        if (N1 < 5) {
            print();
            cout << endl;
            continue;
        }
        if(!findTour(x - 1, y - 1)) {
            clear_arr();
            bool f = abs(x - y) >= 1 ? true : false;

            second(x - 1, y - 1, 1, f);
            if (!exitFlag) {
                clear_arr;
                print();
            }
        }
        cout << endl;
    }

    return 0;
}
