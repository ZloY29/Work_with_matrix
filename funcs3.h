#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

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

// Ввод матриц из верхнего и нижнего уравнений системы.
void matrix_first_and_second_input(vector<vector<double>> &A, vector<vector<double>> &B)
{
    A[0][0] = 5;
    A[0][1] = 3;
    A[1][0] = -1;
    A[1][1] = -1;
    B[0][0] = -5;
    B[0][1] = -6;
    B[1][0] = -3;
    B[1][1] = 2;
    cout << "Матрица из верхнего уравнения:" << '\n';
    write_matrix_console(A);
    cout << "Матрица из нижнего уравнения:" << '\n';
    write_matrix_console(B);
}

// Нахождение матрицы X.
void find_matrix_x(vector<vector<double>> &A, vector<vector<double>> &B, vector<vector<double>> &C)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            C[i][j] = ((2 * A[i][j] + B[i][j]) / 5);
        }
    }
    cout << "\nМатрица X:" << '\n';
    write_matrix_console(C);
}

// Нахождение матрицы Y.
void find_matrix_y(vector<vector<double>> &A, vector<vector<double>> &B, vector<vector<double>> &C)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            C[i][j] = A[i][j] - 2 * B[i][j];
        }
    }
    cout << "\nМатрица Y:" << '\n';
    write_matrix_console(C);
}

// Создание матрицы проверки правильности вычислений.
void make_matrix_checker(vector<vector<double>> &A, vector<vector<double>> &B, vector<vector<double>> &C)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            C[i][j] = A[i][j] - 2 * B[i][j];
        }
    }
    cout << "\nМатрица чекера:" << '\n';
    write_matrix_console(C);
}

// Сравнение полученной матрицы с исходной.
bool good_or_not(vector<vector<double>> &A, vector<vector<double>> &B)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
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