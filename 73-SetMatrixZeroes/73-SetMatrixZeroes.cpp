// Last updated: 26/11/2025, 22:34:09
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
    int row = matrix.size(), col = matrix[0].size();
    bool firstRow = false, firstCol = false;

    for (int i = 0; i < row; i++) {
        if (matrix[i][0] == 0) firstCol = true;
    }
    for (int j = 0; j < col; j++) {
        if (matrix[0][j] == 0) firstRow = true;
    }

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstRow) {
        for (int j = 0; j < col; j++) {
            matrix[0][j] = 0;
        }
    }
    if (firstCol) {
        for (int i = 0; i < row; i++) {
            matrix[i][0] = 0;
        }
    }
}

};