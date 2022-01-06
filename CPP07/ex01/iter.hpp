#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void	iter(T *arr, size_t length, void (*f)(T&))
{
	for (size_t i = 0; i < length; i++) {
		f(arr[i]);
	}
}

template < typename T>
void	toupper_custom(T &c)
{
	c = toupper(static_cast<int>(c));
}

template < typename T>
void	inc(T &c)
{
	++c;
}

template < typename T>
void	print(T &c)
{
	std::cout << c << std::endl;
}



#endif
