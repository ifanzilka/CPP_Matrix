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
        bool    EqMatrix(const Matrix& other) const;
        void    SumMatrix(const Matrix& other);
        void    SubMatrix(const Matrix& other);
        void    MulNumber(const double num);
        void    MulMatrix(const Matrix& other);

        Matrix  Transpose();
        Matrix  MinorMinor(int row, int col);
        double  Determinant();
        Matrix  CalcComplements();
        Matrix  InverseMatrix();


        /* Сеттеры */
        void SetRows(int rows);
        void SetCols(int cols);

        /* Getters */
        int GetRows() const;
        int GetCols() const;





        /* operators  */

        Matrix operator+(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;
        friend Matrix operator*(const double num, const Matrix& other);
        Matrix operator*(const double num) const;
        bool operator==(const Matrix& other) const;
        void operator+=(const Matrix& other);
        void operator-=(const Matrix& other);
        void operator*=(const Matrix& other);
        void operator*=(const double num);
        Matrix& operator=(const Matrix& other);
        double& operator()(int i, int j);
        double  operator()(int i, int j) const;


        /* Destructors */
        ~Matrix();

    };

}

#endif