/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:33:20 by clorin            #+#    #+#             */
/*   Updated: 2021/09/06 12:34:51 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// constructor ***********
Account::Account(int initial_deposit)
: _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    this->_accountIndex = Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
    //[19920104_091532] index:0;amount:42;created
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
    return;
}

// destructor ---------------
Account::~Account( void )
{
    //[19920104_091532] index:0;amount:47;closed
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
    return;
}

//statics ************************************
void    Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << " accounts:" << Account::_nbAccounts << ";total:" <<
    Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << 
    ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    char    buffer[18];
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,18,"[%Y%m%d_%H%M%S]",timeinfo);
    std::cout << buffer;
    //std::cout << "[19920104_091532]";       //TO simplifie test with reference log
}

// public *******************************

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void    Account::makeDeposit(int deposite)
{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposite;
    this->_amount += deposite;
    this->_nbDeposits++;
    Account::_totalAmount += deposite;
    Account::_totalNbDeposits++;
    std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;

}

bool    Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
    if (this->_amount >= withdrawal)
    {    
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals++;
        std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        return (true);
    }
    else
        std::cout << "refused" << std::endl;
    return (false);
}

int		Account::checkAmount( void ) const
{
    return(this->_amount);
}