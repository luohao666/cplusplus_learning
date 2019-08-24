#ifndef _COMPLEX_
#define _COMPLEX_

class complex
{
    public:
        //construcor
        complex(double r=0,double i=0):re(r),im(i){}

        //member func inline
        double real() const {return re;}
        double imag() const {return im;}

        complex& operator += (const complex&);

    private:
        double re;
        double im;

        //friend func
        friend complex& __doapl(complex*,const complex&);
};

inline complex& 
__doapl(complex* ths,const complex& r)
{
    ths->re+=r.re;
    ths->im+=r.im;
    return *ths;
}

inline complex&
complex::operator +=(const complex& r)
{
    return __doapl(this,r);
}

//non-member func
inline complex 
operator + (const complex& x,const complex& y)
{
    return complex(x.real()+y.real(),x.imag()+y.imag());
}

inline complex 
operator + (const complex& x,double y)
{
    return complex(x.real()+y,x.imag());
}

inline complex 
operator + (double x,const complex& y)
{
    return complex(x+y.real(),y.imag());
}

#include <iostream>
using namespace std;

inline ostream&
operator << (ostream& os,const complex& x)
{
    return os << '(' <<x.real() << ',' <<x.imag()<< ')';
}

#endif