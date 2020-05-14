/*
@ Name: Andres Nowak
@ Date: Thu May 14 10:12:55 CDT 2020
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../Headers/Fraction.h"

using namespace std;

int Fraction::gcd(int a, unsigned int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

void Fraction::reduceFraction(int &numerator, unsigned int &denominator)
{
    int greatest_common_divisor = gcd(abs(numerator), denominator);

    numerator = numerator / greatest_common_divisor;
    denominator = denominator / greatest_common_divisor;
}

bool Fraction::checkDenominatorZero(int denominator)
{
    if (denominator)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Fraction::checkDenominatorNegative(int denominator)
{
    if (denominator < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Fraction::checkNumeratorNegative(int numerator)
{
    if (numerator < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Fraction::changeDenominatorValue(int &numerator, int &denominator)
{
    if (checkDenominatorZero(denominator))
    {
        cerr << "You can't put a 0 for a denominator, so we changed your 0 to a 1."
             << "\n";

        denominator = 1;
    }
    else if (checkDenominatorNegative(denominator))
    {
        if (checkNumeratorNegative(numerator))
        {
            numerator = abs(numerator);
            denominator = abs(denominator);
        }
        else
        {
            numerator = -numerator;
            denominator = abs(denominator);
        }
    }
}

Fraction::Fraction(int numerator, int denominator)
{
    changeDenominatorValue(numerator, denominator);

    unsigned int denominator_unsigned = denominator;

    reduceFraction(numerator, denominator_unsigned);

    this->_numerator = numerator;
    this->_denominator = denominator_unsigned;
}

Fraction::Fraction()
{
    this->_numerator = 0;
    this->_denominator = 1;
}

Fraction Fraction::sumFractions(Fraction fraccion_2)
{
    unsigned int denominator_2 = fraccion_2.getDenominator();

    unsigned int common_denominator = this->_denominator * denominator_2;

    int numerator_1 = this->_numerator * (common_denominator / this->_denominator);
    int numerator_2 = fraccion_2.getNumerator() * (common_denominator / denominator_2);

    int sum_numerators = numerator_1 + numerator_2;

    reduceFraction(sum_numerators, common_denominator);

    return Fraction(sum_numerators, common_denominator);
}

Fraction Fraction::multiplyFractions(Fraction fraccion_2)
{
    unsigned int denominator_2 = fraccion_2.getDenominator();
    int numerator_2 = fraccion_2.getNumerator();

    unsigned int multiply_denominators = this->_denominator * denominator_2;
    int multiply_numerators = this->_numerator * numerator_2;

    reduceFraction(multiply_numerators, multiply_denominators);

    return Fraction(multiply_numerators, multiply_denominators);
}

void Fraction::printFractions(bool new_line)
{
    cout << this->_numerator << "/" << this->_denominator;

    if (new_line == true)
    {
        cout << endl;
    }
}

int Fraction::getDenominator()
{
    return this->_denominator;
}

int Fraction::getNumerator()
{
    return this->_numerator;
}