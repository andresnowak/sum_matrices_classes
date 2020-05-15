/*
@ Name: Andres Nowak
@ Date: Thu May 14 10:57:45 CDT 2020
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../Headers/Fraction.h"
#include "../Headers/MatFrac.h"

using namespace std;

bool MatFrac::checkMatricesHaveSameSizes(MatFrac fractions_matrix_2)
{
    vector<vector<Fraction>> fractions_2 = fractions_matrix_2.getMatrix();

    int size_rows_2 = fractions_2.size();

    if (this->size_rows != size_rows_2)
    {
        return false;
    }

    for (int row = 0; row < this->size_rows; row++)
    {
        if (this->_fractions[row].size() != fractions_2[row].size())
        {
            return false;
        }
    }

    return true;
}

bool MatFrac::checkItsAMatrix(vector<vector<Fraction>> matrix)
{
    int size_of_rows = matrix.size();

    if (size_of_rows == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool MatFrac::chechItsAValidMatrix(vector<vector<Fraction>> matrix)
{
    int size_of_cols = matrix[0].size();
    int size_of_rows = matrix.size();

    if (size_of_cols == 0)
    {
        return false;
    }

    for (int i = 0; i < size_of_rows; i++)
    {
        int size_col_actual = matrix[i].size();

        if (size_col_actual != size_of_cols)
        {
            return false;
        }
    }

    return true;
}

MatFrac::MatFrac(vector<vector<Fraction>> fractions)
{
    if (!checkItsAMatrix(fractions))
    {
        cerr << "Not a valid matrix, it doesn't have any rows" << endl;

        exit(0); // talvez se puede hacer diferente
        return;
    }
    else if (!chechItsAValidMatrix(fractions))
    {
        cerr << "Not a valid matrix" << endl;

        exit(0); // talvez se puede hacer diferente
        return;
    }

    this->_fractions = fractions;

    this->size_rows = this->_fractions.size();
    this->size_cols = this->_fractions[0].size();
}

pair<MatFrac, bool> MatFrac::operator+(MatFrac fractions_matrix_2)
{
    vector<vector<Fraction>> fractions_2 = fractions_matrix_2.getMatrix();

    vector<vector<Fraction>> sum_fractions(size_rows, vector<Fraction>(size_cols));

    if (!checkMatricesHaveSameSizes(fractions_matrix_2))
    {
        cerr << "Operacion imposible" << endl;

        return make_pair(MatFrac({{Fraction()}}), false);
    }

    for (int row = 0; row < size_rows; row++)
    {
        for (int col = 0; col < size_cols; col++)
        {
            sum_fractions[row][col] = this->_fractions[row][col] + fractions_2[row][col];
        }
    }

    return make_pair(MatFrac(sum_fractions), true);
}

ostream &operator<<(ostream &output, const MatFrac &matrix)
{
    for (auto row : matrix._fractions)
    {
        for (auto col : row)
        {
            output << col << " ";
        }

        output << "\n";
    }

    return output;
}

vector<vector<Fraction>> MatFrac::getMatrix()
{
    return this->_fractions;
}
