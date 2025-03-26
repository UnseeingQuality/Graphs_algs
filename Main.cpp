#include <Matrix.h>
#include <queue>

constexpr int INF = 1e9;

bool areConnected(const Matrix& graph, size_t i, size_t j) {
    if (i >= graph.Rows || j >= graph.Cols) {
        assert(false);
    }
    return graph(i, j) == 1;
}

std::vector<unsigned int> getNeighbors (std::vector<unsigned int> relationRow) {
    std::vector<unsigned int> NeighborsIds;
    unsigned int currId = 0;
    for (unsigned int inRelation : relationRow) {
        if (inRelation) {
            NeighborsIds.push_back(currId);
        }
        currId += 1;
    }
    return NeighborsIds;
}

std::vector<int> bfs (const Matrix& graph, size_t start, size_t finish) {
    std::vector<int> visited(graph.Rows);
    std::vector<int> dist(graph.Rows, INF);
    std::queue<int> q;
    unsigned int frontId = 0;

    visited[start] = 1;
    dist[start] = 0;
    q.push(start);

    while (!q.empty() && visited[finish] != 1) {
        int curr_vert = q.front();
        q.pop();
        std::vector<unsigned int> currRelations = graph.GetRow(curr_vert);
        std::vector<unsigned int> currNeighbors = getNeighbors(currRelations);

        for (unsigned int to : currNeighbors) {
            if (!visited[to]) {
                visited[to] = 1;
                dist[to] = dist[curr_vert] + 1;
                q.push(to);
            }
            frontId += 1;
            std::queue<int> temp = q;
            while (!temp.empty()) {
                temp.pop();
            }
            // std::cout << std::endl;
        }
    }

    return dist;
}

int main() {
    Matrix graph(9, 9);
    std::vector<int> dists;
    int res;
    int start;
    int finish;

    start = 5;
    finish = 1;

    unsigned int values[9][9] = {
        {0,  0,  0,  0,  1,  0,  1,  0,  0},
        {0,  0,  0,  0,  1,  0,  0,  0,  1},
        {0,  0,  0,  1,  0,  1,  1,  0,  1},
        {0,  0,  1,  0,  1,  1,  0,  0,  0},
        {1,  1,  0,  1,  0,  1,  0,  1,  0},
        {0,  0,  1,  1,  1,  0,  0,  0,  0},
        {1,  0,  1,  0,  0,  0,  0,  1,  0},
        {0,  0,  0,  0,  1,  0,  1,  0,  1},
        {0,  1,  1,  0,  0,  0,  0,  1,  0}
    };

    for (size_t i = 0; i < 9; i++) {
        for (size_t j = 0; j < 9; j++) {
            graph(i, j) = values[i][j];
        }
    }

    printf("Matrix relation: \n");
    graph.Print();

    dists = bfs(graph, start, finish);
    res = dists[finish];
    for (int d : dists) {
        if (d != INF)
            std::cout << d << " ";
        else
            std::cout << "X ";
    }
    std::cout << "\n" << std::endl;
    std::cout << res << std::endl;
}