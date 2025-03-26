#pragma once

#include <cassert>
#include <vector>
#include <iostream>

class Matrix {
public:
    size_t Rows, Cols;
public:
    Matrix(size_t rows, size_t cols);

    unsigned int operator()(size_t row, size_t col) const;
    unsigned int& operator()(size_t row, size_t col);

    const std::vector<unsigned int>& GetRow(size_t index) const;
    std::vector<unsigned int>& GetRow(size_t index);

    void Print() const;

private:
    std::vector<std::vector<unsigned int>> m_Data;
};
