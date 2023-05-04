#include "doctest.h"
#include "Fraction.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

TEST_CASE("Constructor") {
    Fraction a;
    CHECK(string("0/1").compare(a.toString()) == 0);
    Fraction b(0);
    CHECK(string("0/1").compare(b.toString()) == 0);
    Fraction c(5);
    CHECK(string("5/1").compare(c.toString()) == 0);
    Fraction d(2.5);
    CHECK(string("5/2").compare(d.toString()) == 0);
    Fraction e(-19, 11);
    CHECK(string("-19/11").compare(e.toString()) == 0);
    Fraction f(9, 3);
    CHECK(string("3/1").compare(f.toString()) == 0);
    CHECK_THROWS_AS(Fraction(8, 0), std::string); // divide by zere error
}

TEST_CASE("operator ==") {
    CHECK(Fraction(2, 4) == Fraction(1, 2));
    CHECK(!(Fraction(8, 5) == Fraction(0, 5)));
    CHECK(Fraction(15, 10) == 1.5);
    CHECK(!(Fraction(10, 6) == 10.6));
    CHECK(2.8 == Fraction(14, 5));
    CHECK(!(9.4 == Fraction(4, 9)));
    CHECK(Fraction(-5, 17) == Fraction(5, -17)); // (-/+) == (+/-)
    CHECK(Fraction(-9, 18) ==  -0.5); 
}

TEST_CASE("operator +") {
    CHECK((Fraction(1) + Fraction(2)) == Fraction(3));
    CHECK((Fraction(1,2) + Fraction(1, 2)) == Fraction(1));
    CHECK(!((Fraction(2, 8) + Fraction(1, 3)) == Fraction(3, 11)));
    CHECK((Fraction(8, 6) + 1.8) == Fraction(47, 15));
    CHECK(!((Fraction(36, 7) + 9.6) == Fraction(400, 35)));
    CHECK((8.3 + Fraction(15, 16)) == Fraction(739, 80));
    CHECK(!((1.6 + Fraction(2)) == (Fraction(3, 6))));
    CHECK((Fraction(54, 98) + Fraction(54, -98)) == 0); // x + (-x) == 0
}

TEST_CASE("operator -") {
    CHECK((Fraction(1) - Fraction(5, 6)) == Fraction(1, 6));
    CHECK(((Fraction(7, 8) - Fraction(5, 8)) == Fraction(1, 4)));
    CHECK(!((Fraction(9, 5) - Fraction(-9, 5)) == Fraction(0)));
    CHECK((Fraction(62, 9) - 16.5) == Fraction(-173, 18));
    CHECK(!((Fraction(9, 1) - 9.9) == Fraction(9, 10)));
    CHECK((62.3 - Fraction(35, 2)) == Fraction(224, 5));
    CHECK(!((5.2 - Fraction(5, 2)) == Fraction(0)));
}

TEST_CASE("operator *") {
    CHECK((Fraction(21, 7) * Fraction(1, 2)) == 1.5);
    CHECK((Fraction(58, 65) * 0) == 0);  // x * 0 == 0
    CHECK((Fraction(74, 4) * 1) == Fraction(74, 4));  // x * 1 == x
    CHECK((Fraction(5, 6) * Fraction(6, 5)) == 1);  // x * x^(-1) == 1
    CHECK((Fraction(6, 4) * Fraction(9, 7)) == Fraction(27, 14));
    CHECK(!((Fraction(5, 58) * Fraction(3)) == 2));
    CHECK(((3.5 * Fraction(2, 9)) == Fraction(7, 9)));
    CHECK((Fraction(6, 49) * 1.2) == Fraction(36, 245));
}

TEST_CASE("operator /") {
    CHECK((Fraction(6, 98) / Fraction(6, 98)) == 1);  // x / x == 1
    CHECK((0 / Fraction(8, 6)) == 0);  // 0 / x == 0
    CHECK((Fraction(5 ,8) / Fraction(9, 7)) == Fraction(35, 72));
    CHECK(!((Fraction(2, 8) / Fraction(8, 2)) == 0.16));
    CHECK((Fraction(2, 9) / 0.46) == Fraction(100, 207));
    CHECK(9.6 / Fraction(5, 2) == Fraction(96,25));
    CHECK_THROWS_AS((Fraction(8, 5) / 0), std::string); // divide by zero error
}

TEST_CASE("operator <") {
    CHECK(Fraction(9, 5) < Fraction(14, 5));
    CHECK(!(Fraction(55, 2) < Fraction(16, 4)));
    CHECK(Fraction(-8 , 9) < Fraction(8, 9));
    CHECK(Fraction(45, 95) < 6.77);
    CHECK(0.054 < Fraction(6, 7));
}

TEST_CASE("operator <=") {
    CHECK(Fraction(8, 3) <= Fraction(16, 6));
    CHECK(Fraction(4, 1) <= Fraction(20, 4));
    CHECK(Fraction(2, 5) <= 0.4);
    CHECK(Fraction(2, 89) <= 2.9);
    CHECK(9.6 <= Fraction(25, 2));
    CHECK(2.5 <= Fraction(5, 2));
    CHECK(!(Fraction(9, 5) <= Fraction(6, 5)));
}

TEST_CASE("operator >") {
    CHECK(Fraction(59, 9) > Fraction(8, 5));
    CHECK(!(Fraction(5, 2) > Fraction(8, 2)));
    CHECK(Fraction(8, 15) > 0.096);
    CHECK(8.6 > Fraction(9, 2));
    CHECK(Fraction(-5, 8) > -9);
}

TEST_CASE("operator >=" ) {
    CHECK(Fraction(14, 7) >= Fraction(2, 1));
    CHECK(Fraction(5, 8) >= Fraction(1, 2));
    CHECK(!(Fraction(6, 45) >= Fraction(15, 45)));
    CHECK(Fraction(4, 3) >= 0.98);
    CHECK(9.65 >= Fraction(9, 16));
}

TEST_CASE("operator ++ pre") {
    CHECK((Fraction(5, 6)++) == Fraction(5, 6));
}

TEST_CASE("operator ++ post") {
    CHECK((++Fraction(6, 7)) == Fraction(13,7 7));
}

TEST_CASE("operator -- pre") {
    CHECK((Fraction(9, 5)--) == Fraction(9, 5));
}

TEST_CASE("operator -- post") {
    CHECK((--Fraction(8, 2)) == 3);
}
TEST_CASE("operator <<") {
    std::ostream os;
    Fraction f(5, 9);
    os << f;
    std::stringstream ss;
    ss << os.rdbuf();
    CHECK(os.str().compare("5/9"));
}

