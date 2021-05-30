

#include "FileHandler.h"
#include "Expense.h"

#include <vector>

#ifndef Wallet_H
#define  Wallet_H

class Wallet
{

private:
	string WalletName;
	vector<Expense>  expenses;
	float income;
public:
	Wallet();
	Wallet(string Walletname, int totalMoney);


	void saveIncome(float income);

	float loadIncome(string walletName);

	// independant function of any exact wallet : returns all wallets' incomes
	static float getTotalIncome(); 
	//expenses section

	void addExpense(Expense expense);

	void editExpense(Expense expense);

	void deleteExpense(Expense expense);


	void viewExpenses(vector<Expense> allExpenses);



	//see if there is left money to buy anything
	bool checkWallet();


	~Wallet();
};

#endif