#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#define max 50
using namespace std;

int num=0;
void gotoXY(int,int); //curson positioning.
void Cdelay(int); //time delay.
void intro(); //first page
void login(); //login screen.
void menu(); //menu
void insert(); //insert an entry
void edit(); //edit an entry.
void menu_edit(); 
void name_edit(int);
void code_edit(int);
void designation_edit(int);
void experience_edit(int);
void age_edit(int);
void salary_edit(int);
void All_Data(); //to get list of all employees.
void delete_record();
void search(); //search a record.
void save(); //save a record.
void file();
bool Is_File_Present();
void display_record();
void rect_login(); //login box
void rect_menu(int,int); //all other borders.

class employee
{
public:
	char name[20];
	int code;
	char designation[20];
	int exp;
	int age;
	int salary;
	char loan;
	int tax;
	int meal_allowance;
	int transport_allowance;
	int medical_allowance;
	int loan_bal; //loan balance.
	int loan_debit; //loan debit.
	int grosspay; //real eranings withour benefits ans deductions.
	int workingHours;//number of working hours of whole month.
	
};
employee emp[max],tempemp[max];
void file() //to check whether the file is empty or it contains records.
{
	FILE *fp;
	fp = fopen("file.txt","r");//open file and read from start
	int c=0;
	if(fp!=NULL)
	{
		while(feof(fp)==0) //foef tells whether the ending of a file has reached or not.
		{
			fscanf(fp,"%s\t%d\t%s\t%d\t%d\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&emp[c].name,&emp[c].code,&emp[c].designation,&emp[c].exp,&emp[c].age,&emp[c].salary,&emp[c].loan,&emp[c].tax,&emp[c].meal_allowance,&emp[c].transport_allowance,&emp[c].medical_allowance,&emp[c].loan_bal,&emp[c].loan_debit,&emp[c].grosspay,&emp[c].workingHours);
			c++;
		}
		num=c;
	}
	fclose(fp); //close file.
}
void save()
{
	if(num==0)
	{ 
		system("del file.txt");
	}
	else
	{ 
		FILE *fp;
		fp = fopen("file.txt","w");
		for(int i=0;i<num;i++)
		{
			fprintf(fp,"%s\t%d\t%s\t%d\t%d\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",emp[i].name,emp[i].code,emp[i].designation,emp[i].exp,emp[i].age,emp[i].salary,emp[i].loan,emp[i].tax,emp[i].meal_allowance,emp[i].transport_allowance,emp[i].medical_allowance,emp[i].loan_bal,emp[i].loan_debit,emp[i].grosspay,emp[i].workingHours);
		    //fprintf:- To write a formatted string to file stream.
		}
		fclose(fp);
	}
}
void Cdelay(int msec) 
{
    long goal = msec + (clock());
    while (goal > (clock()));
}
bool Is_File_Present()
{
	FILE *fp;
	fp = fopen("file.txt","r");
	if(fp==NULL)
		return false;
	else
		return true;
}
void login()
{
	rect_login();
	char UserName[30],password[30],ch;int i=0;
	gotoXY(5,12);
    printf("Enter UserName : ");
    
    cin>>UserName;
    gotoXY(5,14);
    cout<<"Enter password : ";
    cin>>password;
    if(strcmp(UserName,"GEU")==0 && strcmp(password,"2016928")==0)
    {
    	system("cls");
		rect_login();
    	gotoXY(8,13);
    	cout<<"LOGGING IN PLEASE WAIT...!";
    	gotoXY(8,15);
    	cout<<"lOADING... ";
    		gotoXY(19,15);
    	   Cdelay(2000);
	}
	else
	{
		system("cls");
		rect_login();
    	gotoXY(8,15);
		printf("INCORRECT PASSWORD...");
    	Cdelay(1500);
    	login();
	}
}
void rect_login()
{
	gotoXY(0,10);
	int r = 8, c = 30, i, j;
    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++) {
            if (i == 1 || i == r || j == 1 || j == c)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << "\n";
    }
}
void gotoXY(int X, int Y)
{
    COORD coordinates;
    coordinates.X = X;
    coordinates.Y = Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void insert()
{
	rect_menu(25,33);
	int i=num;
	int sal,TAX,MealAll,MedicalAll,TransportAll,LoanBal,Loandebt,h;
	char loan;
	num+=1;
	gotoXY(25,4);
	printf("INSERT NEW ENTRY");
	gotoXY(10,6);
	cout<<"Name : ";
	cin>>emp[i].name;
	gotoXY(10,8);
	cout<<"Code : ";
	cin>>emp[i].code;
	gotoXY(10,10);
	cout<<"Designation : ";
	cin>>emp[i].designation;
	gotoXY(10,12);
	cout<<"Years of Experience : ";
	cin>>emp[i].exp;
	gotoXY(10,14);
	cout<<"Age : ";
	cin>>emp[i].age;
	gotoXY(10,16);
	cout<<"Enter Working Hours : ";	
	cin>>h;
	sal = h*500;
	emp[i].workingHours = h;
	do
	{
		gotoXY(10,18);
		cout<<"Any Loan (Y/N) ?: \b \b";
		loan=getche();
		if(loan=='Y'|| loan == 'y' || loan =='n' || loan == 'N')
			break;
	}while(1);
	if(loan=='y'|| loan=='Y')
	{
	gotoXY(10,20);
	cout<<"Enter Loan Balance : ";
	cin>>LoanBal;
	}
	else
	{
		LoanBal=0;
	}
	gotoXY(14,22);
	cout<<"Recorded Succesfully...!!!";
	
	TAX =  0.04 * sal; // 4% tax
	MealAll = 300;
	MedicalAll = 300;
	TransportAll = 300;
	Loandebt = sal * 0.09; // 9% of the salary is deducted every month as loan reciept. 
	if(Loandebt > LoanBal)
	{
		LoanBal = 0;
		Loandebt = LoanBal;
	}
	emp[i].salary = sal;
	emp[i].tax=TAX;
	emp[i].meal_allowance = MealAll;
	emp[i].medical_allowance = MedicalAll;
	emp[i].transport_allowance = TransportAll;
	emp[i].loan_bal = LoanBal-Loandebt;
	emp[i].loan = loan;
	emp[i].loan_debit = Loandebt;
	emp[i].grosspay = (sal+MealAll+MedicalAll+TransportAll)+(TAX+Loandebt) ;
	getch();
}
void intro()
{
	rect_menu(20,33);
	gotoXY(15,3); cout<<"...PAYROLL MANAGEMENT SYSTEM...";
    gotoXY(22,5); cout<<"~~ USING C++ ~~";
	gotoXY(39,11);cout<<"MADE BY -";
	gotoXY(39,13); cout<<"PRIYANSHI KAMBOJ";
    gotoXY(3,16.5);cout<<"Press Any key to continue...";
    getch();
    
}
void  All_Data()
{
	rect_menu(25,38);
	gotoXY(15,4);
	printf("       ******** List of the Employees ********");
	gotoXY(6,6);
	cout<<"Name\tCode\tDesignation\tYears(EXP)\tAge\tSalary "<<endl;
	gotoXY(6,7);
	cout<<"------------------------------------------------------------------"<<endl;
	for(int i=0,j=8;i<=num-1;i++,j++)
	{
		gotoXY(6,j);
		cout<<emp[i].name;
		gotoXY(19,j);
		cout<<emp[i].code;
		gotoXY(26,j);
		cout<<emp[i].designation;
		gotoXY(47,j);
		cout<<emp[i].exp;
		gotoXY(58,j);
		cout<<emp[i].age;
		gotoXY(66,j);
		cout<<emp[i].grosspay;
	}
	getch();
}
void menu()
{
	system("cls");
	rect_menu(25,33);
	gotoXY(16,4);
	printf("...PAYROLL MANAGEMENT SYSTEM...");
	gotoXY(25,5);
	cout<<"(using c++)";
	gotoXY(12,8);
	cout<<"i - Insert a New Entry";
	gotoXY(12,10);
	cout<<"d - Delete an Entry";
	gotoXY(12,12);
	cout<<"s - Search an Entry";
	gotoXY(12,14);
	cout<<"e - Edit an Entry";
	gotoXY(12,16);
	cout<<"p - Print the Employee PaySlip.";
	gotoXY(12,18);
	cout<<"l - List of all Employees";
	gotoXY(12,20);
	cout<<"x - End Program";
}
void rect_menu(int r,int c)
{
	gotoXY(-1,4);
	int i, j;
    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++) {
            if (i == 1 || i == r || j == 1 || j == c)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << "\n";
    }
}
void delete_record()
{
	rect_menu(25,33);
	for(int i=0;i<num;i++)
	{
		tempemp[i]=emp[i];
	}
	int code;
	int check=-1;
	gotoXY(25,4);
	printf("DELETE AN ENTRY ");
	gotoXY(10,7);
	cout<<"~Enter the JobCode To Delete That Record : ";
	cin>>code;
	int i,j;
	for(i=0;i<=num-1;i++)
	{
	 	if(emp[i].code==code)
		{
			check=i;
		}
	}
	if(check!=-1)
	{
		for(i=0,j=0;i<=num-1;i++,j++)
		{
			if(i==check)
			{
				i++;
			}
			emp[j]=tempemp[i];
		}
		num--;
	}
}
void search()
{
	rect_menu(25,37);
	int jobcode;
	bool found = false;
	gotoXY(17,4);
	cout<<"You can Search only through the Jobcode of an Employee";
	gotoXY(10,7);
	cout<<"~Enter Code Of the Employee : ";
	cin>>jobcode;
	for(int i=0;i<=num-1;i++)
	{
		if(emp[i].code==jobcode)
		{
			gotoXY(6,8);
			cout<<"Name\tCode\tDesignation\tYears(EXP)\tAge\tSalary "<<endl;
			gotoXY(6,9);
			cout<<"------------------------------------------------------------------"<<endl;
			gotoXY(6,11);
			cout<<emp[i].name;
			gotoXY(19,11);
			cout<<emp[i].code;
			gotoXY(26,11);
			cout<<emp[i].designation;
			gotoXY(47,11);
			cout<<emp[i].exp;
			gotoXY(58,11);
			cout<<emp[i].age;
			gotoXY(66,11);
			cout<<emp[i].grosspay;
			found = true;
		}
	}
	if(!found)
	{
		gotoXY(26,11);
		cout<<"No records Found...!!!\a";
	}
	getch();
}
void menu_edit()
{
	system("cls");
	rect_menu(25,33);
	gotoXY(7,4);
	printf("EDIT AN ENTRY");
	gotoXY(10,6);
	cout<<"~Choose What You want To Edit :-";
	gotoXY(12,8);
	cout<<"n - Name ";
	gotoXY(12,9);
	cout<<"c - Code ";
	gotoXY(12,10);
	cout<<"d - Designation";
	gotoXY(12,11);
	cout<<"e - Experience ";
	gotoXY(12,12);
	cout<<"a - Age";
	gotoXY(12,13);
	cout<<"s - Salary";
	gotoXY(12,14);
	cout<<"x - QUIT";
	gotoXY(10,16);
	cout<<"Enter Choice -  ";
}
void name_edit(int a)
{
	system("cls");
	rect_menu(25,33);
	gotoXY(10,18);
	cout<<"Enter New Name:-  ";
	cin>>emp[a].name;
}
void code_edit(int a)
{
	system("cls");
	rect_menu(25,33);
	gotoXY(10,18);
	cout<<"Enter New Job Code----->  ";
	cin>>emp[a].code;
}
void designation_edit(int a)
{
	system("cls");
	rect_menu(25,33);
	gotoXY(10,18);
	cout<<"Enter new Designation:- ";
	cin>>emp[a].designation;
}
void experience_edit(int a)
{
	system("cls");
	rect_menu(25,33);
	gotoXY(10,18);
	cout<<"Enter new Years of Experience:-";
	cin>>emp[a].exp;
}
void age_edit(int a)
{
	system("cls");
	rect_menu(25,33);
	gotoXY(10,18);
	cout<<"Enter new Age:-";
	cin>>emp[a].age;
}
void salary_edit(int a)
{
	system("cls");
	rect_menu(25,33);
	int sal,TAX,MealA,MedicalA,TransportA,LoanBal=emp[a].loan_bal,LoanDeb;
	char loan;
	gotoXY(10,18);
	cout<<"Enter new Salary:- ";
	cin>>sal;
	TAX =  0.04 * sal;
	MealA = 300;
	MedicalA = 300;
	TransportA = 300;
	LoanDeb = sal * 0.09;
	if(LoanDeb > LoanBal)
	{
		LoanBal = 0;
		LoanDeb = LoanBal;
	}
	emp[a].salary = sal;
	emp[a].tax=TAX;
	emp[a].meal_allowance = MealA;
	emp[a].medical_allowance = MedicalA;
	emp[a].transport_allowance = TransportA;
	emp[a].loan_bal = LoanBal;
	emp[a].loan = loan;
	emp[a].loan_debit = LoanDeb;
	emp[a].grosspay = (sal+MealA+MedicalA+TransportA)+(TAX+LoanDeb) ;
}
void edit()
{
	system("cls");
	rect_menu(22,33);
	int jobcode;
	gotoXY(16,4);
	printf("Edit an Entry:-");
	int i;
	char option;
	gotoXY(10,7);
	cout<<"Enter the jobcode To Edit:- ";
	cin>>jobcode;
	menu_edit();
	for(i=0;i<=num-1;i++)
	{
		if(emp[i].code==jobcode)
		{
			while((option=cin.get())!='x')
			{
				switch(option)
				{
					case 'n':
						name_edit(i);
						break;
					case 'c':
						code_edit(i);
						break;
					case 'd':
						designation_edit(i);
						break;
					case 'e':
						experience_edit(i);
						break;
					case 'a':
						age_edit(i);
						break;
					case 's':
						salary_edit(i);
						break;
				}
   				menu_edit();
			}
		}
	}
}
void display_record()
{
	system("cls");
	rect_menu(25,36);
	gotoXY(10,4);
	int code,i;
	cout<<"Enter Employee Job Code:- ";
	cin>>code;
	for(i=0;i<=num-1;i++)
	{
		if(emp[i].code==code)
		{
			gotoXY(12,6);
			cout<<"Name : "<<emp[i].name;
			gotoXY(45,6);
			cout<<"Working Hours : "<<emp[i].workingHours<<" Hrs";
			gotoXY(6,8);
			cout<<"Earnings :-";
			gotoXY(8,12);
			cout<<"Basic Pay : "<<emp[i].salary<<endl;
			gotoXY(8,14);
			cout<<"Meal Allowance : "<<emp[i].meal_allowance<<endl;
			gotoXY(8,16);
			cout<<"Medical Alowance : "<<emp[i].medical_allowance<<endl;
			gotoXY(8,18);
			cout<<"Transport Allowance : "<<emp[i].transport_allowance<<endl;
			gotoXY(40,8);
			cout<<"Deductions :- "<<endl<<endl;
			gotoXY(42,12);
			cout<<"Tax : "<<emp[i].tax<<endl;
			gotoXY(42,14);
			cout<<"Loan Debit This Month : "<<emp[i].loan_debit<<endl;
			gotoXY(42,16);
			cout<<"Loan Balance : "<<emp[i].loan_bal<<endl;
			gotoXY(32,22);
			cout<<"Total Gross Pay : "<<emp[i].grosspay;
		}
	}
	getch();
}
int main()
{
	system("cls");
	intro(); 
	system("cls");
    login();
    menu(); 
    file();
    char option;
    if(emp[0].code==0 && Is_File_Present())
    	num--;
	while(1)
	{
		option=getch();
		switch(option)
		{
			case 'i':
			    system("cls");
				insert();
				break;
			case 'd':
			    system("cls");
				delete_record();
				break;
			case 's':
			    system("cls");
				search();
				break;
			case 'e':
			    system("cls");
				edit();
				break;
			case 'p':
			    system("cls");
				display_record();
				break;	
			case 'l':
			    system("cls");
				All_Data();
				break;
			case 'x':
			    system("cls");
				save();
				exit(0);
		}
		menu();
	}
	return 0;
}
