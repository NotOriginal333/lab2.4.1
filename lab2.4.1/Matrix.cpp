#include "Matrix.h"
#include <stdexcept>

Matrix::Matrix(int size, int initialValue) : size(size) {
    initializeMatrix(initialValue);
}

Matrix::Matrix() : size(0), data(nullptr) {}

Matrix::Matrix(const Matrix& other) : size(other.size) {
    initializeMatrix(0); 

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = other.data[i][j]; 
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < size; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

int Matrix::getSize() const {
    return size;
}

int Matrix::getElement(int row, int col) const {
    if (row < 0 || row >= size || col < 0 || col >= size) {
        throw std::out_of_range("Matrix index out of range");
    }
    return data[row][col];
}

void Matrix::setElement(int row, int col, int value) {
    if (row < 0 || row >= size || col < 0 || col >= size) {
        throw std::out_of_range("Matrix index out of range");
    }
    data[row][col] = value;
}

Matrix Matrix::operator*(int scalar) const {
    Matrix result(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] * scalar; 
        }
    }

    return result;
}

bool Matrix::operator==(const Matrix& other) const {
    if (size != other.size) {
        return false;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

int Matrix::calculateNorm() const {
    int max = data[0][0];
    int min = data[0][0];

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (data[i][j] > max) {
                max = data[i][j];
            }
            if (data[i][j] < min) {
                min = data[i][j];
            }
        }
    }

    return max - min; 
}

std::istream& operator>>(std::istream& is, Matrix& matrix) {
    std::cout << "Enter the size of the matrix: ";
    is >> matrix.size;

    matrix.initializeMatrix(0);
    std::cout << "Enter the elements of the matrix:" << std::endl;
    for (int i = 0; i < matrix.size; ++i) {
        for (int j = 0; j < matrix.size; ++j) {
            is >> matrix.data[i][j];
        }
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.size; ++i) {
        for (int j = 0; j < matrix.size; ++j) {
            os << matrix.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

void Matrix::initializeMatrix(int initialValue) {
    data = new int* [size];
    for (int i = 0; i < size; ++i) {
        data[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            data[i][j] = initialValue; 
        }
    }
}

int* Matrix::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Matrix index out of range");
    }
    return data[index];
}