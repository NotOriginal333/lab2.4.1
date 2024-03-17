#pragma once

#include <iostream>
#include <string>

class Matrix {
private:
    int** data;
    int size; 

public:
    Matrix(int size, int initialValue = 0);

    Matrix();

    Matrix(const Matrix& other);

    ~Matrix();

    int getSize() const;
    int getElement(int row, int col) const;
    void setElement(int row, int col, int value);

    Matrix operator*(int scalar) const;

    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    int calculateNorm() const;

    friend std::istream& operator>>(std::istream& is, Matrix& matrix);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

    int* operator[](int index);
private:
    void initializeMatrix(int initialValue);
};
