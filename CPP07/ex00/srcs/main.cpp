/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:01:35 by clorin            #+#    #+#             */
/*   Updated: 2021/10/07 10:01:36 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "whatever.hpp"

typedef struct	s_complex
{
	double		reel;
	double		imagin;
}				t_complex;

class Animal
{
private:
	unsigned int	_weight;
	std::string		_name;

public:
	Animal(std::string const &name="Animal", unsigned int const &w = 0):_name(name), _weight(w){}
	virtual ~Animal(void){}
	unsigned int			getWeight(void) const {return (this->_weight);}
	std::string const		getName(void) const {return (this->_name);}
	Animal const & operator=(Animal const & copy) {_name = copy._name;_weight = copy._weight;return *this;}
	bool operator <=(Animal const &rhs) const {return (this->_weight <= rhs._weight);}
	bool operator >=(Animal const &rhs) const {return (this->_weight >= rhs._weight);}
};

void	class_test(void)
{
	Animal a("Elephan", 2000000);
	Animal b("Mouse", 10);

	std::cout << "a = (" <<a.getName()<< ","<< a.getWeight() << ")<"<<&a<<">\tb = ("<<b.getName()<<"," << b.getWeight()<<")<"<<&b<<">" << std::endl;

	std::cout << "The heaviest animal is " << ::max(a, b).getName() << std::endl; 

	::swap(a, b);
	std::cout << "***** After  swap *****" << std::endl;
	std::cout << "a = (" <<a.getName()<< ","<< a.getWeight() << ")\tb = ("<<b.getName()<<"," << b.getWeight()<<")" << std::endl;
	
	std::cout << "The lightest animal is " << ::min(a, b).getName() << std::endl; 
}

void	comple_test(void)
{
	t_complex a, b;

	a.reel = 42.0;
	a.imagin = 3;

	b.reel = 45.5;
	b.imagin = 4;

	std::cout << "***** Before swap *****" << std::endl;
	std::cout << "a = " << a.reel << " + i"<<a.imagin;
	std::cout << "\tb = " << b.reel << " + i"<<b.imagin<<std::endl;

	::swap(a, b);
	std::cout << "***** After  swap *****" << std::endl;
	std::cout << "a = " << a.reel << " + i"<<a.imagin;
	std::cout << "\tb = " << b.reel << " + i"<<b.imagin<<std::endl;
}

void	float_test(void)
{
	float a = 42.42f;
	float b = 42.52f;
	float c = 42.42f;

	std::cout << "***** Before swap *****" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a,b);
	std::cout << "***** After  swap *****" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	std::cout << "c = " << c << " in address : " << &c << std::endl;
	std::cout << "min(a, c) = " << min(a, c) << " in  address " << &min(a, c) <<" (second elem)"<< std::endl;
}

void	given_main(void)
{
	int		a = 2;
	int		b = 3;

	std::cout << "***** Before swap *****" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a,b);
	std::cout << "***** After  swap *****" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string	c = "chaine1";
	std::string d = "chaine2";

	std::cout << "***** Before swap *****" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "***** After  swap *****" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

}

int		main(void)
{
	std::cout << "********** Given Main **********" << std::endl;
	given_main();
	std::cout << std::endl << "********** with float **********" << std::endl;
	float_test();
	std::cout << std::endl << "********* with struct **********" << std::endl;
	comple_test();
	std::cout << std::endl << "********** with Class **********" << std::endl;
	class_test();
	return 0;
}
