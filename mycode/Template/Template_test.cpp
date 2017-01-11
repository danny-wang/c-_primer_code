
#include "Rational.h"
#include "gtest/gtest.h"
#include <string>
#include <iostream>
using namespace std;


TEST(Rational_test, check_type_conversion) {
 
 	Rational<int> oneHalf(1,2);
    Rational<int> b(oneHalf);
    EXPECT_EQ(b.numerator(), 1);
    EXPECT_EQ(b.denominator(), 2);
    cout<<b.numerator()<<"  "<<b.denominator()<<endl;
    Rational<int> c;
    cout<<"before: "<<c.numerator()<<"  "<<c.denominator()<<endl;
    EXPECT_EQ(c.numerator(), 0);
    EXPECT_EQ(c.denominator(), 1);
    c=b;
    cout<<"after: "<<c.numerator()<<"  "<<c.denominator()<<endl;
    EXPECT_EQ(c.numerator(), 1);
    EXPECT_EQ(c.denominator(), 2);
    Rational<int> d=2*oneHalf;
    EXPECT_EQ(d.numerator(), 2);
    EXPECT_EQ(d.denominator(), 2);

}