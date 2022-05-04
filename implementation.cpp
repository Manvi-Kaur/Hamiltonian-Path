// Kruskal's algorithm in C++
#include <bits/stdc++.h>
using namespace std;

#define edge pair<int, int>

class Graph {
   private:
    vector<pair<int, edge> > G;  // graph
    vector<pair<int, edge> > T;  // mst
    vector<vector<int>> adjlist; 
    int *parent;
    int v;  // number of vertices/nodes in graph

   public:
    Graph(int V);
    void AddWeightedEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();
    bool checkhampath();
    void makeadjlist();
};

Graph::Graph(int V) {
  v = V;
  parent = new int[V];

  //i 0 1 2 3 4 5
  //parent[i] 0 1 2 3 4 5
  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}

void Graph::AddWeightedEdge(int u, int v, int w) {
  G.push_back(make_pair(w, edge(u, v)));
  G.push_back(make_pair(w, edge(v, u)));
}

int Graph::find_set(int i) {
  // If i is the parent of itself
  if (i == parent[i])
    return i;
  else
    // Else if i is not the parent of itself
    // Then i is not the representative of his set,
    // so we recursively call Find on its parent
    return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
  parent[u] = parent[v];
}

void Graph::kruskal() {
    // cout << "inside kruskal" << endl;
  int i, uRep, vRep;
//   sort(G.begin(), G.end());  // increasing weight
  for (i = 0; i < G.size(); i++) {
    uRep = find_set(G[i].second.first);
    vRep = find_set(G[i].second.second);
    // cout << i << " ";
    if (uRep != vRep) { //*ensure that degree
      T.push_back(G[i]);  // add to tree
      union_set(uRep, vRep);
    }
  }
    // cout << "finoshed kruskal" << endl;

}
void Graph::print() {
  cout << "Edge :"
     << " Weight" << endl;
  for (int i = 0; i < T.size(); i++) {
    cout << T[i].second.first << " - " << T[i].second.second << " : "
       << T[i].first;
    cout << endl;
  }
}

void Graph :: makeadjlist(){ //Make an adj list of B
    adjlist.resize(v);
    for(int i = 0; i < T.size(); i++){
        adjlist[T[i].second.first].push_back(T[i].second.second);
        adjlist[T[i].second.second].push_back(T[i].second.first);
    }
}

bool Graph :: checkhampath(){
    // cout << "sending for kruskal" << endl;
    kruskal();   
    // cout << "out of kruskal" << endl;
    // cout << T.size();
    // int cost = 0;
    // cout << T.size() << " " << v-1 <<   endl;
    // return (T.size() == v-1);
    // for (int i = 0; i < T.size(); i++) {
    //   cost +=  T[i].second.first + T[i].second.second << " : "
    //     << T[i].first;
    //   cout << endl;

    makeadjlist();
    //Checking if each vertex (except first and last) has a degree = 2
    for(int i = 1; i < adjlist.size()-1; i++){
        // cout << adjlist[i].size() << " ";
        if(adjlist[i].size() != 2) return false;
    }
    return true;
}
int main() {
  Graph g(4);

  // g.AddWeightedEdge(0, 1, 1);
  // g.AddWeightedEdge(1, 2, 1);
  // g.AddWeightedEdge(2, 3, 1);
  // g.AddWeightedEdge(1, 0, 1);
  // g.AddWeightedEdge(2, 1, 1);
  // g.AddWeightedEdge(3, 2, 1);

  g.AddWeightedEdge(0, 1, 1);
  g.AddWeightedEdge(0, 2, 1);
  g.AddWeightedEdge(0, 3, 1);
  g.AddWeightedEdge(1, 2, 1);
  g.AddWeightedEdge(1, 3, 1);
  g.AddWeightedEdge(2, 3, 1);

  // g.AddWeightedEdge(0, 1, 1);
  // g.AddWeightedEdge(0, 2, 1);
  // g.AddWeightedEdge(1, 2, 1);
  // g.AddWeightedEdge(1, 0, 1);
  // g.AddWeightedEdge(2, 0, 1);
  // g.AddWeightedEdge(2, 1, 1);
  // g.AddWeightedEdge(2, 3, 1);
  // g.AddWeightedEdge(2, 5, 1);
  // g.AddWeightedEdge(2, 4, 1);
  // g.AddWeightedEdge(3, 2, 1);
  // g.AddWeightedEdge(3, 4, 1);
  // g.AddWeightedEdge(4, 2, 1);
  // g.AddWeightedEdge(4, 3, 1);
  // g.AddWeightedEdge(5, 2, 1);
  // g.AddWeightedEdge(5, 4, 1);
  // g.kruskal();
  // g.print();
  cout << g.checkhampath() << endl;
  g.print();
  return 0;
}