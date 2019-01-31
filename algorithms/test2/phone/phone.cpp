// C++ program to check if there is exist a path between two vertices
// of a graph.
#include<iostream>
#include <list>
using namespace std;

// This class represents a directed graph using adjacency list
// representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    bool isReachable(int s, int d);

    bool **A;
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    A = new bool*[V];
    for (int i = 0; i < V; ++i) {
        A[i] = new bool[V];
        for (int k = 0; k < V; ++k) {
            A[i][k] = false;
        }
    }
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list
    adj[w].push_back(v);
}

// A BFS based function to check whether d is reachable from s.
bool Graph::isReachable(int s, int d)
{
    if (A[s][d]) {
        return true;
    }

    // Base case
    if (s == d)
      return true;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // it will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            // If this adjacent node is the destination node, then
            // return true
            if (*i == d) {
                A[s][d] = true;
                return true;
            }

            // Else, continue to do BFS
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

    // If BFS is complete without visiting d
    return false;
}

void driver() {
    int n, m, u, v;
    cin >> n >> m;

//    cout << n << " " << m << endl << endl;

    Graph g(m + 1);

    for (int i = 0; i < m; i++) {
        cin >> u >> v;

       // cout << u << " " << v << endl;
        g.addEdge(u, v);
    }

  //  cout << endl;

    int num;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cin >> u >> v;
       // cout << u << " " << v << endl;
        cout << g.isReachable(u, v);
    }

    //int end = path(n, m, 1, edges, false);
   // path(n, m, end, edges, true);
    //cout << endl << end;
}

int main() {
    driver();
    cout << endl;
}
