#pragma once
#include <iostream>

class vect2
{
	private:
		int x;
		int y;

	public:
		vect2() : x(0), y(0) {}
		vect2(int a, int b) : x(a), y(b) {}
		vect2(const vect2 &other) : x(other.x), y(other.y) {}
		vect2 &operator=(const vect2 &other){return(this->x = other.x, this->y = other.y, *this);}
		~vect2(){}

		vect2 operator-(void)const{return vect2(-x, -y);}

		int &operator[](unsigned int i){return(i == 0 ? x : y);}
		int operator[](unsigned int i)const{return(i == 0 ? x : y);}

		vect2 &operator++(void){return((++x, ++y),*this);}
		vect2 &operator--(void){return(--x, --y,*this);}
		vect2 operator++(int){vect2 old(*this); this->x++; this->y++; return(old);}
		vect2 operator--(int){vect2 old(*this); this->x--; this->y--; return(old);}

		bool operator==(const vect2 &other){return(this->x == other.x && this->y == other.y);}
		bool operator!=(const vect2 &other){return(this->x != other.x && this->y != other.y);}

		vect2 &operator+=(const vect2 &other){return(this->x += other.x, this->y += other.y, *this);}
		vect2 &operator-=(const vect2 &other){return(this->x -= other.x, this->y -= other.y, *this);}
		vect2 &operator*=(const int i){return(this->x *= i, this->y *= i, *this);}

		vect2 operator+(const vect2 &other)const{return vect2(this->x + other.x, this->y + other.y);}
		vect2 operator-(const vect2 &other)const{return vect2(this->x - other.x, this->y - other.y);}
		vect2 operator*(const int i)const{return vect2(this->x * i, this->y * i);}

		friend std::ostream &operator<<(std::ostream &out, const vect2 &v){out << "{" << v.x << ", " << v.y << "}"; return(out);}
		friend vect2 operator*(int scalar, const vect2 &v){return(v * scalar);}
};