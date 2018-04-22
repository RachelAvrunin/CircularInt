#include <iostream>
using namespace std;

#include "CircularInt.hpp"

//Constructor
CircularInt::CircularInt(){
	cout << "No values entered, defining default values 0-10"<< endl;
	this->start = 0;
	this->end = 10;
	this->current=0;
}

CircularInt::CircularInt(int start, int end){
	if(end < start ){
		cout << "Wrong values entered, defining default values 0-10"<< endl;
		this->start = 0;
		this->end = 10;
		this->current=0;
	}
	else{
		this->start = start;
		this->end = end;
		this->current=start;
	}
}

CircularInt::~CircularInt(){
}

int normalization(int num, int start, int end){
	num = num % (end-start+1);
	if(num>end)
		num -= (end-start+1);
	if(num < start)
		num += (end-start+1);
	return num;
}

//Assignment
CircularInt& CircularInt::operator= (const CircularInt& c){
	this->start = c.start;
	this->end = c.start;
	this->current = c.current;
	return *this;
}  

CircularInt& CircularInt::operator= (int num){
	this->current = normalization(num,this->start,this->end);
	return *this;
}

//Comparison
bool operator == (CircularInt const & obj, int const num){
	return obj.current == num;
}

bool operator == (int const num, CircularInt const & obj){
	return num == obj.current;
}

bool operator == (CircularInt const & a, CircularInt const & b){
	return a.current == b.current;
}

bool operator != (CircularInt const & obj, int num){
	return !(obj.current == num);
}

bool operator != (int num, CircularInt const & obj){
	return !(num == obj.current);
}

bool operator != (CircularInt const & a, CircularInt const & b){
	return !(a.current == b.current);
}

//Addition

// CircularInt& operator += (int);
// CircularInt& operator += (CircularInt const &);
// friend CircularInt operator + (int, CircularInt const &);
// friend CircularInt operator + (CircularInt const &, int);
// friend CircularInt operator + (CircularInt const &, CircularInt const &);
// CircularInt& operator ++ ();
// const CircularInt operator ++ (int);

//Subtraction

// CircularInt operator - ();
// CircularInt& operator -= (CircularInt const &);
// CircularInt& operator -= (int);
// friend CircularInt operator - (int, CircularInt const &);
// friend CircularInt operator - (CircularInt const &,int);
// friend CircularInt operator - (CircularInt const &,CircularInt const &);
// CircularInt& operator -- ();
// const CircularInt operator -- (int);

//Multiplication

// CircularInt& operator *= (CircularInt const &);
// CircularInt& operator *= (int);
// friend CircularInt operator * (int, CircularInt const &);
// friend CircularInt operator * (CircularInt const &,int);
// friend CircularInt operator * (CircularInt const &, CircularInt const &);

//Division

// CircularInt& operator /= (int);
// CircularInt& operator /= (CircularInt const &);
// friend CircularInt operator / (int, CircularInt const &);
// friend CircularInt operator / (CircularInt const &, int);
// friend CircularInt operator / (CircularInt const &, CircularInt const &);

//Stream
ostream& operator << (ostream& os, CircularInt const & c){
	return os << c.current;
}

// friend istream& operator >> (istream & ,CircularInt &);