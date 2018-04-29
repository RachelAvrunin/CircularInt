

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
	current /= x.current;
	current = current % end;
	if(current < start)
		current += end;
	return *this;
}

CircularInt& CircularInt::operator /= (int const num){
	current /= num;
	current = current % end;
	if(current < start)
		current += end;
	return *this;
}

CircularInt operator / ( CircularInt const & x, int num){
	CircularInt res {x.start, x.end};
	res.current = x.current;
	if(res.current % num == 0)
		res /= num;
	else
		throw "\"There is no number x in {"+to_string(x.start)+","+to_string(x.end)+"} such that x*"+to_string(num)+"="+to_string(x.current)+"\" ";
	return res;
}

CircularInt operator / (int x, CircularInt const & obj){
	CircularInt res {obj.start, obj.end};
	x = x % obj.end;
	res.current = x;
	if(res.current % obj.current == 0)
		res /= obj;
	else
		throw "\"There is no number x in {"+to_string(obj.start)+","+to_string(obj.end)+"} such that x*"+to_string(x)+"="+to_string(obj.current)+"\" ";
	return res;
}

CircularInt operator / (CircularInt const & x, CircularInt const & y){
	if(x.end != y.end || x.start != y.start)
		throw "The objects have different cycles";
	else {
		CircularInt res {x.start, x.end};
        if(x.current % y.current == 0)
            res.current = x.current / y.current;
        else
            throw "\"There is no number x in {"+to_string(x.start)+","+to_string(x.end)+"} such that x*"+to_string(x.current)+"="+to_string(y.current)+"\" ";
		return res;
	}
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