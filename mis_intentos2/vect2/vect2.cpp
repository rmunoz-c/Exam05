
#include "vect2.hpp"

vect2::vect2()
{
	this->_vec.push_back(0);
	this->_vec.push_back(0);
}

vect2::vect2(int v1, int v2)
{
	this->_vec.push_back(v1);
	this->_vec.push_back(v2);
}

vect2::vect2(const vect2 &other) : _vec(other._vec)
{
}

vect2::~vect2()
{

}

vect2 vect2::operator-()const
{
	vect2 res;
	res._vec[0] = this->_vec[0] * -1;
	res._vec[1] = this->_vec[1] * -1;
	return (res);
}

int &vect2::operator[](int i)
{
	if (i == 0 || i == 1)
		return (this->_vec[i]);
	return (this->_vec[0]);
}

const int &vect2::operator[](int i)const
{
	if (i == 0 || i == 1)
		return (this->_vec[i]);
	return (this->_vec[0]);
}










vect2 operator*(int scalar, const vect2 &v)
{
	return (v * scalar);
}

std::ostream &operator<<(std::ostream out, const vect2 &v)
{
	out << "{" << v.getx() << ", " << v.gety() << "}" << std::endl;
	return (out);
}