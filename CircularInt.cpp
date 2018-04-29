

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

int norm(int num, int start, int end){
   while (num < start || num > end){
        if(num > end){
            num -= (end-start+1);
        }
        else if(num < start){
            num += (end-start+1);
        }
    }
	return num;
}

//Assignment
CircularInt& CircularInt::operator = (const CircularInt& x){
	this->start = x.start;
	this->end = x.end;
	this->current = x.current;
	return *this;
}  

CircularInt& CircularInt::operator = (int num){
	this->current = norm(num,this->start,this->end);
	return *this;
}

//Comparison
bool operator == (CircularInt const & x, int const num){
	return x.current == num;
}

bool operator == (int const num, CircularInt const & obj){
	return num == obj.current;
}

bool operator == (CircularInt const & x, CircularInt const & y){
	return x.current == y.current;
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

bool operator <= (CircularInt const & x, int const num){
	return x.current <= num;
}

bool operator <= (int const num, CircularInt const & x){
	return num <= x.current;
}

bool operator <= (CircularInt const & x, CircularInt const & y){
	return x.current <= y.current;
}

bool operator < (CircularInt const & x, int const num){
	return x.current < num;
}

bool operator < (int const num, CircularInt const & x){
	return num < x.current;
}

bool operator < (CircularInt const & x, CircularInt const & y){
	return x.current < y.current;
}

bool operator >= (CircularInt const & x, int const num){
	return x.current >= num;
}

bool operator >= (int const num, CircularInt const & x){
	return num >= x.current;
}

bool operator >= (CircularInt const & x, CircularInt const & y){
	return x.current >= y.current;
}

bool operator > (CircularInt const & x, int const num){
	return x.current > num;
}

bool operator > (int const num, CircularInt const & x){
	return num > x.current;
}

bool operator > (CircularInt const & x, CircularInt const & y){
	return x.current > y.current;
}

//Addition
CircularInt& CircularInt::operator += (CircularInt const & x){
	current = norm(current+x.current, start, end);
	return *this;
}

CircularInt& CircularInt::operator += (int const x){
	current = norm(current+x, start, end);
	return *this;
}

CircularInt operator + (int add, CircularInt const & x){
	CircularInt res {x.start, x.end};
    res.current= norm(add+x.current, x.start, x.end);
	return res;
}

CircularInt operator + (CircularInt const & x, int add){
	return add + x;
}

CircularInt operator + (CircularInt const & x, CircularInt const & y){
	CircularInt res {x.start, x.end};
	res.current = norm(x.current+y.current, x.start, x.end);
	return res;
}

CircularInt& CircularInt::operator ++ (){
	*this += 1;
	return *this;
}

const CircularInt CircularInt::operator ++ (int	){
	CircularInt res {start, end};
	res.current = current;
	current = norm(current + 1, start, end);
	return res;
}

//Subtraction
CircularInt& CircularInt::operator -= (CircularInt const & x){
	current = norm(current-x.current, start, end);
	return *this;
}

CircularInt& CircularInt::operator -= (int const x){
	current = norm(current-x, start, end);
	return *this;
}

CircularInt operator - (int num, CircularInt const & x){
	CircularInt res {x.start, x.end};
	res.current = norm(num-x.current, res.start, res.end);	
	return res;
}

CircularInt operator - (CircularInt const & x, int sub){
	return (-sub + x);
}

CircularInt operator - (CircularInt const & x, CircularInt const & y){
	CircularInt res {x.start, x.end};
	res.current = norm(x.current-y.current, x.start, x.end);
	return res;
}

CircularInt CircularInt::operator - (){
	CircularInt res {start, end};
	res.current = norm(end-current, start, end);
	return res;
}

CircularInt& CircularInt::operator -- (){
	current =norm(current - 1, start, end);
	return *this;
}

const CircularInt CircularInt::operator -- (int){
	CircularInt res {start, end};
	res.current = current;
	current = norm(current - 1, start, end);
	return res;
}

//Multiplication
CircularInt& CircularInt::operator *= (CircularInt const & x){
	current = norm(current*x.current, start, end);
	return *this;
}

CircularInt& CircularInt::operator *= (int const num){
	current = norm(current*num, start, end);
	return *this;
}

CircularInt operator * (int num, CircularInt const & x){
	CircularInt res {x.start, x.end};
	res.current = norm(x.current*num, x.start, x.end);
	return res;
}

CircularInt operator * (CircularInt const & x, int num){
	return num * x ;
}

CircularInt operator * (CircularInt const & x, CircularInt const & y){
	CircularInt res {x.start, x.end};
	res.current = norm(x.current*y.current, x.start, x.end);
	return res;
}

//Division
CircularInt& CircularInt::operator /= (CircularInt const & x){
	if(end > x.current && x.current < start){
		for(int i = start; i <= end; i++)
			if(current == x.current * i){
				this->current = i;
				return *this;
		}
	}
	throw "\"There is no number x in {"+to_string(start)+","+to_string(end)+"} such that x*"+to_string(x.current)+"="+to_string(current)+"\" ";
}

CircularInt& CircularInt::operator /= (int const num){
	if(end > num && num < start){
		for(int i = start; i <= end; i++)
			if(current == num * i){
				this->current = i;
				return *this;
		}
	}
	throw "\"There is no number x in {"+to_string(start)+","+to_string(end)+"} such that x*"+to_string(num)+"="+to_string(current)+"\" ";
}

CircularInt operator / ( CircularInt const & x, int num){
	CircularInt res {x.start, x.end};
	if(x.start <= num && num <= x.current){
		for(int i = x.start; i <= x.end; i++)
			if(x.current == num * i){
				res.current = i;
				return res;
		}
	}
	throw "\"There is no number x in {"+to_string(x.start)+","+to_string(x.end)+"} such that x*"+to_string(num)+"="+to_string(x.current)+"\" ";
}

CircularInt operator / (int num, CircularInt const & x){
	CircularInt res {x.start, x.end};
	if(x.current <= num && num <= x.end){
		for(int i = x.start; i <= x.end; i++)
			if(num == x.current * i){
				res.current = i;
				return res;
		}
	}
	throw "\"There is no number x in {"+to_string(x.start)+","+to_string(x.end)+"} such that x*"+to_string(num)+"="+to_string(x.current)+"\" ";
}

CircularInt operator / (CircularInt const & x, CircularInt const & y){
	CircularInt res {x.start, x.end};
	if(x.start <= y.current && y.current <= x.current){
		for(int i = x.start; i <= x.end; i++)
			if(x.current == y.current * i){
				res.current = i;
				return res;
			}
		}
    throw "\"There is no number x in {"+to_string(x.start)+","+to_string(x.end)+"} such that x*"+to_string(x.current)+"="+to_string(y.current)+"\" ";
}

CircularInt& CircularInt::operator %= (const int num){
	current = norm(start - 1 + ( current % num) , start, end);
	return *this;
}

const CircularInt operator % (const CircularInt& x , const int num){
	CircularInt res {x.start, x.end};
	res.current = norm( x.current % num, x.start, x.end);
	return res;
}

//Stream
ostream& operator << (ostream& os, CircularInt const & c){
	return os << c.current;
}

istream& operator >> (istream & is, CircularInt& x){
		cin >> x.start >> x.end;
		x.current = x.start;
		return is;
}