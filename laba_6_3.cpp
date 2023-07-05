#include "funcs3.h"

int main()
{
    int matrix_size = 2;
    vector<vector<double>> Matrix_first;
    vector<vector<double>> Matrix_second;
    vector<vector<double>> Matrix_X;
    vector<vector<double>> Matrix_Y;
    vector<vector<double>> Matrix_checker;

    init_matrix(Matrix_first, matrix_size);
    init_matrix(Matrix_second, matrix_size);
    init_matrix(Matrix_X, matrix_size);
    init_matrix(Matrix_Y, matrix_size);
    init_matrix(Matrix_checker, matrix_size);
    matrix_first_and_second_input(Matrix_first, Matrix_second);

    cout << "Домножив верхнее уравнение системы на 2 и прибавив к нему" << '\n';
    cout << "нижнее получаю уравнение Х = (2 * mat_first + mat_second) / 5" << '\n';
    find_matrix_x(Matrix_first, Matrix_second, Matrix_X);

    cout << "Подставив Х в верхнее уравнение и перенеся 2 * Х направо" << '\n';
    cout << "со знаком минус получаю уравнение Y = mat_first - 2 * X" << '\n';
    find_matrix_y(Matrix_first, Matrix_X, Matrix_Y);

    cout << "Подставив Х и Y в нижнее уравнение получаю матрицу чекера." << '\n';
    make_matrix_checker(Matrix_X, Matrix_Y, Matrix_checker);

    if (good_or_not(Matrix_second, Matrix_checker))
        cout << "Все посчитано правильно!" << '\n';
    else
        cout << "Все посчитано не правильно!" << '\n';

    clear_matrix(Matrix_first);
    clear_matrix(Matrix_second);
    clear_matrix(Matrix_X);
    clear_matrix(Matrix_Y);
    clear_matrix(Matrix_checker);
    return 0;
}