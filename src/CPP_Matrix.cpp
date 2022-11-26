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

    void Matrix::SumMatrix(const Matrix& other)
    {
        if (this->_rows != other._rows || this->_cols != other._cols)
        {
            throw std::out_of_range("Incorrect input, matrices should have the same size");
        }
        else if (this->_matrix == nullptr && other._matrix == nullptr)
        {
            throw std::out_of_range("Incorrect input, matrix empty");
        }
        else
        {
            for (int i = 0; i < this->_rows; i++)
            {
                for (int j = 0; j < this->_cols; j++)
                {
                    this->_matrix[i][j] += other._matrix[i][j];
                }
            }
        }

    }

    void Matrix::SubMatrix(const Matrix& other)
    {
        if (this->_rows != other._rows || this->_cols != other._cols)
        {
            throw std::out_of_range("Incorrect input, matrices should have the same size");
        }
        else if (this->_matrix == nullptr && other._matrix == nullptr)
        {
            throw std::out_of_range("Incorrect input, matrix empty");
        }
        else
        {
            for (int i = 0; i < this->_rows; i++)
            {
                for (int j = 0; j < this->_cols; j++)
                {
                    this->_matrix[i][j] -= other._matrix[i][j];
                }
            }
        }
        
    }


    void Matrix::MulNumber(const double num)
    {

        for (int i = 0; i < this->_rows; i++)
        {
            for (int j = 0; j < this->_cols; j++)
            {
                this->_matrix[i][j] *= num;
            }
        }
        
    }

    void Matrix::MulMatrix(const Matrix& other)
    {
        if (this->_rows != other._cols)
        {
            throw std::out_of_range("the number of rows of the first matrix must be equal to the number of "
            "columns of the second matrix");
        }
        else if (!this->_matrix || !other._matrix)
        {
            throw std::out_of_range("Incorrect input, matrix empty");
        }
        else
        {
            Matrix result(other._cols, this->_rows);
            for (int i = 0; i < this->_rows; i++)
            {
                for (int j = 0; j < other._cols; j++)
                {
                    for (int k = 0; k < this->_cols; k++)
                    {
                        result._matrix[i][j] += this->_matrix[i][k] * other._matrix[k][j];
                    }
                }
            }
            for (int i = 0; i < this->_rows; i++)
            {
                for (int j = 0; j < other._cols; j++)
                {
                    this->_matrix[i][j] = result._matrix[i][j];
                }
            }
        }
    }

    Matrix  Matrix::Transpose()
    {
        Matrix result(_rows, _cols);
        
        for (int i = 0; i < _rows; i++)
        {
            for (int j = 0; j < _cols; j++)
            {
                result._matrix[j][i] = _matrix[i][j];
            }
        }
        return (result);
    }

    Matrix  Matrix::MinorMinor(int row, int col)
    {
        Matrix result(this->_rows - 1, this->_cols - 1);

        for (int i = 0, x = 0; i < this->_rows; ++i)
        {
            if (row != i)
            {
                for (int j = 0, y = 0; j < this->_cols; ++j)
                {
                    if (col != j)
                    {
                        result._matrix[x][y] = this->_matrix[i][j];
                        y++;
                    }
                }
                x++;   
            }
        }
        return (result);
    }

    double  Matrix::Determinant()
    {
        Matrix minor;
        double result = 0;
        double determinant_minor;

        if ((_cols < 1 || _rows < 1) || (_rows != _cols))
        {
            throw std::out_of_range("Incorrect input");
        }
        if (_cols == 1)
        {
            return (_matrix[0][0]);
        }
        else
        {
            for (int i = 0; i < this->_cols; i++)
            {
                minor = MinorMinor(i, 0);  // чтобы не брать [i][0] элемент, то есть первые элементы строки
                determinant_minor = minor.Determinant();

                determinant_minor = this->_matrix[i][0] * determinant_minor;

                if ((2 + i) % 2 == 1)
                    determinant_minor *= (-1);

                /* res = (-1)^(i)  + det(minor(i, i))*/
                result += determinant_minor;                
            }
        }

        return (result);

    }



    Matrix  Matrix::CalcComplements()
    {
        Matrix result(_rows, _cols);

        if ((_rows != _cols) || _rows < 1 || _cols < 1)
        {
            throw std::out_of_range("Incorrect input");
        }
        for (int i = 0; i < _rows; i++)
        {
            for (int j = 0; j < _cols; j++)
            {
                double determinant = 0.0;
                minor = MinorMinor(i, j);
                determinant = minor.determinant();
                result._matrix[i][j] = pow(-1, i + j) * determinant;
            }
        }
        return (result);
    }
}