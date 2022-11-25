#ifndef CPP_MATRIX_HPP
# define CPP_MATRIX_HPP

#include <cmath>
#include <cstring>
#include <iostream>

namespace ft
{
    class Matrix
    {
    private:
       
        int _rows, _cols;         // Rows and columns
        double **_matrix;         // Pointer to the memory where the matrix is allocated

    protected:
        void    create_matrix();
        void    clear_matrix();

    public:

        /* Constructors */
        Matrix();                    
        Matrix(int rows, int cols);

        /* Finctional */
        bool    EqMatrix(const ft::Matrix& other);
        void    SumMatrix(const Matrix& other);
        void    SubMatrix(const Matrix& other);
        void    MulNumber(const double num);
        void    MulMatrix(const Matrix& other);
        Matrix  T();
        Matrix  Transpose();
        Matrix  CalcComplements();
        double  Determinant();
        Matrix  InverseMatrix();


        /* Destructors */
        ~Matrix();

    };

}

#endif