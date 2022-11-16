#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <string.h>


// Function Declaration
void Developer_intro();
void main_menu();
void Seller_Book();
void Buy_A_Book();
int search();
void Buyers_Display();
void Sellers_Display();

void setcolor(int ForgC)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xB0) + (ForgC & 0x0B);
		//	SetConsoleTextAttributes(hStdOut,wColor);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

struct Seller_Details // STRUCTURE DECLARATION
{

	char Name[20];
	char Name_of_Book[10];
	char Author_name[10];
	char Address[25];
	char Email[20];
	char Phoneno[10];
	char Price[5];

};

struct Buyer_Details // STRUCTURE DECLARATION
{

	char Name[20];
	char Name_of_Book[10];
	char Author_name[10];
	char Address[25];
	char Email[20];
	char Phoneno[15];

};

// start of Main function
int main()
{
	Developer_intro();
	main_menu();
	return 0;
}
// End of the Main function

// For developer Introduction
void Developer_intro()
{	time_t t;
	time(&t);
	setcolor(15);
	printf("\n\t\t\t****************************");
	printf("\n\t\t\t* SECOND HAND BOOK BUUYING AND SELLING: THRIFTSHOP*");
	printf("\n\t\t\t****************************");
	printf("\n\n\t\tDeveloped By:");
	printf("\t RAJ GUPTA\n");
	for(int i=0;i<80;i++)
		printf("-");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(int i=0;i<80;i++)
		printf("-");
	printf("\n\n\n\n\n\n\n\t\t\t\t\tPress any key to Jump to main menu continue....!!");
	getchar();
}

// For Displaying the main menu

void main_menu()
{
	time_t t;
	time(&t);
	short int choice;
	while (choice != 5)
	{

		system("cls");
		printf("\n\t\t\t\t*************************");
		printf("\n\t\t\t\t SECOND HAND BOOK SHOP :THRIFTSHOP ");
		printf("\n\t\t\t\t      * MAIN MENU *");
		printf("\n\t\t\t\t*************************");
		printf("\n\n\n\t\t\t1.Sell A Book");
		printf("\n\t\t\t2.Buy A Book");
		printf("\n\t\t\t3.Books Booked ");
		printf("\n\t\t\t4.Get status");
		printf("\n\t\t\t5.Seller's");
		printf("\n\t\t\t6.Exit\n");
		

		for(int i=0;i<80;i++)
		printf("-");
	    printf("\nCurrent date and time : %s",ctime(&t));
		printf("\n\n\t\t\tEnter Your Choice: ");
		scanf("%hu", &choice);
		

		switch (choice)
		{

		case 1:
			Seller_Book();
			break;

		case 2:
			Buy_A_Book();
			break;

		case 3:
			Buyers_Display();
			break;

		case 4: // Delivery();
			break;

		case 5:
			Sellers_Display();
			break;
		case 6:
			system("cls");
			printf("\n\n\t *****THANK YOU*****");
			printf("\n\t FOR TRUSTING OUR SERVICE");
			//	Sleep(2000);
			exit(0);
			break;

		default:
		{

			printf("\n\n\t\t\tWrong choice.....!!!");
			printf("\n\t\t\tPress any key to   continue....!!");

			getch();
		}
		}
	}
}

// End of displaying main meu


