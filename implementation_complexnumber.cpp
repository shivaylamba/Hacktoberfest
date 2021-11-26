#include <iostream>
#include <cmath>

class Complex{
	float re;
	float im;
	
	float calc_mod();
	float calc_ang();
public:
	Complex(float = 0, float = 0);//definition of a contructor
	
	void show(int = 0);//can show 3 different version of same complex number
	void setR(float);
	void setI(float);
	
	float getR();
	float getI();
	
	Complex operator+(Complex); //definition of all 4 basics operations with complex numbers
	Complex operator*(Complex);
	Complex operator-(Complex);
	
	~Complex();//destructor
};

Complex::Complex(float re, float im){
	this->re = re;
	this->im = im;
}

Complex::~Complex(){}

void Complex::show(int mode){
	switch(mode){
		case 0:
			std::cout<<re;
			if(im != 0){
				if(im < 0)
					std::cout<<" "<<im;
				else
					std::cout<<" + "<<im<<"i";
			}
			break;
		case 1:
			std::cout<<calc_mod()<<" \ "<<calc_ang();
			break;
		case 2:
			std::cout<<calc_mod()<<" e^"<<calc_ang()<<"i";
			break;
		default:
			break;
	}
}

void Complex::setR(float re){
	this->re = re;
}

void Complex::setI(float im){
	this->im = im;
}
float Complex::getR(){
	return re;
}
float Complex::getI(){
	return im;
}

Complex Complex::operator+(Complex cmp){
	Complex sum;
	
	sum.setR(cmp.getR() + re);
	sum.setI(cmp.getI() + im);
	
	return sum;
}

Complex Complex::operator-(Complex cmp){
	Complex sum;
	
	sum.setR(cmp.getR() - re);
	sum.setI(cmp.getI() - im);
	
	return sum;
}

Complex Complex::operator*(Complex cmp){
	Complex sum;
	
	sum.setR(cmp.getR()*re - cmp.getI()*im);
	sum.setI(cmp.getI()*re + cmp.getR()*im);
	
	return sum;
}

float Complex::calc_mod(){
	return sqrt(re*re +im*im);
}
float Complex::calc_ang(){

	return (atan(im/re));

}

int main(){
	
	Complex a(10, 5), b(25, 10), c;
	
	c = a + b;
	c.show();
	std::cout<<std::endl;
	c.show(1);
	std::cout<<std::endl;
	c.show(2);
	std::cout<<std::endl;
	std::cout<<std::endl;
	
	c = a - b;
	c.show();
	std::cout<<std::endl;
	c.show(1);
	std::cout<<std::endl;
	c.show(2);
	std::cout<<std::endl;
	std::cout<<std::endl;
	
	c = a * b;
	c.show();
	std::cout<<std::endl;
	c.show(1);
	std::cout<<std::endl;
	c.show(2);
	std::cout<<std::endl;
	std::cout<<std::endl;
}
