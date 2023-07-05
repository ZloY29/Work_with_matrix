#include "funcs.h"

int main()
{
    int matrix_size;
    vector<vector<double>> Matrix;
    vector<vector<double>> Matrix_square;
    vector<vector<double>> Buff_matrix;
    vector<vector<double>> Matrix_funcs_cube;
    vector<vector<double>> Matrix_funcs_square;
    vector<vector<double>> Singular_matrix;

    scanf_matrix_file(Matrix, matrix_size);
    cout << "Изначальная матрица:" << "\n";
    write_matrix_console(Matrix);

    matrix_in_square(Matrix, Matrix_square, matrix_size);
    cout << "Возведем изначальную матрицу в квадрат:" << "\n";
    write_matrix_console(Matrix_square);

    matrix_in_funcs_kube(Matrix_square, Buff_matrix, Matrix_funcs_cube, matrix_size);
    cout << "Возведем полученную матрицу еще в куб:" << "\n";
    write_matrix_console(Matrix_funcs_cube);

    matrix_in_square(Matrix_square, Matrix_funcs_square, matrix_size);
    cout << "Также возведем полученную матрицу в квадрат:" << "\n";
    write_matrix_console(Matrix_funcs_square);

    multy_elem_matrix(Matrix_funcs_square, matrix_size, -10);
    cout << "И умножим ее на -10:" << "\n";
    write_matrix_console(Matrix_funcs_square);

    multy_elem_matrix(Matrix_square, matrix_size, 7);
    cout << "Также умножим полученную матрицу на 7:" << "\n";
    write_matrix_console(Matrix_square);

    make_singular_matrix(Singular_matrix, matrix_size);
    multy_elem_matrix(Singular_matrix, matrix_size, -12);
    cout << "Также создадим единичную матрицу и умножим ее на -12:" << "\n";
    write_matrix_console(Singular_matrix);

    sum_of_matrix(Matrix_funcs_cube, Matrix_funcs_square, matrix_size);
    sum_of_matrix(Matrix_funcs_cube, Matrix_square, matrix_size);
    sum_of_matrix(Matrix_funcs_cube, Singular_matrix, matrix_size);

    cout << "Ну и наконец произведем вычисления получившегося у нас добра:" << "\n";
    write_matrix_console(Matrix_funcs_cube);

    clear_matrix(Matrix);
    clear_matrix(Matrix_square);
    clear_matrix(Buff_matrix);
    clear_matrix(Matrix_funcs_cube);
    clear_matrix(Matrix_funcs_square);
    clear_matrix(Singular_matrix);
    return 0;
}