// Seller function
void Seller_Book()
{
	FILE *f;
	char test;
	f = fopen("sellers_details.txt", "a+");
	if (f == 0)
	{
		f = fopen("sellers_details.txt", "w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while (1)
	{	struct Seller_Details input;
	
	
		system("cls");
		printf("\n Enter Seller Details:"); 
		printf("\n**************************\n");
		printf("Enter Name:\n");
		scanf("%s", input.Name);
		fflush(stdin);
		printf("Enter Subject of Book:\n");
		scanf("%s", input.Name_of_Book);
		fflush(stdin);
		printf("Enter Author Name:\n");
		fgets(input.Author_name, 10, stdin);
		printf("Enter Address:\n");
		fgets(input.Address, 25, stdin);
		fflush(stdin);
		printf("Enter Email:\n");
		scanf(" %s", input.Email);
		printf("Enter Phone Number:\n");
		scanf("%s", input.Phoneno);
		fflush(stdin);
		printf("Enter Price(\'x\'Rs):\n");
		scanf("%s", input.Price);
		fflush(stdin);
		fwrite(&input, sizeof(struct Seller_Details), 1, f);
		fputs("\n", f);
		printf("\n\n1 Book is successfully Added!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test = getche();
		if (test == 27)
			break;
	}
	fclose(f);
}

// Seller function end

// Seller display function
void Sellers_Display()
{
	FILE *f;
	
	char test;
struct Seller_Details input;
	if ((f = fopen("sellers_details.txt", "r")) == NULL)
	{
		exit(0);
	}
	
			system("cls");
			printf("NAME\t ");
			printf("subject\t");
			printf("Author\t");
			printf("\tADDRESS ");
			printf("\tEMAIL ");
			printf("\tPHONENUMBER ");
			printf("\t PRICE \n");

			for (int i = 0; i < 118; i++)
				printf("-");
while (1)
{
	

			while (fread(&input, sizeof(struct Seller_Details), 1, f))
			{
				printf("\n%s \t\t %s\t\t %s\t\t %s\t\t %s\t\t %s\t\t %s \n", input.Name, input.Name_of_Book, input.Author_name, input.Address, input.Email, input.Phoneno, input.Price);
			}
			printf("\n Press esc key to exit");
		test = getche();
		if (test == 27)
			break;
}
			fclose(f);
		
	}
// Seller display function ends


// Buyer display function
void Buyers_Display()
{
	struct Buyer_Details inp;
	FILE *f;
	char test;
	if ((f = fopen("Buyers_details.txt", "r")) == NULL)
	{
		exit(0);
	}
	
			system("cls");
			printf("NAME\t ");
			printf("subject\t");
			printf("Author\t");
			printf("\tADDRESS ");
			printf("\tEMAIL ");
			printf("\tPHONENUMBER\n");
		

			for (int i = 0; i < 118; i++)
				printf("-");
while (1)
{
	

			while (fread(&inp, sizeof(struct Buyer_Details), 1, f))
			{
				printf("\n%s \t\t %s\t\t %s\t\t %s\t\t %s\t\t %s \n", inp.Name, inp.Name_of_Book, inp.Author_name, inp.Address, inp.Email, inp.Phoneno);
			}
			printf("\n Press esc key to exit");
		test = getche();
		if (test == 27)
			break;
}
			fclose(f);
}


// Buyer display function ends

// Buyer function
void Buy_A_Book()
{
struct Buyer_Details inp;
	FILE *f;
	char test;
	f = fopen("Buyers_details.txt", "a+");
	if (f == 0)
	{
		f = fopen("Buyers_details.txt", "w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while (1)
	{
		system("cls");
		printf("\n Enter Buyer Details:");
		printf("\n**************************\n");
		int flag = search();
		if (flag == 0)
		{
			printf("\n Enter Name:\n");
			scanf("%s", inp.Name);
			fflush(stdin);
			printf("Enter Address:\n");
			scanf("%s", inp.Address);
			printf("Enter Phone Number:\n");
			scanf("%s", inp.Phoneno);
			printf("Enter Email:\n");
			scanf(" %s", inp.Email);
			fflush(stdin);
			fwrite(&inp, sizeof(struct Buyer_Details), 1, f);
		}
		printf("\n\nBook is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another Buyer detail:");
		test = getche();
		if (test == 27)
			break;
	}
	fclose(f);
}
// Buyer function ends

//search function starts 
int search()
{
	struct Buyer_Details inp;
	struct Seller_Details input;
	system("cls");
	FILE *f;
	char name_of_book[20];
	char Author_name[20];
	int flag = 1;
	int a, b;

	f = fopen("sellers_details.txt", "r+");
	if (f == 0)
	{
		exit(0);
	}
	printf("Enter the Book name: \n");
	scanf("%s", name_of_book);
	fflush(stdin);
	printf("Enter the Author name: \n");
	scanf("%s", Author_name);
	while (fread(&input, sizeof(struct Seller_Details), 1, f) == 1)
	{
		a = strcmp(input.Name_of_Book, name_of_book);
		b = strcmp(input.Author_name, Author_name);
		if ((a && b) != 0)
		{
			flag = 0;
			printf("\n\tBook Found\n ");
			   strcpy(inp.Name_of_Book, name_of_book);
			strcpy(inp.Author_name, Author_name);
			flag = 0;
			break;
		}
	}
	if (flag == 1)
	{
		printf("\n\tRequested Book could not be found!");
	}
	fclose(f);
	return flag;
}


//search function ends