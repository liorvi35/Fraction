/**
 * @brief this file containts the Fraction declarations; Assignment 3, Software Systems 2 course at Ariel University
 * @author Lior Vinman
 * @since 15/04/2023
*/


#pragma once // insuring that header will be included only once at most

#include <iostream>

using namespace std;

namespace ariel
{
    /**
     * @brief this class representing the fraction
    */
    class Fraction
    {
        private:

            int _numerator, _denominator;
        
        public:

            /* Constructor */

            Fraction(int, int);

            /* Addition */

            Fraction operator+(const Fraction&); // Fraction + Fraction

            friend float operator+(float, const Fraction&); // float + Fraction

            friend float operator+(const Fraction&, float); // Fraction + float

            /* Subtraction */

            Fraction operator-(const Fraction&); // Fraction - Fraction

            friend float operator-(float, const Fraction&); // float - Fraction

            //friend float operator-(const Fraction&, float); // Fraction - float

            /* Multiplication */

            Fraction operator*(const Fraction&); // Fraction * Fraction

            friend float operator*(float, const Fraction&); // float * Fraction

            friend float operator*(const Fraction&, float); // Fraction * float

            /* Divison */

            Fraction operator/(const Fraction&); // Fraction : Fraction

            friend float operator/(float, const Fraction&); // float : Fraction

            friend float operator/(const Fraction&, float); // Fraction : float

            /* Equallity */

            bool operator==(const Fraction&); // Fraction == Fraction

            friend float operator==(float, const Fraction&); // float == Fraction

            friend float operator==(const Fraction&, float); // Fraction == float


            /* Less Than */

            bool operator<(const Fraction&); // Fraction < Fraction

            friend float operator<(float, const Fraction&); // float < Fraction

            friend float operator<(const Fraction&, float); // Fraction < float

            /* Less Than or Equall*/

            bool operator<=(const Fraction&); // Fraction <= Fraction

            friend float operator<=(float, const Fraction&); // float <= Fraction

            friend float operator<=(const Fraction&, float); // Fraction <= float

            /* Greater Than */

            bool operator>(const Fraction&); // Fraction > Fraction

            friend float operator>(float, const Fraction&); // float > Fraction

            friend float operator>(const Fraction&, float); // Fraction > float

            /* Greater Than or Equall*/

            bool operator>=(const Fraction&); // Fraction >= Fraction

            friend float operator>=(float, const Fraction&); // float >= Fraction

            friend float operator>=(const Fraction&, float); // Fraction >= float

            /* Increment */

            Fraction& operator++(); // ++Fractior

            Fraction operator++(int); // Fraction++

            /* Decrement */

            Fraction& operator--(); // --Fractior

            Fraction operator--(int); // Fraction--

            /* Output Stream */

            friend ostream& operator<<(ostream&, const Fraction&); // output in format: "<numerator> / <denominator>"

            /* Input Stream */

            friend istream& operator>>(istream&, Fraction&); // input in format: "<numerator> <denominator>"
    };
}