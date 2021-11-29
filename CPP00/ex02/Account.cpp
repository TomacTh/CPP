#include <ctime>
#include <iostream>
#include <ios>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ):_amount(initial_deposit)
{
	static	int index;

	this->_accountIndex = index++;
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;	
	Account::_totalAmount += initial_deposit;
	++Account::_nbAccounts;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl; 
}

Account::~Account( void )
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl; 
}

void	Account::_displayTimestamp(void)
{
	time_t		timer;
	struct tm*	t_info;

	time(&timer);
	t_info = localtime (&timer);
	std::cout << "[" << (1900 + t_info->tm_year) << t_info->tm_mon + 1 << t_info->tm_mday 
	<< "_" << t_info->tm_hour << t_info->tm_min << t_info->tm_sec << "] ";
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" 
	<< Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" 
	<< Account::_totalNbWithdrawals << std::endl;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" 
	<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	p_amount = _amount;

	Account::_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" 
		<< p_amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	++_nbWithdrawals;
	++Account::_totalNbWithdrawals;
	std::cout << "index:" << _accountIndex << ";p_amount:" 
	<< p_amount << ";withdrawal:" << withdrawal << ";amount:" 
	<< _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}


void	Account::makeDeposit(int deposit)
{
	int	p_amount; 
	
	p_amount = _amount;
	_amount += deposit;
	Account::_totalAmount += deposit;
	++_nbDeposits;
	++Account::_totalNbDeposits;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" 
	<< deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}


int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

