#include "../common_header.hpp"

struct Pos {
  int i, j, dist;
};

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    queue<Pos> q;
    vector<vector<bool>> visited{mat.size(),
                                 vector<bool>(mat[0].size(), false)};

    for (int i = 0; i < mat.size(); i++)
      for (int j = 0; j < mat[i].size(); j++)
        if (mat[i][j] == 0)
          q.push({i, j, 0});

    int count = 0;
    while (!q.empty()) {
      count++;
      Pos p = q.front();
      q.pop();
      if (visited[p.i][p.j])
        continue;
      visited[p.i][p.j] = true;
      mat[p.i][p.j] = p.dist;
      if (p.i + 1 < mat.size() && !visited[p.i + 1][p.j])
        q.push({p.i + 1, p.j, p.dist + 1});
      if (p.i - 1 >= 0 && !visited[p.i - 1][p.j])
        q.push({p.i - 1, p.j, p.dist + 1});
      if (p.j - 1 >= 0 && !visited[p.i][p.j - 1])
        q.push({p.i, p.j - 1, p.dist + 1});
      if (p.j + 1 < mat[p.i].size() && !visited[p.i][p.j + 1])
        q.push({p.i, p.j + 1, p.dist + 1});
    }
    cout << "count: " << count << " m*n: " << mat.size() << " " << mat[0].size()
         << endl;

    return mat;
  }
};
