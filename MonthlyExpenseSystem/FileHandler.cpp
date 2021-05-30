/*
 * FileHandler.cpp
 *
 *  Created on: May 25, 2021
 *      Author: Us
 */


#include "FileHandler.h"
//expenses section



vector<string> FileHandler::split(string s, string del)
{
	int start = 0;
	int end = s.find(del);
	int i = 0;
	vector<string> items(6);
	while (end != -1) {
		items[i] = s.substr(start, end - start);

		start = end + del.size();
		end = s.find(del, start);

		i++;
	}

	items[i] = s.substr(start, end - start);


	return items;
}

void FileHandler::countExpenses()
{
	textFile.open("Data\\wallet.txt");

	int begin = 0;

	string line;

	if (textFile.is_open())
	{

		while (getline(textFile,line,';'))
		{
			nofExpenses++;

			//cout << "Number of expenses" << nofExpenses;
		}

		textFile.close();
	}
	
}

void FileHandler:: saveExpense(exspense_info info)

	{
	if (info.amount != -1){
		textFile.open("Data\\wallet.txt", ios::app);

		if (textFile.is_open())
		{
			

		textFile << info.date << ',' << info.description 

			<< ',' << info.category << ',' << info.amount << ',' << info.price << ',' << info.name << ';';

					
		textFile.close();
		}
	}
	}

	void  FileHandler:: rewriteExpense(Expense expense)
	{

	}

	vector<Expense> FileHandler::loadWallet(string walletName)
	{

		countExpenses();

		vector <Expense> expenses(nofExpenses);
		if (nofExpenses < 1)
		{
			cout << "Looks like you haven't register any expenses yet";
			return   vector<Expense> (1);
		}
		

	


		textFile.open("Data\\wallet.txt");
		
		string line;
		if (textFile.is_open())
		{
			int i = 0;
			while (getline(textFile,line,';'))
			{
				exspense_info expenseInfo(split(line, ","));

				expenses[i] = Expense(expenseInfo);

				//cout << line;
				i++;
			}

			
			textFile.close();

		}
		


		return expenses;
	}

	void  FileHandler:: eraseExpense(Expense expense)
	{

	}

//wallet section


	Wallet FileHandler::findWallet(string walletName)
	{

		string foundedWallet = "";

		// this gets all the wallets names
		string path = "E:\\MonthlyExpenses-Manager-System-master (2)\\MonthlyExpenses-Manager-System-master\\MonthlyExpenseSystem\\Data";
		for (const auto& entry : fs::directory_iterator(path))
		{
			foundedWallet = entry.path().filename().string();
			if ( foundedWallet == walletName)
			{
				foundedWallet = entry.path().filename().string();

				cout << "the wallet     : " << foundedWallet << " has been found";
				break;
			}
			
			foundedWallet = "";

		}


		// needs to be revised
		Wallet wallet;

		if (foundedWallet == "")
			return wallet;


		else
		{
			
			return  wallet;
		}
		
	

	}

	void FileHandler::  scanAllWallets()
	{

		// this gets all the wallets names
		string path = "E:\\MonthlyExpenses-Manager-System-master (2)\\MonthlyExpenses-Manager-System-master\\MonthlyExpenseSystem\\Data";
		for (const auto& entry : fs::directory_iterator(path))
		{
			std::cout << entry.path().filename() << std::endl;


			nofWallets++;
		}

		cout << "Number of wallets found : " << nofWallets;
			
	}

	void FileHandler::   deleteWallet(Wallet wallet)
	{

	}
	/*
	void FileHandler::loadWallet(string walletFile)
	{
		walletFile = "Data\\" + walletFile;

		//const char* WalletName = fileDestination.c_str();



		textFile.open(walletFile);

		string line;
		if (textFile.is_open())
		{
			while (getline(textFile, line))
			{

				
				cout << line << '\n';


			}

			textFile.close();
		}


	}

	*/




	void FileHandler::  makeWallet( string name)
{
//output the txt file with wallet name
	name = "Data\\" + name;
	//const char * WalletName = name.c_str();


	//should check here if the file is already there
	 fstream WalletFile(name,ios::app);
	

}

FileHandler::FileHandler() {
	// TODO Auto-generated constructor stub

	nofWallets = 0;
	nofExpenses = 0;

}
float FileHandler::totalPrices()
{
	countExpenses();
	vector <Expense> expenses(nofExpenses);
	textFile.open("Data\\wallet.txt");

	string line;
	float total = 0;
	if (textFile.is_open())
	{
		int i = 0;
		while (getline(textFile, line, ';'))
		{
			exspense_info expenseInfo(split(line, ","));

			expenses[i] = Expense(expenseInfo);
			total += (expenses[i].get_amount()* expenses[i].get_price());
			i++;
		}
		textFile.close();

	}
	return total;
}
FileHandler::~FileHandler() {
	// TODO Auto-generated destructor stub
}

