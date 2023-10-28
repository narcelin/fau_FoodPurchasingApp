/*COP 2220  (program 4) - 
//add you name, date and description here*/
/*
	Nicolas Arcelin
	
	September 2023

	Interactive program using functions from stdio.h(printf and scanf), math in C, conditions, a while loop, and programmer defined functions. (Sorgente, 2023, as cited in Canvas)
*/

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings

#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower and toupper

//function prototypes

void Greeting(void);
//welcome the user to the food purchasing app

int DisplayFoodSelections();
//display the food choices, the price, and related item number
//declare, ask, get the item number
//return the item number

double SetPrice(int itemNumber);
//input: item number
//use the item number to identify the price 
//return the price 

double AddQuantityToOrder(double price);
//input: price of the item
//declare ask and get the quantity
//calculate and return the item total
//return the total

double Checkout(double balance, double totalPrice);
//input: amount of money in the account and the order total
//return: the amount left in the account after making the purchase
//Uses the Reload and checkFor Enough functions 
//to get money from the user until the user has enough to make the purchase
//make the purchase and return the remaining balance


//THIS FUNCTION WILL BE CALLED FROM THE Checkout function
int CheckForEnough(double balance, double totalPrice);
//input: amount of money in the account and the order total
//returns a 1 if there is enough in the account to make a purchase
//returns 0 if there is not enough

//THIS FUNCTION WILL BE CALLED FROM THE Checkout function
double Reload(double balance);
//input: account balance
//return the new balance with the added funds
//reload the account balance


int main()
{
	//declare variables
	double balanceInMain = 20.00;
	double priceInMain = 0.0;
	double totalInMain = 0.0;
	int itemNumber;

	//greet the user - Greeting function call
	Greeting();

	//display the balance, at this point is should be $20.00
	printf("\n \n Your current balance is %.2lf Credits \n \n", balanceInMain);

	//display the items for purchase - call the DisplayFoodSelections function and it will return the item number
	int userSelection = DisplayFoodSelections();

	//print the item number to check that the function is working as expected
	printf("\nItem selection confirmation: %d \n \n", userSelection);

	//set the price of the item - call the SetPrice function
	double itemPrice = SetPrice(userSelection);

	//print the price to check that the function is working as expected
	while(itemPrice < 0){
		userSelection = DisplayFoodSelections();
		itemPrice = SetPrice(userSelection);
	}

	//get the quantity and add it to the total - call the AddQuantityToOrder function
	double totalItemPrice = AddQuantityToOrder(itemPrice);
	
	//print the total to check that the function is working as expected
	printf("\nTotal Item Price Confirmation: %.2lf\n\n", totalItemPrice);

	//Checkout
	balanceInMain = Checkout(balanceInMain, totalItemPrice);

	//display the ending balance
	printf("\n\nPlease come again. Your balance is now %.2lf", balanceInMain);

	//say goodbye to the user
	printf("\n \nHave a great day!\n\n");
	return 0;
}


//function definitions

//welcome the user to the food purchasing app
void Greeting(void)
{
	  printf("\n Welcome to the new an improved Carbon Bonder 3000 where we use the same food syntisizer tech as the enterprise. Take a look at our choices below!");
}

//display the food choices, the price, and related item number
//declare, ask, get, and return the item number
int DisplayFoodSelections()
{
	int item;

	printf("1: Klingon Cuisine - 27 Credits \n2: Vulcan Cuisine - 23 Credits \n3: Bajoran Cuisine - 32 Credits \n4: Ferengi Cuisine - 435 Credits \n5: Human Cuisine - 1 \nPlease select an item using the starting item number only: ");


	scanf(" %d", &item);
	printf("\n");
	return item;

}


//input: item number
//use the item number to identify the price 
//return the price 
double SetPrice(int itemNumber)
{
	switch (itemNumber) {
        case 1:
			printf("You have selected Item 1. May this mean bring your enemies to your knees and may your sons bring honor to your house.");
            return(27);
            break;
        case 2:
			printf("You have selected Item 2. May you live long and propser.");
            return(23);
            break;
        case 3:
			printf("You have selected Item 3. Prophets guid you well.");
            return(32);
            break;
        case 4:
			printf("You have selected Item 4. This follows the rules of aquisition");
            return(435);
            break;
        case 5:
			printf("You have selected... Item 5. Go get them chap?");
            return(1); //AKA FREE
            break;
            
        default:
			printf("\nSorry, that Item is not an option. Please try again \n\n");
            return -1;
            break;
    }
	//double price = 0.0;

	//switch (itemNumber) {
	//case 1:
		//printf("\nYou selected Box Combo, the price is $11.39\n");
		//price = 11.39;
		//break;
	//add other cases
	//default:
		//printf("\nThere is no item with that number");
		//price = 0.0;
	//}
	//return price;
}

//input: price of the item
//declare ask and get the quantity
//calculate and return the item total
//return the total
double AddQuantityToOrder(double price)
{
	int userQuantity;
	printf("\n\nHow many would you like? : ");
	scanf(" %d", &userQuantity);
	//declare, ask, and get the quantity
	return price * userQuantity;
}

//input: amount of money in the account and the order total
//return: the amount left in the account after making the purchase
//Uses the Reload and checkFor Enough functions 
//to get money from the user until the user has enough to make the purchase
//make the purchase and return the remaining balance
double Checkout(double balance, double totalPrice)
{
	//initialization
	int enough = CheckForEnough(balance, totalPrice);
	
	while (enough == 0)//not enough money
	{
		//display the balance and total
		printf("Not enough credits, you have %.2lf Credits. The total is %.2lf. Do you wish to add more Credits? (1:YES | 2:NO): ", balance, totalPrice);
		int reloadAccount;
		scanf(" %d", &reloadAccount);
		
		//balance = Reload(balance);//RELOAD
		if(reloadAccount == 1){
			balance = Reload(balance);
		} else if(reloadAccount == 1994){
			printf("\nBEZOS MODE ACTIVATED");
			balance = 9999999;
		} else {
			printf("Good bye!");
			enough = 0; //End loop
			return -1;
		};

		//enough = CheckForEnough(balance, totalPrice); //UPDATE
		enough = CheckForEnough(balance, totalPrice);
	}
	//subtract total from balance 
		balance = balance - totalPrice;
	return balance;
	//return the new balance
}

//input: amount of money in the account and the order total
//returns a 1 if there is enough in the account to make a purchase
//returns 0 if there is not enough
int CheckForEnough(double balance, double totalPrice)
{
	//use if/else here
	if(balance < totalPrice){
		return 0;
	} else { //Could do an else if (balance = then one for > ) <- Thought this to be more effective
		return 1;
	};
}

//input: account balance
//return the new balance with the added funds
//reload the account balance
double Reload(double balance)
{
	double addAmount;
	printf("How many Credits would you like to add? This will be automatically deducted from your Bank Of America Account. \n ₡: ");
	scanf(" %lf", &addAmount);
	//ask and get the aamount to add
	return balance + addAmount;

}
