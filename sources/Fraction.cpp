/**
 * @brief this file contains the Fraction implementations; ssignment 3, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @since 15/04/2023
*/


#include <iostream>
#include <stdexcept>
#include "Fraction.hpp"

using namespace std;

namespace ariel
{
    /**
     * @brief this function calculates the greatest common divison of two integers
     * @param a first integer
     * @param b second integer
     * @return gcd(a,b)
    */
    int GCD(int a, int b)
    {
        int r = 0;
        while(b != 0)
        {
            r = (a % b);
            a = b;
            b = r;
        }

        return a;
    }

    /**
     * @brief this is a constructor to create a standard object from two integers
     * @param numerator fraction upper value
     * @param denominator fraction lower value
    */
    Fraction::Fraction(int numerator, int denominator) : _numerator(numerator), _denominator(denominator)
    {
        if(denominator == 0)
        {
            throw invalid_argument("/ by 0");
        }
        else
        {
            this->_numerator = numerator;
            this->_denominator = denominator;
        }
    }

    /**
     * @brief this operator adds two fractions
     * @param other second fraction to add to current fraction
     * @return the result of adding both fractions
    */
    Fraction Fraction::operator+(const Fraction &other)
    {
        int numerator = 0, denominator = 0, gcd = 0;

        numerator = (this->_numerator * other._denominator) + (this->_denominator * other._numerator);
        denominator = this->_denominator * other._denominator;
        gcd = GCD(numerator, denominator);

        numerator /= gcd;
        denominator /= gcd;

        return Fraction(numerator, denominator);
    }

    /**
     * @brief this operator adds float with fraction
     * @param x float to add
     * @param other fraction to add
     * @return x + other as float
    */
    float operator+(float x, const Fraction &other)
    {
        return (((other._numerator) + (x * other._denominator)) / (other._denominator));
    }

    /**
     * @brief this operator adds fraction with float
     * @param other fraction to add
     * @param x float to add
     * @return other + x as float
    */
    float operator+(const Fraction &other, float x)
    {
        return (x + other);   
    }

    /**
     * @brief this operator subtracts two fractions
     * @param other fraction to subtruct from currect fruction
     * @return the result of subtracting both fractions
    */
    Fraction Fraction::operator-(const Fraction &other)
    {
        return this->operator+(Fraction((-1 * other._numerator), other._denominator));
    }

    /**
     * @brief this operator subtracts float and fraction
     * @param x float from subtract
     * @param other fraction to subtract
     * @return x - other as float
    */
    float operator-(float x, const Fraction &other)
    {
        return x + Fraction((-1 * other._numerator), other._denominator);
    }

    /**
     * @brief this operator subtracts float and fraction
     * @param x float to subtract
     * @param other fraction from subsract
     * @return other - x as float
    */
    float operator-(const Fraction &other, float x)
    {
        return -1 * (x - other);
    }

    /**
     * @brief this operator multiplies two fructions
     * @param other fraction to multipliy
     * @return multiplication of two fractions
    */
    Fraction Fraction::operator*(const Fraction &other)
    {
        int numerator = 0, denominator = 0, gcd = 0;

        numerator = this->_numerator * other._numerator;
        denominator = this->_denominator * other._denominator;
        gcd = GCD(numerator, denominator);

        numerator /= gcd;
        denominator /= gcd;

        return Fraction(numerator, denominator);
    }

    /**
     * @brief this operator multiplies fraction and a float
     * @param x float to mult
     * @param other fraction to mult
     * @return x * other as float
    */
    float operator*(float x, const Fraction &other)
    {
        return (x * other._numerator) / other._denominator;
    }

    /**
     * @brief this operator multiplies fraction and a float
     * @param x float to mult
     * @param other fraction to mult
     * @return other * x as float
    */
    float operator*(const Fraction &other, float x)
    {
        return x * other;
    }

    /**
     * @brief this operator divides fractions
     * @param other fraction to divide
     * @return divides current fraction with other
    */
    Fraction Fraction::operator/(const Fraction &other)
    {
        return this->operator*(Fraction(other._denominator, other._numerator));
    }

    /**
     * @brief this operator divides float by fraction
     * @param x float to divide
     * @param other fraction to divide
     * @return x / other as float
    */
    float operator/(float x, const Fraction &other)
    {
        return other._numerator / (other._numerator * x);
    }

    /**
     * @brief this operator divides float by fraction
     * @param x float to divide
     * @param other fraction to divide
     * @return other / x as float
    */
    float operator/(const Fraction &other, float x)
    {
        return 1 / (x / other);
    }

    bool Fraction::operator==(const Fraction &other)
    {
        return this->_numerator * other._denominator == this->_denominator * other._numerator;
    }

    float operator==(float x, const Fraction &other)
    {
        return other._numerator == x * other._denominator;
    }

    float operator==(const Fraction &other, float x)
    {
        return x == other;
    }

    bool Fraction::operator>(const Fraction &other)
    {
        return this->_numerator * other._denominator > this->_denominator * other._numerator;
    }

    float operator>(float x, const Fraction &other)
    {
        return other._numerator > x * other._denominator;
    }

    float operator>(const Fraction &other, float x)
    {
        return x > other;
    }

    bool Fraction::operator>=(const Fraction &other)
    {
        return this->_numerator * other._denominator >= this->_denominator * other._numerator;
    }

    float operator>=(float x, const Fraction &other)
    {
        return other._numerator >= x * other._denominator;
    }

    float operator==(const Fraction &other, float x)
    {
        return x >= other;
    }

    bool Fraction::operator<(const Fraction &other)
    {
        return this->_numerator * other._denominator < this->_denominator * other._numerator;
    }

    float operator<(float x, const Fraction &other)
    {
        return other._numerator < x * other._denominator;
    }

    float operator<(const Fraction &other, float x)
    {
        return x < other;
    }

    bool Fraction::operator<=(const Fraction &other)
    {
        return this->_numerator * other._denominator <= this->_denominator * other._numerator;
    }

    float operator<=(float x, const Fraction &other)
    {
        return other._numerator <= x * other._denominator;
    }

    float operator<=(const Fraction &other, float x)
    {
        return x <= other;
    }

    ostream& operator<<(ostream &os, const Fraction &other)
    {
        os << other._numerator << "/" << other._denominator << endl;
        return os;
    }

    istream& operator>>(istream &is, Fraction &other)
    {
        is >> other._numerator >> other._denominator;
        return is;
    }
}