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
# include "iter.hpp"

typedef struct	s_complex
{
	double		reel;
	double		imagin;
}				t_complex;

class Character
{
private:
	unsigned int	_level;
	std::string		_name;

public:
	Character(std::string const &name="Character", unsigned int const &l = 0):_name(name), _level(l){}
	virtual ~Character(void){}
	unsigned int			getLevel(void) const {return (this->_level);}
	std::string const		getName(void) const {return (this->_name);}
	Character const & operator=(Character const & copy) {_name = copy._name;_level = copy._level;return *this;}
	bool operator <=(Character const &rhs) const {return (this->_level <= rhs._level);}
	bool operator >=(Character const &rhs) const {return (this->_level >= rhs._level);}
	Character operator++(int) {Character old = *this; this->operator++(); return old;}
	Character &operator++(){this->_level++; return *this;}
};

std::ostream &	operator<<(std::ostream &o, t_complex const &c)
{
	o << c.reel << " i"<< c.imagin;
	return o;
}

std::ostream &	operator<<(std::ostream &o, Character const &character)
{
	o << "<" << character.getName() << "> ("<< character.getLevel() << ")";
	return o;
}

template <typename T>
void	print_elem(T &el)
{
	std::cout << " [" << el << "]";
}

template <typename T>
void	increment_elem(T &el)
{
	el ++;
}

void	class_test(void)
{
	Character		tab[2] = {Character("Bilbon", 5), Character("Gandalf", 10)};

	std::cout << "tab[] = ";
	::iter(tab, 2, print_elem);
	std::cout << std::endl;
	std::cout << " -- increment() --" << std::endl;
	::iter(tab, 2, increment_elem);
	std::cout << "tab[] = ";
	::iter(tab, 2, print_elem);
	std::cout << std::endl;
}

void	comple_test(void)
{
	t_complex	tab[2]= {{42.0,3},{45.5,4}};

	std::cout << "tab[] = ";
	::iter(tab, 2, print_elem);
	std::cout << std::endl;
}

void	float_test(void)
{
	float		tab[5] = {0.0f, 1.4f, 2.42f, 3.03f, 42.42f};

	std::cout << "tab[] = ";
	::iter(tab, 5, print_elem);
	std::cout << std::endl;
	std::cout << " -- increment() --" << std::endl;
	::iter(tab, 5, increment_elem);
	std::cout << "tab[] = ";
	::iter(tab, 5, print_elem);
	std::cout << std::endl;
}

void	int_test(void)
{
	int		tab[5] = {0,1, 2, 3, 4};

	std::cout << "tab[] = ";
	::iter(tab, 5, print_elem);
	std::cout << std::endl;
	std::cout << " -- increment() --" << std::endl;
	::iter(tab, 5, increment_elem);
	std::cout << "tab[] = ";
	::iter(tab, 5, print_elem);
	std::cout << std::endl;
}

void	char_test(void)
{
	char	tab[5] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << "tab[] = ";
	::iter(tab, 5, print_elem);
	std::cout << std::endl;
	std::cout << " -- increment() --" << std::endl;
	::iter(tab, 5, increment_elem);
	std::cout << "tab[] = ";
	::iter(tab, 5, print_elem);
	std::cout << std::endl;
}

int		main(void)
{
	std::cout << "********** With array of INT **********" << std::endl;
	int_test();
	std::cout << std::endl << "********** with float **********" << std::endl;
	float_test();
	std::cout << std::endl << "********** with  char **********" << std::endl;
	char_test();
	std::cout << std::endl << "********* with struct **********" << std::endl;
	comple_test();
	std::cout << std::endl << "********** with Class **********" << std::endl;
	class_test();
	return 0;
}
