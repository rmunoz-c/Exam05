#include "bigint.hpp"

static size_t decimal_to_size(const std::string& text) {
	if (text.size() > 9)
		return ~size_t(0);
	size_t number = 0;
	for (size_t index = 0; index < text.size(); ++index)
		number = number * 10 + size_t(text[index] - '0');
	return number;
}

bigint& bigint::operator+=(const bigint& other) 
{
	const std::string &other_value = other.value;
	const size_t other_size = other_value.size();
	size_t this_size = this->value.size();
	if (this_size < other_size)
		this->value.insert(0, other_value, 0, other_size - this_size);
	else
		this_size = other_size;
	const size_t total_size = this->value.size();
	char* write_ptr = &this->value[0] + total_size - 1;
	const char* read_ptr = other_value.data() + other_size - 1;
	int carry = 0;
	size_t i = 0;
	for (; i < this_size; ++i, --write_ptr, --read_ptr) {
		int sum = (*write_ptr - '0') + (*read_ptr - '0') + carry;
		carry = (sum >= 10);
		*write_ptr = char('0' + sum - 10 * carry);
	}
	for (; carry && i < total_size; ++i, --write_ptr) {
		if (*write_ptr == '9')
			*write_ptr = '0';
		else {
			++*write_ptr;
			carry = 0;
		}
	}
	if (carry)
		this->value.insert(this->value.begin(), '1');
	return *this;
}

bigint& bigint::operator<<=(const bigint& k) {
	if (this->value != "0")
		this->value.append(decimal_to_size(k.value), '0');
	return *this;
}

bigint& bigint::operator>>=(const bigint& k) {
	size_t shift = decimal_to_size(k.value);
	if (shift >= this->value.size())
		value = "0";
	else
		value.erase(value.size() - shift);
	return *this;
}