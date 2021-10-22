#include <cmath>

int surfaceArea(vector<vector<int>> A) {
    
    int nrow = A.size(), ncol = A[0].size(); 
    int surface_area = nrow * ncol * 2;
    
    for (size_t r = 0; r < nrow; r++) {
        surface_area += A[r][0];
        for (size_t c = 0; c < ncol - 1; c++) {
            surface_area += abs(A[r][c] - A[r][c + 1]);
            }
        surface_area += A[r][ncol - 1];
        }
    
    for (size_t c = 0; c < ncol; c++) {
        surface_area += A[0][c];
        for (size_t r = 0; r < nrow - 1; r++) {
            surface_area += abs(A[r][c] - A[r + 1][c]);
            }
        surface_area += A[nrow - 1][c];
        }

    return surface_area;
}
