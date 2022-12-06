#include <iostream>
#include <algorithm>
#include <limits>

const int N = 6;

void shortest_path(int A[N][N], int D[N][N]) {
    int n = N;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            D[i][j] = A[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                D[i][j] = std::min(D[i][j], D[i][k] + D[k][j]);
                if (D[i][j] > 1000000) {
                    D[i][j] = 888;
                }
                std::cout << D[i][j];
                std::cout << "   ";
            }
            std::cout << std::endl;
        }
        std::cout << "\n";
    }
}


int main()
{

    
int A[N][N] = { {0,8,std::numeric_limits<int>::max(),9,7,std::numeric_limits<int>::max()},
                {6,0,-2,10,std::numeric_limits<int>::max(),8},
                {2,4,0,7,7,10},
                {5, std::numeric_limits<int>::max(), 3, 0, 3, std::numeric_limits<int>::max()},
                {std::numeric_limits<int>::max(), 9, 8, 3, 0, 6},
                {3, 3, 5, std::numeric_limits<int>::max(), 1, 0}
};

    int D[N][N]{};

    shortest_path(A, D);

    return 0;
}
