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
        void    AllocateMatrix(int cols, int rows);
        void    FreeMatrix();
        void    CopyMatrix(const Matrix& other);

    public:

        /* Constructors */
        Matrix();                    
        Matrix(int rows, int cols);
        Matrix(const Matrix& other);
        //Matrix(Matrix&& other);

        /* Finctional */
        bool    EqMatrix(const ft::Matrix& other);
        void    SumMatrix(const Matrix& other);
        void    SubMatrix(const Matrix& other);
        void    MulNumber(const double num);
        void    MulMatrix(const Matrix& other);

        Matrix  Transpose();
        Matrix  MinorMinor(int row, int col);
        double  Determinant();
        Matrix  CalcComplements();
        Matrix  InverseMatrix();


        /* operators  */

        Matrix& operator=(const Matrix& other);

        double& operator()(int i, int j);
        double  operator()(int i, int j) const;


        /* Destructors */
        ~Matrix();

    };

}

#endif