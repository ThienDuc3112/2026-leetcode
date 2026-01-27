#include "../common_header.hpp"

class Vertex {
public:
  int vertexId;
  bool offline = false;
  int powerGridId = -1;

  Vertex() {}
  Vertex(int id) : vertexId(id) {}
};

using PowerGrid = priority_queue<int, vector<int>, greater<int>>;
using Graph = vector<vector<int>>;

class Solution {
private:
  vector<Vertex> vertices = vector<Vertex>();

  void traverse(Vertex &u, int powerGridId, PowerGrid &powerGrid,
                Graph &graph) {
    u.powerGridId = powerGridId;
    powerGrid.push(u.vertexId);
    for (int vid : graph[u.vertexId]) {
      Vertex &v = vertices[vid];
      if (v.powerGridId == -1)
        traverse(v, powerGridId, powerGrid, graph);
    }
  }

public:
  vector<int> processQueries(int c, vector<vector<int>> &connections,
                             vector<vector<int>> &queries) {
    Graph graph(c + 1);
    vertices.resize(c + 1);

    for (int i = 1; i <= c; i++) {
      vertices[i] = Vertex(i);
    }

    for (auto &conn : connections) {
      graph[conn.at(0)].push_back(conn.at(1));
      graph[conn.at(1)].push_back(conn.at(0));
    }

    vector<PowerGrid> powerGrids;

    for (int i = 1, powerGridId = 0; i <= c; i++) {
      auto &v = vertices[i];
      if (v.powerGridId == -1) {
        PowerGrid powerGrid;
        traverse(v, powerGridId, powerGrid, graph);
        powerGrids.push_back(powerGrid);
        powerGridId++;
      }
    }

    vector<int> ans;
    for (auto &q : queries) {
      int op = q.at(0), x = q.at(1);
      if (op == 1) {
        if (!vertices[x].offline) {
          ans.push_back(x);
        } else {
          auto &powerGrid = powerGrids[vertices[x].powerGridId];
          while (!powerGrid.empty() && vertices[powerGrid.top()].offline) {
            powerGrid.pop();
          }
          ans.push_back(!powerGrid.empty() ? powerGrid.top() : -1);
        }
      } else if (op == 2) {
        vertices[x].offline = true;
      }
    }
    return ans;
  }
};
class BadSolution {
public:
  vector<int> processQueries(int c, vector<vector<int>> &connections,
                             vector<vector<int>> &queries) {
    vector<int> res;
    vector<set<int>> sets;
    vector<int> idxMapping(c, -1);
    set<int> offline;

    for (vector<int> con : connections) {
      int a = con[0] - 1, b = con[1] - 1;

      cout << "a: " << a << " b: " << b << endl;
      cout << "idxMapping[a]: " << idxMapping[a]
           << " idxMapping[b]: " << idxMapping[b] << endl;

      if (idxMapping[a] == -1 && idxMapping[b] == -1) {
        set<int> temp = {a, b};
        sets.push_back(temp);
        idxMapping[a] = idxMapping[b] = sets.size() - 1;
      } else if (idxMapping[a] == idxMapping[b])
        continue;
      else if (idxMapping[a] == -1) {
        idxMapping[a] = idxMapping[b];
        sets[idxMapping[a]].insert(a);
      } else if (idxMapping[b] == -1) {
        idxMapping[b] = idxMapping[a];
        sets[idxMapping[b]].insert(b);
      } else {

        cout << "before:\n";
        cout << "[";
        for (int m : idxMapping)
          cout << m << " ";
        cout << "]\n";

        if (sets[idxMapping[a]].size() > 0) {
          cout << "set a:\n";
          for (int e : sets[idxMapping[a]])
            cout << e << " ";
          cout << endl;
        }
        if (sets[idxMapping[b]].size() > 0) {
          cout << "set b:\n";
          for (int e : sets[idxMapping[b]])
            cout << e << " ";
          cout << endl;
        }

        int oldIdx = idxMapping[b];
        for (int key : sets[oldIdx]) {
          idxMapping[key] = idxMapping[a];
          sets[idxMapping[a]].insert(key);
        }
        sets[oldIdx].clear();

        cout << "\nafter:\n";
        cout << "[";
        for (int m : idxMapping)
          cout << m << " ";
        cout << "]\n";
        if (sets[idxMapping[a]].size() > 0) {
          cout << "set a:\n";
          for (int e : sets[idxMapping[a]])
            cout << e << " ";
          cout << endl;
        }
        if (sets[idxMapping[b]].size() > 0) {
          cout << "set b:\n";
          for (int e : sets[idxMapping[b]])
            cout << e << " ";
          cout << endl;
        }

        if (sets[idxMapping[a]].size() == c)
          break;
      }
    }

    int i = 0;
    for (set<int> s : sets) {
      cout << "set " << i << ": ";
      if (s.size() > 0)
        for (int e : s)
          cout << e << " ";
      cout << endl;
    }

    for (vector<int> q : queries) {
      int a = q[1] - 1;
      if (q[0] == 2) {
        offline.insert(a);
        if (idxMapping[a] != -1)
          sets[idxMapping[a]].erase(a);
      } else if (offline.find(a) == offline.end())
        res.push_back(a + 1);
      else if (idxMapping[a] == -1 || sets[idxMapping[a]].empty())
        res.push_back(-1);
      else
        res.push_back(*sets[idxMapping[a]].begin() + 1);
    }

    return res;
  }
};
