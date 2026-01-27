#include <iostream>
#include <ostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  bool dfs(unordered_map<int, unordered_set<int>> &graph,
           unordered_set<int> &inserted, vector<int> &res,
           unordered_set<int> &visited, int toInsert) {
    if (visited.find(toInsert) != visited.end())
      return false;
    if (inserted.find(toInsert) != inserted.end())
      return true;

    visited.insert(toInsert);
    for (auto prereq : graph[toInsert]) {
      if (!dfs(graph, inserted, res, visited, prereq))
        return false;
    }
    cout << "Call with " << toInsert << endl;

    res.push_back(toInsert);
    inserted.insert(toInsert);
    visited.erase(toInsert);
    return true;
  }
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    unordered_map<int, unordered_set<int>> graph;
    unordered_set<int> inserted;
    vector<int> res;
    for (auto req : prerequisites) {
      graph[req[0]].insert(req[1]);
    }

    for (int i = 0; i < numCourses; ++i) {
      unordered_set<int> visited;
      if (!dfs(graph, inserted, res, visited, i))
        return {};
    }

    return res;
  }
};
