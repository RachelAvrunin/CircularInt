#include <iostream>
using namespace std;
#pragma once

class CircularInt{
 
    private:
    int start;
    int end;
    int current;
          
    public:

        //Constructor
        CircularInt();
        CircularInt(int, int);
        ~CircularInt();

        //Assignment
        CircularInt& operator =(CircularInt const &);
        CircularInt& operator =(int);

        //Comparison
        friend bool operator == (CircularInt const &, int const);
        friend bool operator == (int const, CircularInt const &);
        friend bool operator == (CircularInt const &, CircularInt const &);
        friend bool operator != (CircularInt const &, int const);
        friend bool operator != (int const, CircularInt const &);
        friend bool operator != (CircularInt const &, CircularInt const &);
        friend bool operator <= (CircularInt const &, int const);
        friend bool operator <= (int const, CircularInt const &);
        friend bool operator <= (CircularInt const &, CircularInt const &);
        friend bool operator < (CircularInt const &, int const);
        friend bool operator < (int const, CircularInt const &);
        friend bool operator < (CircularInt const &, CircularInt const &);
        friend bool operator >= (CircularInt const &, int const);
        friend bool operator >= (int const, CircularInt const &);
        friend bool operator >= (CircularInt const &, CircularInt const &);
        friend bool operator > (CircularInt const &, int const);
        friend bool operator > (int const, CircularInt const &);
        friend bool operator > (CircularInt const &, CircularInt const &);
        
        //Addition
        CircularInt& operator += (int);
        CircularInt& operator += (CircularInt const &);
        friend CircularInt operator + (int, CircularInt const &);
        friend CircularInt operator + (CircularInt const &, int);
        friend CircularInt operator + (CircularInt const &, CircularInt const &);
        CircularInt& operator ++ ();
        const CircularInt operator ++ (int);

        //Subtraction
        CircularInt operator - ();
        CircularInt& operator -= (CircularInt const &);
        CircularInt& operator -= (int);
        friend CircularInt operator - (int, CircularInt const &);
        friend CircularInt operator - (CircularInt const &,int);
        friend CircularInt operator - (CircularInt const &,CircularInt const &);
        CircularInt& operator -- ();
        const CircularInt operator -- (int);

        //Multiplication
        CircularInt& operator *= (CircularInt const &);
        CircularInt& operator *= (int);
        friend CircularInt operator * (int, CircularInt const &);
        friend CircularInt operator * (CircularInt const &,int);
        friend CircularInt operator * (CircularInt const &, CircularInt const &);

        //Division
        CircularInt& operator /= (int);
        CircularInt& operator /= (CircularInt const &);
        friend CircularInt operator / (int, CircularInt const &);
        friend CircularInt operator / (CircularInt const &, int);
        friend CircularInt operator / (CircularInt const &, CircularInt const &);

        //Stream
        friend ostream& operator << (ostream &, CircularInt const &);
        friend istream& operator >> (istream & ,CircularInt &);
};

