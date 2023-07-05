#include "funcs2.h"

int main()
{
    int matrix_size;
    vector<vector<double>> Matrix;
    vector<vector<double>> Matrix_reverse;
    vector<vector<double>> Matrix_transposed;

    scanf_matrix_file(Matrix, matrix_size);
    make_reverse_matrix(Matrix, Matrix_reverse, matrix_size);
    make_transposed_matrix(Matrix, Matrix_transposed, matrix_size);

    cout << "Исходная матрица:" << '\n';
    write_matrix_console(Matrix);

    cout << "Обратная матрица:" << '\n';
    write_matrix_console(Matrix_reverse);

    cout << "Транспонированная матрица:" << '\n';
    write_matrix_console(Matrix_transposed);

    if (orthogonal_or_not(Matrix_reverse, Matrix_transposed, matrix_size))
        cout << "Исходная матрица является ортогональной!" << '\n';
    else
        cout << "Исходная матрица не является ортогональной!" << '\n';

    clear_matrix(Matrix);
    clear_matrix(Matrix_reverse);
    clear_matrix(Matrix_transposed);
    return 0;
}