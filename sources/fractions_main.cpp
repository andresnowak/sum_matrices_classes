/*
@ Name: Andres Nowak
@ Date: Mon May 11 15:45:50 CDT 2020
*/

#include <utility>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <string>
#include <regex>

#include "../Headers/Fraction.h"
#include "../Headers/MatFrac.h"

using namespace std;

vector<vector<Fraction>> randomMatrix(unsigned int rows, unsigned int cols)
{
    vector<vector<Fraction>> matriz(rows, vector<Fraction>(cols));

    for (auto &row : matriz)
    {
        for (auto &col : row)
        {
            col = Fraction(rand() % 10 + 1, rand() % 10 + 1);
        }
    }

    return matriz;
}

vector<Fraction> getMatrixFromString(string text)
{
    pair<string, string> num_den = {"", ""};

    vector<Fraction> fraction;

    int pos_num_den = 0;

    for (char x : text)
    {
        if (x == ',' and num_den.first != "" and num_den.second != "")
        {
            fraction.push_back(Fraction(stoi(num_den.first), stoi(num_den.second)));

            pos_num_den = 0;

            num_den = {"", ""};
        }
        else if (x == '/')
        {
            pos_num_den = 1;
        }
        else if ((int(x) >= 48 and int(x) <= 57) or x == '+' or x == '-')
        {
            if (pos_num_den == 0)
            {
                num_den.first += x;
            }
            else
            {
                num_den.second += x;
            }
        }
    }

    return fraction;
}

void checkIfFileExists(ifstream &file)
{
    if (file.fail())
    {
        cerr << "File doesn't Exist" << endl;

        exit(0);
    }
    else
    {
        cout << "File exists" << endl;
    }
}

vector<vector<Fraction>> createMatrixFromFile(string name_of_doc)
{
    ifstream file(name_of_doc);

    checkIfFileExists(file);

    string text;

    vector<vector<Fraction>> fractions;

    vector<Fraction> fraction;

    while (getline(file, text))
    {
        fraction = getMatrixFromString(text);

        if (fraction.size())
        {
            fractions.push_back(fraction);
        }
    }

    return fractions;
}

void writeMatrixToFile(string name_of_doc, vector<vector<Fraction>> matrix)
{
    ofstream file(name_of_doc);

    for (auto &x : matrix)
    {
        for (auto &y : x)
        {
            file << y.getNumerator() << "/" << y.getDenominator() << ", ";
        }

        file << "\n";
    }
}

int main()
{
    string name_of_doc_1;
    string name_of_doc_2;

    string directory_matrices = "../matrices/";

    srand(time(NULL));

    cout << "introduzca el nombre de los archivos con extension(tiene que estar adentro de la carpeta matrices):" << endl;

    cout << "texto 1: ";
    cin >> name_of_doc_1;

    cout << "texto 2: ";
    cin >> name_of_doc_2;

    //para crear matrices random

    //writeMatrixToFile(directory_matrices + name_of_doc_1, randomMatrix(4, 4));
    //writeMatrixToFile(directory_matrices + name_of_doc_2, randomMatrix(4, 4));

    MatFrac matrix_1 = MatFrac(createMatrixFromFile(directory_matrices + name_of_doc_1));
    MatFrac matrix_2 = MatFrac(createMatrixFromFile(directory_matrices + name_of_doc_2));

    pair<MatFrac, bool> sum_matrices = matrix_1 + matrix_2;

    if (sum_matrices.second)
    {
        cout << "Ingrese el nombre del archivo para el resultados de suma de matrices: ";

        string name_of_doc_result;

        cin >> name_of_doc_result;

        writeMatrixToFile(directory_matrices + name_of_doc_result, sum_matrices.first.getMatrix());

        cout << matrix_1 << "\n"
             << "+"
             << "\n\n";

        cout << matrix_2 << "\n"
             << "="
             << "\n\n";

        cout << sum_matrices.first;
    }
}
