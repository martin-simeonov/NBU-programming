#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
using namespace std;

class Node;
typedef list<Node> List;
typedef List::iterator Pos;
class Node {
private:
    int u;
    Pos p;
    public:
    Node(int u0) { u = u0; }
    void setPos(Pos p0) { p = p0; }
    int getU() { return u; }
    Pos getPos() { return p; }
};

int path(int n, int m, int start, vector<pair<int, int> > edges, bool flag) {
    vector<List> L(n + 1);
    int u, v;

    for (vector<pair<int, int> >::iterator it = edges.begin(); it != edges.end(); ++it) {
        u = it -> first;
        v = it -> second;
        Pos s = L[u].insert(L[u].end(), Node(v));
        Pos t = L[v].insert(L[v].end(), Node(u));
        s -> setPos(t);
        t -> setPos(s);
    }

    vector<int> Path(m + 1);
    Path[0] = start;
    int i = 0, j = m;
    while (i < j) {
        u = Path[i];
        if (L[u].size() > 0) {
            Node X = L[u].front();
            L[u].pop_front();
            v = X.getU();
            L[v].erase(X.getPos());
            i++;
            Path[i] = v;
        } else {
            Path[j] = u;
            i--;
            j--;
        }
    }

    for (int i = flag; i <= m; i++) {
        cout << Path[i] << " ";
    }
    return Path[m];
}

void driver() {
    int n, m, u, v;
    cin >> n >> m;

    vector<pair<int, int> > edges;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        edges.push_back(make_pair(u, v));
    }
    int end = path(n, m, 1, edges, false);
    path(n, m, end, edges, true);
    //cout << endl << end;

    cout << endl;
}

int main() {
    int num;
    cin >> num;
    for (int k = 0; k < num; ++k) {
        driver();
    }
}
