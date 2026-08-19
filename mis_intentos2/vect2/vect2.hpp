#include <iostream>
#include <vector>

class vect2
{
	private:
		std::vector<int> _vec;

	public:
		vect2();
		vect2(int a, int b);
		vect2(const vect2 &src);
		vect2 &operator=(const vect2 &src);

		~vect2();

		int getx()const;
		int gety()const;

		vect2 operator-()const;

		int &operator[](int index);
		const int &operator[](int index)const;

		vect2 &operator++(void);
		vect2 &operator--(void);
		vect2 operator++(int);
		vect2 operator--(int);

		bool operator==(const vect2 &other)const;
		bool operator!=(const vect2 &other)const;

		vect2 &operator=(const vect2 &other);
		vect2 &operator+=(const vect2 &other);
		vect2 &operator-=(const vect2 &other);
		vect2 &operator*=(const vect2 &other);
		vect2 &operator*=(int i);

		vect2 operator+(const vect2 &other)const;
		vect2 operator+(int i)const;
		vect2 operator-(const vect2 &other)const;
		vect2 operator-(int i)const;
		vect2 operator*(const vect2 &other)const;
		vect2 operator*(int i)const;
	
};
std::ostream &operator<<(std::ostream &out, const vect2 &v);
vect2 operator*(int scalar, const vect2 &v);