/*
@ Name: Andres Nowak
@ Date: Mon May 11 16:00:56 CDT 2020
*/

#include <vector>
#include <string>

#include "Fraction.h"

using namespace std;

#ifndef MATFRAC_H
#define MATFRAC_H

class MatFrac
{
private:
    vector<vector<Fraction>> _fractions;
    int size_cols;
    int size_rows;

    bool checkMatricesHaveSameSizes(MatFrac fractions_matrix_2);
    bool checkItsAMatrix(vector<vector<Fraction>> matrix);
    bool chechItsAValidMatrix(vector<vector<Fraction>> matrix);

public:
    MatFrac(vector<vector<Fraction>> fractions);

    pair<MatFrac, bool> sumMatrices(MatFrac fractions_matrix_2);

    void printMatrix();

    vector<vector<Fraction>> getMatrix();
};

#endif // MATFRAC_H