#include "includes/CPP_Matrix.hpp"



void fill_matrix(ft::Matrix &A, int rows, int cols)
{

    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < cols; j++)
        {
            double num;
            std::cin >> num;
            A(i, j) = num;
        }
    }

    
}

void print_matrix(ft::Matrix &A, int rows, int cols)
{

    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < cols; j++)
        {
            std::cout << A(i, j) << " ";
        }
        std::cout <<"\n";
    }

    
}


int main()
{
    ft::Matrix A(3, 3);
    ft::Matrix B(3, 3);


    fill_matrix(A, 3, 3);

    std::cout << A.Determinant() << std::endl;

    ft::Matrix obr = A.InverseMatrix();
    
    
    print_matrix(obr, 3, 3);
    
    ft::Matrix res = A * obr; 
    print_matrix(res, 3, 3);
    while (1)
        ;

    // for (int i = 0; i < 3; i++)
    // {

    //     for (int j = 0; j < 3; j++)
    //     {
    //         if (i == j)
    //         {
    //             A(i, j) = 1;
    //             B(i, j) = 1;
    //         }
    //     }
    // }

    // A.SumMatrix(B);

    // for (int i = 0; i < 3; i++)
    // {

    //     for (int j = 0; j < 3; j++)
    //     {
    //         std::cout << A(i, j)  << " ";
    //     }
    //     std::cout << std::endl;
   // }

    return (0);
}