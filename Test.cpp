#include "sources/Fraction.hpp"
#include "doctest.h"

using namespace std;
using namespace ariel;

namespace ariel
{
    TEST_CASE("Constructor tests")
    {
        Fraction a;
        Fraction b(2, 3);
        Fraction c(5, 10);
        Fraction d(0, 1);
        Fraction e(-1, 2);

        CHECK(a.getNumerator() == 0);
        CHECK(a.getDenominator() == 1);

        CHECK(b.getNumerator() == 2);
        CHECK(b.getDenominator() == 3);
        
        CHECK(c.getNumerator() == 5);
        CHECK(c.getDenominator() == 10);
        
        CHECK(d.getNumerator() == 0);
        CHECK(d.getDenominator() == 1);

        CHECK(e.getNumerator() == -1);
        CHECK(e.getDenominator() == 2);
    }


    TEST_CASE("Addition tests") 
    {
        Fraction a(1, 2);
        Fraction b(1, 3);a++;
        ++a;
        Fraction c(-1, 100000);
        Fraction d(7, 8);
        Fraction e = a + b;
        Fraction f = c + d;

        CHECK(e.getNumerator() == 5 );
        CHECK(e.getDenominator() == 6);

        CHECK(f.getNumerator() == 87499);
        CHECK(f.getDenominator() == 100000);
    }


    TEST_CASE("Subtraction tests")
    {
        Fraction a(1, 2);
        Fraction b(1, 3);
        Fraction c(6, 6);
        Fraction d(-100, 7);
        Fraction e = a - b;
        Fraction f = c - d;

        CHECK(e.getNumerator() == 1);
        CHECK(e.getDenominator() == 6);

        CHECK(e.getNumerator() == 107);
        CHECK(e.getDenominator() == 7);
    }

    TEST_CASE("Multiplication tests")
    {
        Fraction a(1, 2);
        Fraction b(2, 3);
        Fraction c(-80, 7);
        Fraction d(5, 2);
        Fraction e = a * b;
        Fraction f = c * d;

        CHECK(e.getNumerator() == 1);
        CHECK(e.getDenominator() == 3);

        CHECK(f.getNumerator() == -200);
        CHECK(f.getDenominator() == 7);
    }

    TEST_CASE("Divison tests")
    {
        Fraction a(1, 2);
        Fraction b(2, 3);
        Fraction e = a / b;

        CHECK(e.getNumerator() == 3);
        CHECK(e.getDenominator() == 4);

    }

    TEST_CASE("Inequality tests")
    {
        Fraction a(4, 8);
        Fraction b(8, 12);
        Fraction c(4, 8);

        CHECK(a == c);
        CHECK(!(a == b));

        CHECK(a != b);

        CHECK(!(a > b));
        CHECK(b > a);

        CHECK(!(a >= b));
        CHECK(a >= a);

        CHECK(a < b);
        CHECK(!(b < a));

        CHECK(a <= c);
        CHECK(c <= a);
        CHECK(a <= b);
    }


    TEST_CASE("Increasing & Decreasing tests")
    {
        Fraction a(1, 1);
        Fraction b(5, 7);

        a++;
        ++a;

        b++;
        ++b;


        CHECK(a.getNumerator() == 3);
        CHECK(a.getDenominator() == 1);

        CHECK(b.getNumerator() == 19);
        CHECK(b.getDenominator() == 7);
    }
}
