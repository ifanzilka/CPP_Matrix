#include "CPP_Matrix.hpp"

namespace ft
{
    /* Constructors */
    Matrix::Matrix()
    {
        _rows = 0;
        _cols = 0;
    }

    Matrix::Matrix(int rows, int cols)
    {
        if (rows <= 0 || cols <= 0)
        {
            throw std::out_of_range("Invalid size of rows or columns");
        }
        _rows = rows;
        _cols = cols;
        create_matrix();
    }


    /* Destructors */
    Matrix::~Matrix()
    {
        clear_matrix();
    }

    /* utils */

    void Matrix::create_matrix()
    {
        if (!this->_rows || !this->_cols)
            throw std::length_error("Rows is less or equal 0");
        this->_matrix = new double *[_rows];
  
  
        for (int i = 0; i < _rows; i++)
        {
            _matrix[i] = new double[_cols];
        }

        /* zero */
        for (int i = 0; i < _rows; i++)
        {
            for (int j = 0; j < _cols; j++)
            {
                _matrix[i][j] = 0;
            }
        }
    }


    void Matrix::clear_matrix()
    {
        if (this->_matrix)
        {
            if (this->_rows && this->_cols)
            {
                for (int i = 0; i < this->_rows; i++)
                {
                    delete[] _matrix[i];
                }
                delete[] _matrix;
            }
        }
    }


    bool Matrix::EqMatrix(const ft::Matrix& other)
    {
        bool result = true;
        if (this->_rows != other._rows || this->_cols != other._cols)
        {
            result = false;
            throw std::out_of_range("Incorrect input, matrices should have the same size");
        } else if ((this->_rows < 0 || this->_cols < 0) && (other._rows < 0 || other._cols < 0))
        {
            result = false;
            throw std::out_of_range("Incorrect input, size cannot be less than zero");
        }
        else
        {
            for (int i = 0; i < this->_rows; i++)
            {
                for (int j = 0; j < this->_cols; j++)
                {
                    if (std::fabs(this->_matrix[i][j] - other._matrix[i][j]) > 1e-07)
                        result = false;
                }
            }
        }
        return result;
    }

}