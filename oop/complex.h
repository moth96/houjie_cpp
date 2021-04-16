#ifndef __COMPLEX__
#define __COMPLEX__

//complex实现代码
//1.实现了complex的构造函数、cout和操作符重载
#include <iostream>
using namespace std;

class complex
{
public:
    complex(double r = 0, double i = 0): re(r), im(i){}
    double getReal() const {return re;}
    double getImag() const {return im;}
    //+=
    complex& operator += (const complex& c){
        this->re += c.re;
        this->im += c.im;
        return *this;
    }
    //-=
    complex& operator -= (const complex& c){
        this->re -= c.re;
        this->im -= c.im;
        return *this;
    };

private:
    double re, im;

};

//输出重载
ostream& operator << (ostream& os, const complex& c){
    return os << '(' << c.getReal() << ',' << c.getImag() << ')';
}

//+
complex operator + (const complex& c1, const complex& c2){
    return complex(c1.getReal() + c2.getReal(), c1.getImag() + c2.getImag());
}
complex operator + (double r, const complex& c){
    return complex(r + c.getReal(), c.getImag());
}
complex operator + (const complex& c, double r){
    return complex(r + c.getReal(), c.getImag());
}

//-
complex operator - (const complex& c1, const complex& c2){
    return complex(c1.getReal() - c2.getReal(), c1.getImag() - c2.getImag());
}
complex operator - (double r, const complex& c){
    return complex(r - c.getReal(), -c.getImag());
}
complex operator - (const complex& c, double r){
    return complex(c.getReal() - r, c.getImag());
}

//*
complex operator * (const complex& c1, const complex& c2){
  return complex (c1.getReal() * c2.getReal() - c1.getImag() * c2.getImag(),
			   c1.getReal() * c2.getImag() + c1.getImag() * c2.getReal());
}
complex operator * (const complex& c, double r){
  return complex (c.getReal() * r, c.getImag() * r);
}

complex operator * (double r, const complex& c){
  return complex (r * c.getReal(), r * c.getImag());
}

// /
complex operator / (const complex& c, double r){
  return complex (c.getReal() / r, c.getImag() / r);
}

//== !=
bool operator == (const complex& c1, const complex& c2){
    return c1.getReal() == c2.getReal() && c1.getImag() == c2.getImag();
}
bool operator == (const complex& c1, double c2){
    return c1.getReal() == c2 && c1.getImag() == 0;
}
bool operator == (double c1, const complex& c2){
    return c2.getReal() == c1 && c2.getImag() == 0;
}
bool operator != (const complex& c1, const complex& c2){
    return !(c1 == c2);
}
bool operator != (const complex& c1, double c2){
    return !(c1 == c2);
}
bool operator != (double c1, const complex& c2){
    return !(c1 == c2);
}

//+X -X
complex operator + (const complex& c){
  return c;
}

complex operator - (const complex& c){
  return complex (-c.getReal(), -c.getImag());
}

//共轭
complex conj(const complex& c){
    return complex(c.getReal(), -c.getImag());
}
//norm
double norm(const complex& c){
    return c.getReal() * c.getReal() + c.getImag() + c.getImag();
}


#endif