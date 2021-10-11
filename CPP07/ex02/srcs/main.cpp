/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:56:37 by clorin            #+#    #+#             */
/*   Updated: 2021/10/07 14:56:38 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <string>

# define C_GREEN    "\e[32m"
# define C_RED      "\e[31m"
# define C_YELLOW   "\e[33m"
# define C_CYAN     "\e[34m"
# define C_RESET    "\e[0m"

# define MAX_VAL 10


/******************************************************************************
*                               Struct Complex numbers                        *
* *****************************************************************************/
typedef struct  s_complex
{
    double      reel;
    double      imagin;
}               t_complex;

std::ostream &  operator<<(std::ostream &o, t_complex const &c)
{
    o << c.reel << " i"<< c.imagin;
    return o;
}

/******************************************************************************
 *                              Class Character
 * ****************************************************************************/

class Character
{
private:
    unsigned int    _level;
    std::string     _name;

public:
    Character(std::string name="Character", unsigned int l = 0):_name(name), _level(l){}
    virtual ~Character(void){}
    unsigned int            getLevel(void) const {return (this->_level);}
    void                    setLevel(unsigned int &level) {this->_level = level;}
    std::string const       getName(void) const {return (this->_name);}
    void                    setName(std::string const &name) {this->_name = name;}
    Character const & operator=(Character const & copy) {_name = copy._name;_level = copy._level;return *this;}
/*    bool operator <=(Character const &rhs) const {return (this->_level <= rhs._level);}
    bool operator >=(Character const &rhs) const {return (this->_level >= rhs._level);}
    Character operator++(int) {Character old = *this; this->operator++(); return old;}
    Character &operator++(){this->_level++; return *this;}*/
};

std::ostream &  operator<<(std::ostream &o, Character const &character)
{
    o << "<" << character.getName() << "> level : "<< character.getLevel();
    return o;
}

/********************************************************************************
 *                       T e s t s    of     C l a s s                          *
 * *****************************************************************************/
void        test_Class(void)
{
   Array<Character> numbers(MAX_VAL);
    
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        unsigned int value = rand() % MAX_VAL;
        std::string name = "Character #";
        name.append(std::to_string(value));
        value = rand() % 100;

        numbers[i].setName(name);
        numbers[i].setLevel(value);
    }
    {
        Array<Character> tmp = numbers;
        Array<Character> test(tmp);

        std::cout << "**************      Memory      ************" << std::endl;
        std::cout << C_CYAN << "numbers\t\ttmp=\t\ttest(tmp)"<<C_RESET << std::endl;
        for (size_t i = 0; i < MAX_VAL; i++)
        {
            std::cout << &numbers[i] << "\t" << &tmp[i] << "\t" << &test[i] << "\t --> ";
            if (&numbers[i] != &tmp[i] && &tmp[i] != &test[i])
                std::cout << C_GREEN << "OK";
            else
                std::cout << C_RED << "KO";
            std::cout << C_RESET << std::endl;
        }

        /*we change the value of the 2 copy tmp & test to control the deep copy */
        for (size_t i = 0; i < MAX_VAL; i++)
        {
            unsigned int new1 = tmp[i].getLevel() + 1;      
            unsigned int new2 = test[i].getLevel() + 2;
            tmp[i].setLevel(new1);
            test[i].setLevel(new2);
        }
        bool    test_modif_cpy = true;
        for (size_t i = 0; i < MAX_VAL; i++)
        {
            /* the difference must be 1*/
            test_modif_cpy = test_modif_cpy && (tmp[i].getLevel() - numbers[i].getLevel() == 1);    
            test_modif_cpy = test_modif_cpy && (test[i].getLevel() - tmp[i].getLevel() == 1);
        }
        std::cout << "modif test = " << ((test_modif_cpy)? "\e[32mTrue":"\e[31mFalse")<< C_RESET << std::endl;
    }

    try
    {
        std::cout << "Trying to acces numbers[-2] ... ";
        std::cout << numbers[-2] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Trying to acces numbers[MAX_VAL] ... ";
        numbers[MAX_VAL].getLevel();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "numbers[" << i << "] = rand() = " ;
        unsigned value = rand() % 200;
        numbers[i].setLevel(value);
        std::cout << numbers[i]<< std::endl;
    }
}

