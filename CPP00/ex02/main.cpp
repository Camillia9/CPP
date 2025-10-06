#include "Account.hpp"

int main() {
    Account compte0(42);
    Account compte1(54);
    Account compte2(957);
    Account compte3(432);
    Account compte4(1234);
    Account compte5(0);
    Account compte6(754);
    Account compte7(16576);
	Account::displayAccountsInfos();
	compte0.displayStatus();
	compte1.displayStatus();
	compte2.displayStatus();
	compte3.displayStatus();
	compte4.displayStatus();
	compte5.displayStatus();
	compte6.displayStatus();
	compte7.displayStatus();
	compte0.makeDeposit(5);
	compte1.makeDeposit(765);
	compte2.makeDeposit(564);
	compte3.makeDeposit(2);
	compte4.makeDeposit(87);
	compte5.makeDeposit(23);
	compte6.makeDeposit(9);
	compte7.makeDeposit(20);
	Account::displayAccountsInfos();
	compte0.displayStatus();
	compte1.displayStatus();
	compte2.displayStatus();
	compte3.displayStatus();
	compte4.displayStatus();
	compte5.displayStatus();
	compte6.displayStatus();
	compte7.displayStatus();
	compte0.makeWithdrawal(50);
	compte1.makeWithdrawal(34);
	compte2.makeWithdrawal(657);
	compte3.makeWithdrawal(4);
	compte4.makeWithdrawal(76);
	compte5.makeWithdrawal(90);
	compte6.makeWithdrawal(657);
	compte7.makeWithdrawal(7654);
	Account::displayAccountsInfos();
	compte0.displayStatus();
	compte1.displayStatus();
	compte2.displayStatus();
	compte3.displayStatus();
	compte4.displayStatus();
	compte5.displayStatus();
	compte6.displayStatus();
	compte7.displayStatus();
    return 0;  // Les destructeurs seront appelés automatiquement
}