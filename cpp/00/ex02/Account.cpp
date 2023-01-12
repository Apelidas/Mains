
#include "Lst.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp()
{
	time_t	now = time(0);
	tm		*detail = localtime(&now);

	std::cout << '[' << std::setw(2) << std::setfill('0') << detail->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << detail->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << detail->tm_mday;
	std::cout << '_' << std::setw(2) << std::setfill('0') << detail->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << detail->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << detail->tm_sec;
	std::cout << "] ";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ';';
	std::cout << "total:" << _totalAmount << ';';
	std::cout << "deposits:" << _totalNbDeposits << ';';
	std::cout << "withdrawals:" << _totalNbWithdrawals << "\n";
}

void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	this->_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << this->_amount - deposit << ';';
	std::cout << "deposit:" << deposit << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "nb_deposits:" << this->_nbDeposits << '\n';
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "withdrawal:";
	if (this->_amount < withdrawal)
	{
		std::cout << "refused\n";
		return (0);
	}
	std::cout << withdrawal << ';';
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	_totalAmount -= withdrawal;
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << '\n';
	return (1);
}

int		Account::checkAmount( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this ->_amount << ';';
	std::cout << "deposits:" << this->_nbDeposits << ';';
	std::cout << "withdrawals:" << this->_nbWithdrawals << '\n';
}


Account::Account(int initial_deposit)
{
	this->_accountIndex = getNbAccounts();
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->checkAmount();
	_nbAccounts += 1;
	std::cout << "created\n";
}

Account::Account( void )
{
	this->_accountIndex = getNbAccounts();
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->checkAmount();
	_nbAccounts += 1;
	std::cout << "created\n";
}

Account::~Account()
{
	this->checkAmount();
	_nbAccounts -= 1;
	_totalAmount -= this->_amount;
	std::cout << "closed\n";
}
