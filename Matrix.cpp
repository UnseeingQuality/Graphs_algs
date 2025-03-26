#include <Matrix.h>

Matrix::Matrix(size_t rows, size_t cols) : Rows(rows), Cols(cols),
    m_Data(rows, std::vector<unsigned int>(cols, 0)) {
}

unsigned int& Matrix::operator()(size_t row, size_t col) {
    if (row >= Rows || col >= Cols) {
        assert(false);
    }
    return m_Data[row][col];
}

const std::vector<unsigned int>& Matrix::GetRow(size_t index) const {
    if (index >= m_Data.size()) {
        std::cout << "Index is incorrect" << std::endl;
        assert(false);
    }
    return m_Data[index];
}

std::vector<unsigned int>& Matrix::GetRow(size_t index) {
    if (index >= m_Data.size()) {
        std::cout << "Index is incorrect" << std::endl;
        assert(false);
    }
    return m_Data[index];
}

unsigned int Matrix::operator()(size_t row, size_t col) const {
    if (row >= Rows || col >= Cols) {
        assert(false);
    }
    return m_Data[row][col];
}

void Matrix::Print() const {
    for (const std::vector<unsigned int>& row : m_Data) {
        std::cout << "[";
        for (const unsigned int element : row) {
            std::cout << element << " ";
        }
        std::cout << "]" << std::endl;
    }
}
