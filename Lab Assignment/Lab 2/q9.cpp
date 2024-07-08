// Create a 'MATRIX' class of size m X n. Overload the ‘+’ operator to
// Add Two MATRIX objects. Write a main function to implement it.

#include <iostream>
using namespace std;

class MATRIX
{
private:
    int **mat;
    int rows;
    int cols;

public:
    MATRIX(int r, int c) : rows(r), cols(c)
    {
        mat = new int *[rows];
        for (int i = 0; i < rows; ++i)
        {
            mat[i] = new int[cols]();
        }
    }

    MATRIX(const MATRIX &other) : rows(other.rows), cols(other.cols)
    {
        mat = new int *[rows];
        for (int i = 0; i < rows; ++i)
        {
            mat[i] = new int[cols];
            for (int j = 0; j < cols; ++j)
            {
                mat[i][j] = other.mat[i][j];
            }
        }
    }

    // Destructor
    ~MATRIX()
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] mat[i];
        }
        delete[] mat;
    }

    void input()
    {
        cout << "Enter elements for a " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> mat[i][j];
            }
        }
    }

    void display()
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    MATRIX operator+(MATRIX other)
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Matrices dimensions do not match for addition.";
            exit(1);
        }

        MATRIX result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }
};

int main()
{
    int rows, cols;
    cout << "Enter the number of rows and columns for the matrices: ";
    cin >> rows >> cols;

    MATRIX mat1(rows, cols);
    MATRIX mat2(rows, cols);

    cout << "Input for matrix 1:" << endl;
    mat1.input();
    cout << "Input for matrix 2:" << endl;
    mat2.input();

    MATRIX result = mat1 + mat2;
    cout << "Resultant matrix after addition:" << endl;
    result.display();

    return 0;
}
