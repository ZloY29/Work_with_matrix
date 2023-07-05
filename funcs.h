#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

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
    ifstream in("matrix.txt");
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

// Возведение матрицы в куб.
void matrix_in_funcs_kube(vector<vector<double>> &A, vector<vector<double>> &B,
                          vector<vector<double>> &C, int &n)
{
    init_matrix(B, n);
    init_matrix(C, n);
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            double term = 0;
            for (int k = 0; k < A.size(); k++)
            {
                term += A[i][k] * A[k][j];
            }
            B[i][j] = term;
        }
    }
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            double term = 0;
            for (int k = 0; k < A.size(); k++)
            {
                term += A[i][k] * B[k][j];
            }
            C[i][j] = term;
        }
    }
}

// Возведение матрицы в квадрат.
void matrix_in_square(vector<vector<double>> &A, vector<vector<double>> &B, int &n)
{
    init_matrix(B, n);
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            double term = 0;
            for (int k = 0; k < A.size(); k++)
            {
                term += A[i][k] * A[k][j];
            }
            B[i][j] = term;
        }
    }
}

// Умножение матрицы на число.
void multy_elem_matrix(vector<vector<double>> &A, int &n, int num)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = num * A[i][j];
        }
    }
}

// Создание единичной матрицы.
void make_singular_matrix(vector<vector<double>> &A, int &n)
{
    init_matrix(A, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == j)
                A[i][j] = 1;
            else
                A[i][j] = 0;
        }
    }
}

// Сумма матриц.
void sum_of_matrix(vector<vector<double>> &A, vector<vector<double>> &B, int &n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] += B[i][j];
        }
    }
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