/********************************************************************************
 *                       T e s t s    of     S t r u c t                        *
 * *****************************************************************************/
void        test_complex(void)
{
    Array<t_complex> numbers(MAX_VAL);
    
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i].reel = value;
    }
    {
        Array<t_complex> tmp = numbers;
        Array<t_complex> test(tmp);

        std::cout << "**************      Memory      ************" << std::endl;
        std::cout << C_CYAN << "numbers\t\ttmp=\t\ttest(tmp)"<<C_RESET << std::endl;
        for (size_t i = 0; i < MAX_VAL; i++)
        {
            std::cout << &numbers[i] << "\t" << &tmp[i] << "\t" << &test[i] << "\t --> ";
            if (&numbers[i] != &tmp[i] && &tmp[i] != &test[i])
                std::cout << C_GREEN << "OK";
            else
                std::cout << C_RED << "KO";
            std::cout << C_RESET << std::endl;
        }
    }

    try
    {
        std::cout << "Trying to acces numbers[-2] ... ";
        std::cout << numbers[-2] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Trying to acces numbers[MAX_VAL] ... ";
        numbers[MAX_VAL].imagin = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "numbers[" << i << "] = rand() = " ;
        numbers[i].imagin = rand();
        std::cout << numbers[i]<< std::endl;
    }  
}

/********************************************************************************
 *                       T e s t s    of     F l o a t s                        *
 * *****************************************************************************/

void        test_float(void)
{
    Array<float> numbers(MAX_VAL);
    
    float* mirror = new float[MAX_VAL];
    
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const float value = rand() / 3;
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<float> tmp = numbers;
        Array<float> test(tmp);

        std::cout << "**************      Memory      ************" << std::endl;
        std::cout << C_CYAN << "numbers\t\ttmp=\t\ttest(tmp)"<<C_RESET << std::endl;
        for (size_t i = 0; i < MAX_VAL; i++)
        {
            std::cout << &numbers[i] << "\t" << &tmp[i] << "\t" << &test[i] << "\t --> ";
            if (&numbers[i] != &tmp[i] && &tmp[i] != &test[i])
                std::cout << C_GREEN << "OK";
            else
                std::cout << C_RED << "KO";
            std::cout << C_RESET << std::endl;
        }
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return ;
        }
    }
    try
    {
        std::cout << "Trying to acces numbers[-2] ... ";
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Trying to acces numbers[MAX_VAL] ... ";
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "numbers[" << i << "] = rand() = " ;
        numbers[i] = rand();
        std::cout << numbers[i]<< std::endl;
    }
    delete [] mirror;
}

/********************************************************************************
 *                       T e s t s    of     I n t                              *
 * *****************************************************************************/

void        test_given(void)
{
    Array<int> numbers(MAX_VAL);
    
    int* mirror = new int[MAX_VAL];
    
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        std::cout << "**************      Memory      ************" << std::endl;
        std::cout << C_CYAN << "numbers\t\ttmp=\t\ttest(tmp)"<<C_RESET << std::endl;
        for (size_t i = 0; i < MAX_VAL; i++)
        {
            std::cout << &numbers[i] << "\t" << &tmp[i] << "\t" << &test[i] << "\t --> ";
            if (&numbers[i] != &tmp[i] && &tmp[i] != &test[i])
                std::cout << C_GREEN << "OK";
            else
                std::cout << C_RED << "KO";
            std::cout << C_RESET << std::endl;
        }
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return ;
        }
    }
    try
    {
        std::cout << "Trying to acces numbers[-2] ... ";
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Trying to acces numbers[MAX_VAL] ... ";
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "numbers[" << i << "] = rand() = " ;
        numbers[i] = rand();
        std::cout << numbers[i]<< std::endl;
    }
    delete [] mirror;
}

/********************************************************************************
 *                                  M A I N                                     *
 * *****************************************************************************/

int main(void)
{   
    std::cout << "--------------   With Integer   ----------------" << std::endl;
    test_given();
    std::cout << std::endl<< "--------------   With float   ----------------" << std::endl;
    test_float();
    std::cout << std::endl<< "--------------   With Struc nb Complex   ----------------" << std::endl;
    test_complex();
    std::cout << std::endl<< "--------------   With a Class    ----------------" << std::endl;
    test_Class();
    return 0;
}
