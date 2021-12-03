//A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019

#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include <unistd.h>
using namespace std; 
/*
struct MenuItem
{
  string name;
  double itemCost; 
  string desc; 
  char addLetter; 
  char removeLetter;
  int count; 
};
*/
class MenuItem
{
private:
	string name;
	double itemCost; 
	string desc; 
	char addLetter; 
	char removeLetter;
	int count; 

public:
	MenuItem()
	{
		name = "DefaultName";
		itemCost = 0.00;
		desc = "Default description";
		addLetter = 'A';
		removeLetter = 'X';
		count = 0;
	}
	void setName(string n) { name = n; }
	void setItemCost(double ic) { itemCost = ic; }
	void setDesc(string d) { desc = d; }
	void setAddLetter(char al) { addLetter = al; }
	void setRemoveLetter(char rl) { removeLetter = rl; }
	void setCount(int c) { count = c; }
	string getName() { return name; }
	double getItemCost() { return itemCost; }
	string getDesc() { return desc; }
	char getAddLetter() { return addLetter; }
	char getRemoveLetter() { return removeLetter; }
	int getCount() { return count; }
	void incrementCount() { count++; }
	void decrementCount() { count--; }
};

class Checkout
{
private:
	double tip;
	double tax;
	double totalDue;
	double tender;
	double change;
	char choice;
	bool paid_by_credit;

public:
	Checkout()
	{
		tip = 0.0;
		tax = 0.0;
		totalDue = 0.0;
		tender = 0.0;
		change = 0.0;
		choice = '\0';
		paid_by_credit = true;
	}
	void payment(double &subtotal)
	{
	    cout << "\nWould you like to enter a tip?\n"
			 << "Recommended tip is 20% which would be $" << subtotal * 0.20
			 << "\n >> ";
		cin >> tip;
		cout << "\nYou entered a tip of $" << tip << endl
			 << "Thank you!\n\n";
		
		totalDue += subtotal + tax + tip;

		cout << "Please select a payment method\n"
			 << "1) Credit Card\n"
			 << "2) Cash\n"
			 << " >> ";
		cin >> choice;

		if (choice == '1')
		{
			cout << "Processing credit card payment...\n";
			paid_by_credit = true;
		}
		else if (choice == '2')
		{
			cout << "Enter a cash amount (Total due = $" << totalDue << ")\n"
				 << " >> ";
			cin >> tender;
			if (tender >= totalDue)
			{
				change = tender - totalDue;

				cout << "Your change for this transaction is $" << change << endl;
			}
			cout << "Processing cash payment...\n";
			paid_by_credit = false;
		}
		cout << "Done!\n\n";
	}
	void printReciept(vector<MenuItem> &m, double &subtotal)
	{
		cout << "DrT's Efficient Menu Reciept\n"
			 << "----------------------------\n";
			 cout << "Item" << setw(10) << "Cost" << setw(15) << "Count" << endl;
		for(int i = 0; i < m.size(); i++)
  		{
			cout << m[i].getName() << setw(5) << "$" << m[i].getItemCost() << setw(5) << m[i].getCount() << endl << endl;
		}
		cout << "Sub Total" << setw(10) << "$" << subtotal << endl
			 << "Sales Tax" << setw(10) << "$" << tax << endl
			 << "Tip" << setw(15) << "$" << tip << endl
			 << "-----------------------------\n"
			 << "TOTAL" << setw(15) << "$" << totalDue << endl
			 << "-----------------------------\n";
		if (paid_by_credit)
		{
			cout << "Paid By:" << setw(15) << "Credit\n";
		}
		else if (!paid_by_credit)
		{
			cout << "Paid By:" << setw(15) << "Cash\n\n";
		}
	}
};

