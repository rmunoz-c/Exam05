#pragma once
#include <iostream>

class vect2 {
	private:
		int _x;
		int _y;

	public:
		vect2(): _x(0), _y(0) {}
		vect2(const int x, const int y): _x(x), _y(y) {}
		vect2(const vect2 &other) : _x(other._x), _y(other._y) {}
		vect2 &operator=(const vect2 &other) {_x = other._x; _y = other._y; return (*this);}
		~vect2() {}

		vect2 operator-(void) const {return vect2(-_x, -_y);}

		int &operator[](int idx) {return (idx == 0 ? _x : _y);}
		int operator[](int idx) const {return (idx == 0 ? _x : _y);}

		vect2 &operator++(void) {return ((++_x, ++_y), *this);}
		vect2 &operator--(void){return ((--_x, --_y), *this);}
		vect2 operator++(int) {vect2 tmp(*this);  ++(*this); return  (tmp);}
		vect2 operator--(int) {vect2 tmp(*this); --(*this); return (tmp);}

		bool operator==(const vect2 &o) const {return ((_x == o._x) && (_y == o._y));}
		bool operator!=(const vect2 &o) const {return (!(*this == o));}

		vect2 &operator+=(const vect2 &other){_x += other[0]; _y += other[1]; return (*this);}
		vect2 &operator-=(const vect2 &other){_x -= other[0]; _y -= other[1]; return (*this);}
		vect2 &operator*=(const int n){_x *= n; _y *= n; return (*this);}

		vect2 operator+(const vect2 &other) const {return (vect2(_x + other._x, _y + other._y));}
		vect2 operator-(const vect2 &other) const {return (vect2(_x - other._x, _y - other._y));}
		vect2 operator*(const int n) const {return  vect2(_x * n, _y * n);}

		friend vect2 operator*(const int n, const vect2 &o){return (vect2(o * n));}
		friend std::ostream& operator<<(std::ostream &os, const vect2 &other) {return  (os << "{" << other[0] << ", " << other[1] << "}");}
};

// class vect2 {
//     private:
//         int x;
//         int y;

//     public:
//         vect2();
//         vect2(const int nx, const int ny);
//         vect2(const vect2 &other);
//         vect2& operator=(const vect2& other);
//         ~vect2();

//         vect2   operator-(void) const;

//         int		operator[](const int index) const;
//         int		&operator[](const int index);

//         vect2	&operator++(void);
//         vect2	&operator--(void);
//         vect2   operator++(int);
//         vect2   operator--(int);

//         bool    operator!=(const vect2& other) const;
//         bool    operator==(const vect2& other) const;

//         vect2&  operator+=(const vect2& other);
//         vect2&  operator-=(const vect2& other);
//         vect2&  operator*=(const int n);

//         vect2   operator+(const vect2& other) const;
//         vect2   operator-(const vect2& other) const;
//         vect2	operator*(const int n) const;



//         friend std::ostream& operator<<(std::ostream& os, const vect2& other) {
//             os << "{" << other.x << ", "  << other.y << "}";
//             return (os);
//         }
//         friend vect2    operator*(const int n, const vect2& other) {
//             return (vect2(n * other.x, n * other.y));
//         }
// };


