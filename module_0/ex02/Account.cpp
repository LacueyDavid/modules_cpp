#include <iomanip>
#include <ctime>
#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(){
	return _nbAccounts;
}

int Account::getTotalAmount(){
	return _totalAmount;
}

int Account::getNbDeposits(){
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(){
	return _totalNbWithdrawals;
}

Account::Account(int initial_deposit)
{
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created:" << std::endl;
}

Account::~Account(){
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" << std::endl;
};

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";";

	_amount += deposit;
	_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;

	std::cout	<< "deposit:" << deposit << ";"
				<< "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";";

	_amount -= withdrawal;
	if (checkAmount())
	{
		_amount += withdrawal;
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	_totalAmount -= withdrawal;
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	std::cout	<< "withdrawal:" << withdrawal << ";"
				<< "amount:" << _amount << ";"
				<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

void	Account::displayStatus(void) const{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals
				<< std::endl;
}
int		Account::checkAmount(void) const{
	return (_amount < 0);
}

void	Account::_displayTimestamp(){
	time_t time_ptr;
	struct tm *time;

	std::time(&time_ptr);
	time = localtime(&time_ptr);
	std::cout	<< "["
		<< time->tm_year + 1900
		<< std::setw(2) << std::setfill('0') << time->tm_mon + 1
		<< std::setw(2) << std::setfill('0') << time->tm_mday
		<< "_"
		<< std::setw(2) << std::setfill('0') << time->tm_hour
		<< std::setw(2) << std::setfill('0') << time->tm_min
		<< std::setw(2) << std::setfill('0') << time->tm_sec
		<< "] ";
}

void Account::displayAccountsInfos(){
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals() << std::endl;
}
