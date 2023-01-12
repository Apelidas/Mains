#include "Lst.hpp"


void info_out(Account *array, int len)
{
	int i;

	i = 0;
	array[0].displayAccountsInfos();
	while (i < len)
	{
		array[i].displayStatus();
		i++;
	}
}

void log_recreate()
{
	{
	Account array[] = {42, 54, 957, 432, 1234, 0, 754, 16576};
	info_out(array, 8);
	array[0].makeDeposit(5);
	array[1].makeDeposit(765);
	array[2].makeDeposit(564);
	array[3].makeDeposit(2);
	array[4].makeDeposit(87);
	array[5].makeDeposit(23);
	array[6].makeDeposit(9);
	array[7].makeDeposit(20);
	info_out(array, 8);
	array[0].makeWithdrawal(50);
	array[1].makeWithdrawal(34);
	array[2].makeWithdrawal(657);
	array[3].makeWithdrawal(4);
	array[4].makeWithdrawal(76);
	array[5].makeWithdrawal(30);
	array[6].makeWithdrawal(657);
	array[7].makeWithdrawal(7654);
	info_out(array, 8);
	}
}

void test()
{
	Account test(123);

	std::cout << test.getNbAccounts() << '\n';
	std::cout << test.getNbDeposits() << '\n';
	std::cout << test.getNbWithdrawals() << '\n';
	test.displayAccountsInfos();
	test.displayStatus();
	test.makeDeposit(877);
	test.displayAccountsInfos();
	test.makeWithdrawal(580);
	test.displayAccountsInfos();
	test.makeWithdrawal(430);
}

int main()
{
	log_recreate();
}
