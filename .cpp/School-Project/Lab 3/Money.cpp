#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "Money.h"




int main()
{
  Money mn1(8,150); // 8 dollars and 150 cents
  Money mn2(5,10);  // 5 dollars and 10 cents
  Money mn5(20,120); // 20 dollars and 120 cents
  Money mn3 = mn1 + mn2;
  Money mn4;
  mn4.setMoney(14,5); //setvalue dollars and cents as 14 dollars and 5 cents

  std::cout << "mn1: " << mn1 << '\n';
  std::cout << "mn2: " << mn2 << '\n';
  std::cout << "mn3 = mn1 + mn2 = " << mn3 << '\n';
  std::cout << "mn4 " << mn4 << '\n';
  std::cout << "mn5 " <<  mn5 <<'\n';
  if (mn1 > mn2)
  {
    std::cout << "Money 1 > Money 2" << '\n';
  } else {
    std::cout << "Money 1 < Money 2" << '\n';
  }

  if (mn4 == mn5)
  {
    std::cout << "Money 4 = Money 5" << '\n';
  }
  else {
    std::cout << "Money 4 not EQUALS to Money 5" << '\n';
  }
  return 0;
}


Money::Money(){
  cents = 0;
  dollars = 0;
}
Money::Money(int dollars, int cents){
  this->cents = cents % 100;
  this->dollars = dollars + cents/100;

}

double Money::doubleMoney() const {
  double d  = getDollars();
  double c = getCents();
  return (d + (c/100));
}

void Money::setMoney(int dollars, int cents){
  this->cents = cents % 100;
  this->dollars = dollars + cents/100;

}

int Money::getDollars() const{
  return dollars;

}
int Money::getCents() const{
  return cents;
}

std::ostream& operator <<(std::ostream& out, const Money& mn){
  out << "$" << std::fixed << std::setprecision(2) << mn.doubleMoney() << "\n";
  return out;
}

Money Money::operator+(const Money& mn) const{
  Money temp;
  temp.dollars = this->dollars + mn.dollars;
  temp.cents = this->cents + mn.cents;
  return temp;

}

Money Money::operator-(const Money& mn) const{
  Money temp;
  temp.dollars = this->dollars - mn.dollars;
  temp.cents = this->cents - mn.cents;
  if (temp.dollars < 0){
    temp.dollars = abs(this->dollars - mn.dollars);
  }
  return temp;

}

Money Money::operator*(int x) const{
  Money temp;
  temp.dollars = this->dollars*x;
  temp.cents = this->cents*x;
  return temp;
}

bool operator > (const Money& mn, const Money& mn2){
  return ((mn.getDollars() > mn2.getDollars()) && (mn.getCents() > mn2.getCents()));
}

bool operator < (const Money& mn, const Money& mn2){
  return ((mn.getDollars() < mn2.getDollars()) && (mn.getCents() < mn2.getCents()));
}

bool operator == (const Money& mn, const Money& mn2){
  return ((mn.getDollars() == mn2.getDollars()) && (mn.getCents() == mn2.getCents()));
}
