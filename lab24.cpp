#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber((real*c.real)-(imag*c.imag),(imag*c.real)+(real*c.imag));
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
    double x = pow(c.real,2)+pow(c.imag,2);
	return ComplexNumber(((real*c.real)+(imag*c.imag))/x,((imag*c.real)-(real*c.imag))/x);
}

ComplexNumber operator+(double s,const ComplexNumber &c){
	return ComplexNumber(s+c.real,c.imag);
}

ComplexNumber operator-(double s,const ComplexNumber &c){
	return ComplexNumber(s-c.real,-c.imag);
}
ComplexNumber operator*(double s,const ComplexNumber &c){
	return ComplexNumber(s*c.real,s*c.imag);
}
ComplexNumber operator/(double s,const ComplexNumber &c){
	return ComplexNumber((s*c.real)/(pow(c.real,2)+pow(c.imag,2)),(-(s*c.imag))/(pow(c.real,2)+pow(c.imag,2)));
}

ostream & operator<<(ostream &os, const ComplexNumber &c){
    if (c.real == 0){
        if(c.imag == 0) return os << "0";
        else return os << c.imag << "i";
    }
    else if(c.imag > 0) return os << c.real << "+" << c.imag << "i";
    else if(c.imag < 0) return os << c.real << c.imag << "i";
    else return os << c.real;
}

bool ComplexNumber::operator==(const ComplexNumber &c){
    if(real == c.real && imag == c.imag){
        return true;
    }else{
        return false;
    }
}

bool operator==(double s,const ComplexNumber &c){
    if(s == c.real && c.imag == 0){
        return true;
    }else{
        return false;
    }
}

double ComplexNumber::abs(){
    return sqrt(pow(real,2)+pow(imag,2));
}

double ComplexNumber::angle(){
    return atan2(imag,real) * (180/M_PI) ;
}