#include <stdio.h>
#include <stdlib.h>

unsigned int totalNights = 0;
unsigned int totalCharge = 0;
#define rate 400
#define minNights 1
#define maxNights 14
#define smallDiscount 50
#define largeDiscount 100
#define fullPriceNights 3
#define smallDiscountNights 6
#define ownerSummary -1

void startProgram();
void displaySummary();
int calculateCharge(int nights);
int validateData();
void clearInputBuffer();
int validInt(int input);


int main(){
		startProgram();
}

void startProgram() {
	int inputNum = 0;
	int charge = 0;

	do {
		inputNum = validateData();
		if (inputNum == -1)
		{
			displaySummary();
		}

		else if (inputNum >= minNights && inputNum <= maxNights)
		{
			charge = calculateCharge(inputNum);
			printf("Thank you for choosing to stay with us at AirUCCS! %d nights will cost %d.\n\n", inputNum, charge);
			totalNights += inputNum;
			totalCharge += charge;
		}
	} while (inputNum != -1);
}
int validateData() {
	int customerInput = 0;
	int validation = 0;

	printf("Enter the number of nights you would like to stay between %d and %d.\n", minNights, maxNights);
	validation = scanf("%d", &customerInput);

	while (!validation || !validInt(customerInput))
	{

		clearInputBuffer();
		
			printf("Invalid. Please enter a number between %d and %d\n", minNights, maxNights);
			validation = scanf("%d", &customerInput);

	}

	return customerInput;


}

void clearInputBuffer() {
	while (getchar() != '\n');
}

int validInt(int input)
{
	return (input >= minNights && input <= maxNights) || input == ownerSummary;
}

int calculateCharge(int nights)
{

	if (nights <= fullPriceNights)
		return nights * rate;
	else if (nights <= smallDiscountNights)
		return (fullPriceNights * rate) + ((nights - fullPriceNights) * (rate - smallDiscount));
	else
		return (fullPriceNights * rate) + ((smallDiscountNights - fullPriceNights) * (rate - smallDiscount)) + ((nights - (smallDiscountNights)) * (rate - largeDiscount));
}

void displaySummary() {
	printf("%d nights have been rented out for a total of $%d \n", totalNights, totalCharge);
}


