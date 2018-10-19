#ifndef MONEY_H
#define MONEY_H
#include <iostream>

class Money
{
public:
    Money(); //default constructor
    Money(int dollars, int cents);
    double doubleMoney() const; // return Money as double value
    void setMoney(int dollars, int cents);
    int getDollars() const ;
    int getCents() const;

    friend std::ostream& operator<<(std::ostream& out, const Money& mn);

    Money operator+(const Money& mn) const;
    Money operator-(const Money& mn) const;
    Money operator*(int x) const;
    friend bool operator > (const Money& mn, const Money& mn2);
    friend bool operator < (const Money& mn, const Money& mn2);
    friend bool operator == (const Money& mn, const Money& mn2);




private:
    int dollars; //to hold dollars
    int cents; //to hold cents

  };





#endif
