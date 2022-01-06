#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <typename T>
class Array {
	public:
		Array<T>(void) : _arr(new T[0]), _size(0) {}
		Array<T>(unsigned int n) : _arr(new T[n]), _size(n) {}
		Array<T>(Array const & src) {*this = src;}
		virtual ~Array<T>(void){delete [] _arr;}

		Array const &	operator=(Array const &rhs) {
			if (this != &rhs) {
				_size = rhs._size;
				_arr = new T[_size];
				for (unsigned int i = 0; i < _size; i++) {
					_arr[i] = rhs._arr[i];
				}
			}
			return (*this);
		}

		T	&operator[](unsigned int n) throw (std::exception) {
			if (n >= _size)
				throw std::exception();
			else
				return _arr[n];
		}

		unsigned int	size(void) const {return _size;}
	private:
		T				*_arr;
		unsigned int	_size;
};

#endif
