#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint {
	std::string value;

public:
	bigint() : value("0") {}
	bigint(int n) : value() { if (n < 0) n = 0; do { value.insert(value.begin(), char('0' + n % 10)); n /= 10; } while (n); }
	explicit bigint(const std::string& v) : value(v.find_first_not_of('0') == std::string::npos ? "0" : v.substr(v.find_first_not_of('0'))) {}
	bigint(const bigint& other) : value(other.value) {}
	bigint& operator=(const bigint& other) { value = other.value; return *this; }
	~bigint() {}

	bigint& operator+=(const bigint& other);
	bigint& operator<<=(const bigint& k);
	bigint& operator>>=(const bigint& k);

	bigint& operator++() { return *this += 1; }
	bigint operator++(int) { bigint t(*this); *this += 1; return t; }

	friend bigint operator+(bigint a, const bigint& b) { return a += b; }
	friend bigint operator<<(bigint a, const bigint& k) { return a <<= k; }
	friend bigint operator>>(bigint a, const bigint& k) { return a >>= k; }

	friend bool operator<(const bigint& a, const bigint& b)
		{ return a.value.size() != b.value.size() ? a.value.size() < b.value.size() : a.value < b.value; }
	friend bool operator==(const bigint& a, const bigint& b) { return a.value == b.value; }
	friend bool operator>(const bigint& a, const bigint& b) { return b < a; }
	friend bool operator<=(const bigint& a, const bigint& b) { return !(b < a); }
	friend bool operator>=(const bigint& a, const bigint& b) { return !(a < b); }
	friend bool operator!=(const bigint& a, const bigint& b) { return !(a == b); }

	friend std::ostream& operator<<(std::ostream& os, const bigint& b) { return os << b.value; }
};

#endif