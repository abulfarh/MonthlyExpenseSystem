/*
 * FileHandler.h
 *
 *  Created on: May 25, 2021
 *      Author: mercy
 * 
 * 

 */

#ifndef FileHandler_H
#define FileHandler_H



#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>

#include "Expense.h"


#include "wallet.h"
using namespace std;
namespace fs = std::filesystem;







class FileHandler {
private:
	fstream textFile;
	int nofExpenses ; // gets this number to give it to number of expenses
	int nofWallets ; // num of wallets exist in the folder



public:
	
	//this to split string used for date 
	static vector<string>  split(string s, string del = ",");
	

	//expense section

	void countExpenses();

		
	
	void saveExpense(exspense_info info);

	void eraseExpense(Expense expense);

	void rewriteExpense(Expense expense);

	vector<Expense> loadWallet(string walletFile);
//wallet section

	//void saveIncome(float income);
	void makeWallet(string name);

	Wallet findWallet(string walletName);

	void scanAllWallets();

	void deleteWallet(Wallet wallet);
	float totalPrices();
	//void loadWallet(string walletName);





	FileHandler();

	virtual ~FileHandler();
};


#endif

