#ifndef BASE_HPP
# define BASE_HPP

class Base {
	public:
		Base();
		Base(Base const &);
		Base & operator=(Base const &){return *this;}
		virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