//function definitions
void populateMenu(vector<MenuItem> &entireMenu)
{
  //put some default values in our Menu
  const int numItems = 7; 
  MenuItem Item1; 
  MenuItem Item2;
  MenuItem Item3; 
  MenuItem Item4;
  MenuItem Item5;
  MenuItem Item6;
  MenuItem Item7;    

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item4
  entireMenu.push_back(Item5); //add to the end of list the Item5
  entireMenu.push_back(Item6); //add to the end of list the Item6
  entireMenu.push_back(Item7); //add to the end of list the Item7

  vector<string> defaultMenuNames = {"Green Tea", "Burrito", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entireMenu[i].setName(defaultMenuNames[i]); 
    entireMenu[i].setAddLetter(defaultAddLetters[i]); 
    entireMenu[i].setRemoveLetter(defaultRemoveLetters[i]); 
    entireMenu[i].setItemCost(3.00 + i); //set a random starter cost for each item
    entireMenu[i].setCount(0); //initialze all counts to 0
    entireMenu[i].setDesc("delicious"); //set all default desc to "delicous"
  }

}

void showMenu(vector<MenuItem> &m)
{
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout << "DrT's Effcient Menu" << endl; 
  cout << "ADD  \tNAME \t COST \tREMOVE\tCOUNT\tDESC"<<endl; 
  for(int i = 0; i < m.size(); i++)
  {
    cout << m[i].getAddLetter() << ")" << setw(10) << m[i].getName() 
    << setw(5) << "$" << m[i].getItemCost() << setw(5) << "(" << m[i].getRemoveLetter()
    << ")" << setw(7) << m[i].getCount() << setw(13) << m[i].getDesc() 
    <<endl; 
  }

}

void acceptOrder(vector<MenuItem> &m, double &subtotal)
{
  char option = '\0';// the user-selected menu item

  do
  {
    cout << "\nPlease choose an item (x to Exit): ";
    cin >> option; 

    for(int i=0; i < m.size(); i++)
    {
      if(option == m[i].getAddLetter())
      {
        cout << "\nMenu Item " << m[i].getAddLetter() << " selected."; 
        m[i].incrementCount(); //increment the count by 1
        cout << "\033[2J\033[1;1H"; //clear screen 
        cout << "\n1 UP on " << m[i].getName() << endl;
        subtotal += m[i].getItemCost(); //increment the subtotal by the cost of the item 
        showMenu(m); //show the updated menu
        cout << "\nSubtotal: $" << subtotal << endl;  
      }
      else if(option == m[i].getRemoveLetter())
      {
        cout << "\nRemove Item " << m[i].getRemoveLetter() << " selected."; 
        if(m[i].getCount() > 0) //subtract if and only if the count is > 0
        {
          m[i].decrementCount(); //decrement the count by 1
          cout << "\033[2J\033[1;1H"; //clear screen 
          cout << "\n1 DOWN on " << m[i].getName() << endl;
          subtotal -= m[i].getItemCost(); //decrement the subtotal by the cost of the item
          showMenu(m); //show the updated menu
          cout << "\nSubtotal: $" << subtotal << endl;  
        }
        else //the the user why you blocked item removal 
        {
            
            cout << "\nItem count must be > 0 to remove: " << m[i].getName() << endl;
        }
      }
      else if(
                option != m[i].getAddLetter() && 
                option != m[i].getRemoveLetter() &&
                option != 'x' &&
                option != 'X' 
            ) //test for all of my valid inputs
            {
              if(i == 0)
              {
                cout << "\nInvalid input (" << option << "). Please try again." << endl; 
              }  
            }
    }
  }while(option != 'x' && option != 'X'); 
  cout << "\nThank you for placing your order." << endl; 
  //handle the tip process here
  //handle reciept generation here
}

int main() 
{
	char character = '\0';
	double subtotal = 0.0;
	do
	{
		vector<MenuItem> wholeMenu; 
		populateMenu(wholeMenu); //put some default values in the menu
		showMenu(wholeMenu); //print the current data of the menu on screen 
		acceptOrder(wholeMenu, subtotal); 

		Checkout checkout;
		checkout.payment(subtotal);
		checkout.printReciept(wholeMenu, subtotal);

		cout << "\nEnter any character to restart >> ";
		cin >> character;

		system("clear");
	} while (1);
  
  	return 0; 
}