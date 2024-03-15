#include <iostream>
#include <fstream>

namespace GLOBAL_CONSTANTS {
    constexpr char firstFileName[] = "file1.txt";
    constexpr char secondFileName[] = "file2.txt";
    constexpr char outputFileName[] = "file.txt";
    constexpr char ROW_SEPARATOR = '|';
    constexpr char COL_SEPARATOR = ',';
}

void getMatrixDimensions(std::ifstream& in, size_t& rows, size_t& cols) {
    size_t countRows = 0, countCols = 0;

    while (!in.eof()) {
        char a;
        in.get(a);

        if (a == GLOBAL_CONSTANTS::COL_SEPARATOR && countRows == 0) {
            countCols++;
        } else if (a == GLOBAL_CONSTANTS::ROW_SEPARATOR) {
            countRows++;
        }
    }

    in.clear();
    in.seekg(0, std::ios::beg);

    rows = countRows + 1;
    cols = countCols + 1;
}

void initMatrix(std::ifstream& in, int** matrix) {
    size_t currentRow = 0, currentCol = 0;
    int currentNumber = 0;
    
    while (!in.eof()) {
        char a;
        in.get(a);
        if (in.eof()) {
            break;
        }

        if (a == GLOBAL_CONSTANTS::COL_SEPARATOR) {
            currentCol++;
            currentNumber = 0;
        }
        else if (a == GLOBAL_CONSTANTS::ROW_SEPARATOR) {
            currentRow++;
            currentCol = 0;
            currentNumber = 0;
        }
        else {
            currentNumber = currentNumber * 10 + (a - '0');
            matrix[currentRow][currentCol] = currentNumber;
        }
    }
}

void printMatrix(int** matrix, const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

void freeMatrix(int** matrix, const size_t rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int** multiplyMatrices(int** matrixOne, const size_t matrixOneRows, const size_t matrixOneCols, int** matrixTwo, 
    const size_t matrixTwoRows, const size_t matrixTwoCols, size_t& resultMatrixRows, size_t& resultMatrixCols) {
    if (matrixOneCols != matrixTwoRows) {
        std::cout << "Matrices can't be multiplied (or at least not in that order)!" << std::endl;
        return nullptr;
    }

    resultMatrixRows = matrixOneRows;
    resultMatrixCols = matrixTwoCols;

    int** resultMatrix = new int* [resultMatrixRows];
    for (int i = 0; i < resultMatrixRows; i++) {
        resultMatrix[i] = new int[resultMatrixCols];
    }
           
    int currentSum = 0;

    for (int i = 0; i < matrixOneRows; i++) {
        for (int j = 0; j < matrixTwoCols; j++) {
            for (int s = 0; s < matrixOneCols; s++) {
                currentSum += matrixOne[i][s] * matrixTwo[s][j];
            }

            resultMatrix[i][j] = currentSum;
            currentSum = 0;
        }
    }

    return resultMatrix;
}

void writeMatrixInFile(std::ofstream& out, int** matrix, const size_t rows, const size_t cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            out << matrix[i][j];

            if (j != cols - 1) {
                out << GLOBAL_CONSTANTS::COL_SEPARATOR;
            }  
        }
        if (i != rows - 1) {
            out << GLOBAL_CONSTANTS::ROW_SEPARATOR;
        }
    }
}

int main()
{
    std::ifstream in1(GLOBAL_CONSTANTS::firstFileName, std::ios::in);
    if (!in1.is_open()) {
        return -1;
    }

    std::ifstream in2(GLOBAL_CONSTANTS::secondFileName, std::ios::in);
    if (!in1.is_open()) {
        in1.close();
        return -1;
    }

    size_t matrixOneRows = 0, matrixOneCols = 0;
    getMatrixDimensions(in1, matrixOneRows, matrixOneCols);
    int** matrixOne = new int* [matrixOneRows];
    for (int i = 0; i < matrixOneRows; i++) {
        matrixOne[i] = new int[matrixOneCols];
    }
    initMatrix(in1, matrixOne);

    size_t matrixTwoRows = 0, matrixTwoCols = 0;
    getMatrixDimensions(in2, matrixTwoRows, matrixTwoCols);
    int** matrixTwo = new int* [matrixTwoRows];
    for (int i = 0; i < matrixTwoRows; i++) {
        matrixTwo[i] = new int[matrixTwoCols];
    }
    initMatrix(in2, matrixTwo);

    size_t resultMatrixRows = 0, resultMatrixCols = 0;
    int** resultMatrix = multiplyMatrices(matrixOne, matrixOneRows, matrixOneCols, matrixTwo, matrixTwoRows, matrixTwoCols, resultMatrixRows, resultMatrixCols);

    std::ofstream out(GLOBAL_CONSTANTS::outputFileName, std::ios::out);
    if (!out.is_open()) {
        return -1;
    }

    writeMatrixInFile(out, resultMatrix, resultMatrixRows, resultMatrixCols);

    in1.close();
    in2.close();
    out.close();

    freeMatrix(matrixOne, matrixOneRows);
    freeMatrix(matrixTwo, matrixTwoRows);
    freeMatrix(resultMatrix, resultMatrixRows);
}
