/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:03:33 by tkong             #+#    #+#             */
/*   Updated: 2023/02/11 18:34:13 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account( void ) {}
Account::Account( int initial_deposit ) : 
	_accountIndex(_nbAccounts), 
	_amount(initial_deposit), 
	_nbDeposits(), 
	_nbWithdrawals()
{
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << ' '
		<< "index:" << _accountIndex << ';'
		<< "amount:" << _amount << ';'
		<< "created\n";
}
Account::~Account( void ) {
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	_displayTimestamp();
	std::cout << ' '
		<< "index:" << _accountIndex << ';'
		<< "amount:" << _amount << ';'
		<< "closed\n";
}

int		Account::getNbAccounts( void ) { return _nbAccounts; }
int		Account::getTotalAmount( void ) { return _totalAmount; }
int		Account::getNbDeposits( void ) { return _totalNbDeposits; }
int		Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << ' '
		<< "index:" << _accountIndex << ';'
		<< "p_amount:" << _amount << ';';
	if (deposit < 0) {
		std::cout << "deposit:refused\n";
		return;
	}
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "deposit:" << deposit << ';'
		<< "amount:" << _amount << ';'
		<< "nb_deposits:" << _nbDeposits << '\n';
}
bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << ' '
		<< "index:" << _accountIndex << ';'
		<< "p_amount:" << _amount << ';';
	if (withdrawal < 0 || withdrawal > _amount) {
		std::cout << "withdrawal:refused\n";
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ';'
		<< "amount:" << _amount << ';'
		<< "nb_withdrawals:" << _nbWithdrawals << '\n';
	return true;
}
int		Account::checkAmount( void ) const { return _amount; }

void	Account::_displayTimestamp( void ) {
	std::time_t timer = std::time(nullptr);
	struct tm* t = std::localtime(&timer);
	std::cout << '['
		<< std::string(4 - (int) std::to_string(t->tm_year + 1900).size(), '0')
		<< t->tm_year + 1900
		<< std::string(2 - (int) std::to_string(t->tm_mon + 1).size(), '0')
		<< t->tm_mon + 1
		<< std::string(2 - (int) std::to_string(t->tm_mday).size(), '0')
		<< t->tm_mday
		<< '_'
		<< std::string(2 - (int) std::to_string(t->tm_hour).size(), '0')
		<< t->tm_hour
		<< std::string(2 - (int) std::to_string(t->tm_min).size(), '0')
		<< t->tm_min
		<< std::string(2 - (int) std::to_string(t->tm_sec).size(), '0')
		<< t->tm_sec
		<< ']';
}
void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << ' '
		<< "accounts:" << getNbAccounts() << ';'
		<< "total:" << getTotalAmount() << ';'
		<< "deposits:" << getNbDeposits() << ';'
		<< "withdrawals:" << getNbWithdrawals() << '\n';
}
void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << ' '
		<< "index:" << _accountIndex << ';'
		<< "amount:" << _amount << ';'
		<< "deposits:" << _nbDeposits << ';'
		<< "withdrawals:" << _nbWithdrawals << '\n';
}
