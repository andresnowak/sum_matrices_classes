/*
@ Name: Andres Nowak
@ Date: Mon May 11 15:59:48 CDT 2020
*/

#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:
    int _numerator;
    unsigned _denominator;

    int gcd(int a, unsigned int b);

    void reduceFraction(int &numerator, unsigned int &denominator);

    bool checkDenominatorZero(int denominator);
    bool checkDenominatorNegative(int denominator);
    bool checkNumeratorNegative(int numerator);

    void changeDenominatorValue(int &numerator, int &denominator);

public:
    Fraction(int numerator, int denominator);
    Fraction();

    Fraction sumFractions(Fraction fraccion_2);
    Fraction multiplyFractions(Fraction fraccion_2);

    void printFractions(bool new_line = false);

    int getDenominator();
    int getNumerator();
};

#endif // FRACTION_H