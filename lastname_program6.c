/*COP 2220  (program 6) -
//add you name, date and description here*/

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings

#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower and toupper

//function prototypes

void MenuSelection(char* selectionPtr);
//input the selection variable by reference ("address of")
//displays the menu otions and gets the character from the user

void OneItemOrder(double *totalPtr);
//input: total by reference ("address of")
//allows the user to order a quantity of one item and updates the total

//ADD THE OTHER PROTOTYPES


int main()
{
	double balanceInMain,balanceFromFile = 0.0;
	double itemTotal = 0.0, orderTotal = 0.0;
	char selection;
	FILE* inPtr, * outPtr;//declare file pointers
	//DO NOT DECLARE char or double points use "address of" &

	//greet the user
		
	inPtr = fopen("foodAccountBalance.txt", "r"); //connect to the file
	fscanf(inPtr, "%lf", &balanceFromFile); //read the balance from the file

	balanceInMain = balanceFromFile;//keep the balance from file in case you need to reset (select 'N')
	//display the balance

	//MenuSelection(&selection); //call the MenuSelection function

	//while (selection != 'Q' && selection != 'q')
	{
		//if (selection == 'A' || selection == 'a')
		{
			//OneItemOrder(&itemTotal); //add one item to the order 
		}

		//add the other options, 'C'(checkout) and 'N'(reset)

		//else
		{
			//printf("\nnot recognized");
		}

		//call the MenuSelection function for the update
	}

	outPtr = fopen("foodAccountBalance.txt", "w");//connect to the file to save the balance
	fprintf(outPtr, "%f", balanceInMain);//save the balance

	//say goodbye to the user
	return 0;
}

void OneItemOrder(double *totalPtr)
{
	double price = 0.0;
	double total = 0.0;
	int itemNumber;
	*totalPtr = 0.0; //set the "value at" itemTotal to 0

	//display the items for purchase - call the DisplayFoodSelections function and it will return the item number
	//call DisplayFoodSelections

	//print the item number to check that the function is working as expected
	
	//set the price of the item - call the SetPrice function
	
	//get the quantity and add it to the total - call the AddQuantityToOrder function
	//*totalPtr = AddQuantityToOrder(price);

}

void MenuSelection(char* selectionPtr)
{
	//display the choices (A, C, N, Q)
	//use scanf to get the choice
}

//the rest of the functions are from PROGRAM 4