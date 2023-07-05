#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

// Первоначальная инициализация матриц.
void init_matrix(vector<vector<double>> &A, int &n)
{
    vector <double> B;
    for (int i = 0; i < n; i++)
    {
        A.push_back(B);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i].push_back(0);
        }
    }
}

// Считывание исходной матрицы из файла.
void scanf_matrix_file(vector<vector<double>> &A, int &n)
{
    ifstream in("matrix2.txt");
    in >> n;
    init_matrix(A, n);
    for (int i = 0; i < A[i].size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            in >> A[i][j];
        }
    }
    in.close();
}

// Очистка матриц.
void clear_matrix(vector<vector<double>> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size();)
        {
            A[i].pop_back();
        }
    }
    for (int i = 0; i < A.size();)
    {
        A.pop_back();
    }
}

// Удаление строки и столбца из матрицы
void removing_row_and_column_from_matrix(vector<vector<double>> &A, vector<vector<double>> &B,
                                         int n, int row, int column)
{

    int remove_row = 0;
    int remove_column = 0;
    for(int i = 0; i < n-1; i++)
    {
        if(i == row) {
            remove_row = 1;
        }
        remove_column = 0;
        for(int j = 0; j < n-1; j++)
        {
            if(j == column) {
                remove_column = 1;
            }
            B[i][j] = A[i + remove_row][j + remove_column];
        }
    }
}

// Вычисление определителя, разложением по строке
int matrix_det(vector<vector<double>> A, int n)
{
    int det = 0;
    int sign = 1;
    if(n == 1)
    {
        return A[0][0];
    }

    if(n == 2)
    {
        return A[0][0]*A[1][1] - A[0][1]*A[1][0];
    }
    vector<vector<double>> new_matrix;
    init_matrix(new_matrix, n);
    for(int i = 0; i < n; i++)
    {
        if(A[0][i] == 0)
            continue;
        else
        {
            removing_row_and_column_from_matrix(A, new_matrix, n, 0, i);
            det = det + (sign * A[0][i] * matrix_det(new_matrix, n-1));
        }
        sign = -sign;
    }
    clear_matrix(new_matrix);
    return det;
}

// Создание обратной матрицы.
void make_reverse_matrix(vector<vector<double>> A, vector<vector<double>> &B, int n)
{
    init_matrix(B, n);
    vector<vector<double>> matrix_minors;
    init_matrix(matrix_minors, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            removing_row_and_column_from_matrix(A, matrix_minors, n, i, j);
            B[j][i] = ((pow(-1, i + j + 2)) *
                       (matrix_det(matrix_minors, n - 1))) /
                      (matrix_det(A, n));
        }
    }
    clear_matrix(matrix_minors);
}

// Создание транспонированной матрицы.
void make_transposed_matrix(vector<vector<double>> A, vector<vector<double>> &B, int n)
{
    init_matrix(B, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            B[i][j] = A[j][i];
        }
    }
}

// Сравнение транспонированной матрицы и обратной.
bool orthogonal_or_not(vector<vector<double>> &A, vector<vector<double>> &B, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == B[i][j])
            {
                continue;
            }
            else
                return false;
        }
    }
    return true;
}

// Вывод матриц в консоль.
void write_matrix_console(vector<vector<double>> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "\n";
}
