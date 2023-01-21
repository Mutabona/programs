#include <iostream>
#include <stdlib.h>
#include <new>

class Matrix{
    public:
    int rows;
    int columns;
    double *data = NULL;
    Matrix(const int& rows_, const int& columns_): rows(rows_), columns(columns_) {
        if (rows_ <= 0 || columns_ <=0) {
            std::cout<<"Wrong size of matrix";
            exit(1);
        }
        try {
            data = new double[rows*columns];
        }
        catch (std::bad_alloc& ex) {
            std::cout<<"Wrong size of matrix";
            exit(1);
        }
    }
    Matrix(const Matrix& mat): rows(mat.rows), columns(mat.columns) {
        try {
            data = new double[rows*columns];
        }
        catch (std::bad_alloc& ex) {
            std::cout<<"Wrong size of matrix";
            exit(1);
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                data[i*columns+j] = mat.data[i*columns+j];
            }
        }
    }
    ~Matrix() {
        delete[] data;
    }
};

std::ostream& operator<<(std::ostream& out, Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.columns; j++) {
            out<<mat.data[i * mat.columns+j]<<' ';
        }
        out<<'\n';
    }
    return out;
}

