#include<stdio.h>
#include<stdlib.h>

// new types used in embedded
typedef	unsigned char u8;
typedef	signed char s8;
typedef	unsigned short int u16;
typedef	signed short int s16;
typedef	unsigned int u32;
typedef	signed int s32;
typedef	unsigned long long int u64;
typedef	signed long long int s64;
typedef	float f32;
typedef	double f64;
typedef	long double f96;

#define null 0 	// null is constant of zero
#define true 1
#define false 0

#define admin_arguements()	do{ printf("for add new patient enter 1\n");\
				printf("for edit patient enter 2\n");\
				printf("for reserve a slot with a doctor enter 3\n");\
				printf("for cancel reservation enter 4\n");\
				printf("for exit enter 0\n");\
				printf("choice: ");\
				scanf("%d",&choice); } while (0)

// linked list node declaration of 2 types
// have 1 is the value and the other is the pointer to next node
typedef	struct nodes
{
	s8 name[50];
	struct nodes *next;
	u16	id;
	u16 age;
	u16 gender;
	u16 reserve;
}patient;

// header pointer to first node
patient * header = null;
s8 name[50]={0};
u16	slots[5]={0};
u16 actual_pass=1234;
u16 id=0;
u16 mode=0;
u16 choice=0;
u16 choice1=0;
u16 choice2=0;
u16 choice3=0;
u16 choice4=0;
u16 choice5=0;
u16 pass=0;


u8 pass_check(u16 * ptr);
void add_patient(void);
void edit_patient(void);
void reserve_slot(void);
void cancel_slot(void);
void view_patient(void);
void today_reservation(void);

void main(void)
{
	do
	{
	printf("For Admin mode enter 1\n");
	printf("For user mode enter 2\n");
	printf("For Exit Enter 0\n");
	printf("Choice: ");
	scanf("%d",&mode);
	switch (mode)
	{
		case 1:	// admin mode
			printf("insert the password please: ");\
			scanf("%d",&pass);
	// checking the id for 3 time only and return 0 (false) or 1(true)
			if (pass_check(&pass)==0)
			{
				printf("the password incorrect");
				break;
			}
			else 
			{
			do
			{
				admin_arguements();	// macro function
				switch (choice)
				{
					case 1:	// adding new patients
					add_patient();
					break;
				
					case 2:	// edit patient
					edit_patient();
					break;
					
					case 3:	//reserve a slot with a doctor
					reserve_slot();
					break;
					
					case 4:	//cancel reservation
					cancel_slot();
					break;
					default:
					break;
				}
			}while(choice !=0 );	
// while password is right and u didnt entered 0 do it again... and so on.
		 }
		break;
		
		case 2:	// user mode
		do 
		{
			printf("For View Patient record Enter 1\n");
			printf("For View Today reservation Enter 2\n");
			printf("For Exit Enter 0\n");
			printf("choice: ");
			scanf("%d", &choice);
			switch (choice)
			{
				case 1:
				view_patient();
				break;
				
				case 2:
				today_reservation();
				break;
			}
		}while(choice != 0);	// user mode loob
		break;
		default:
		break;
	}
	}while (mode !=0); // total program loob
	
}

void view_patient(void)
{
	u8 i=null;
	patient * ptr = header;
	patient * ptr_prievious = header;
	if (header == null)
	{
		printf("There Is NO Patients To VIEW\n");
	}
	else 
	{
		printf("Insert ID = ");
		scanf("%d",&id);
		i=0;
		do 
		{
			if (ptr->id == id)
			{
				// printf("ID= %d\n",ptr->id);
				printf("Name= %s\n",ptr->name);
				printf("age= %d\n",ptr->age);
				printf("gender= %d\t",ptr->gender);
				printf("notes: 1 for men & 2 for female\n");
				printf("reserve = %d\n", ptr->reserve);
				i++;
				break;
			}
			else {}
			ptr_prievious=ptr;
			ptr=ptr->next;
		}while (ptr_prievious->next != null);
		if (i == 0)
			printf("This ID Not Exists\n");
		else {}
	}
}
void today_reservation(void)
{
	for (u8 j=0;j<5;j++)
	{
		if (slots[j] !=0)
			printf("Slot '%d' is ocupied\n",j+1);
		else 
			printf("Slot '%d' is Free\n",j+1);
	}
}
u8 pass_check(u16 * ptr)
{
	u8 i;
	for (i=0;i<3;i++)
	{
		if (i>0) // for second round i=1, to only make the user insert 2 more ,, then total 3 trial 
		{
			printf("insert the right password PLZ: ");
			scanf("%d",ptr);
		}
		if (*ptr == actual_pass)	// when user enter right pass return 1
		{
			return 1;
			break;
		}
		else{}
	}
	if (i==3)	// when complete the for loob then i=3 so return 0 means pass wrong
		return 0;
}

void add_patient(void)
{
	u8 i=null;
	patient * ptr = header;
	patient * ptr_prievious = header;
	if (header == null)
	{
		patient * temp = malloc(sizeof(patient));
		temp->next = null;
		temp->reserve = false;
		header = temp;
		
		printf("insert ID = ");
		scanf("%d",&temp->id);
		printf("if male enter 1\t if female enter 2\nGender:");
		scanf("%d",&temp->gender);
		printf("insert name = ");
		scanf("%s",temp->name);	
		printf("insert age= ");
		scanf("%d",&temp->age);
	}
	else
	{
		printf("insert ID = ");
		scanf("%d",&id);
		i=0;
		do 
		{
			// printf(" 1\n");
			if (ptr->id == id)
			{
				printf("This ID Already Exists\n");
				i++;
				// printf("2\n");
				break;
			}
			else {}
			ptr_prievious = ptr;
			ptr = ptr->next;
			// printf("3\n");
		}while (ptr_prievious->next != null);
		// printf("4\n");
		if (i == 0)
		{
			// printf(" 11 ");
			patient* temp = malloc(sizeof(patient));
			ptr_prievious->next = temp;
			temp->next = null;
			temp->id = id;
			temp->reserve = false;
			printf("if male enter 1\nif female enter 2\n");
			scanf("%d",&temp->gender);
			printf("insert name = "); 
			scanf("%s",temp->name);
			printf("insert age= ");
			scanf("%d",&temp->age);
		}
		else{}
		// printf("final");
	}
}
void edit_patient(void)
{
	u8 i=null;
	patient * ptr = header;
	patient * ptr_prievious = header;
	if (header == null)
	{
		printf("There Is NO Patients To Edit\n");
	}
	else 
	{
		printf("Insert ID Will Edit = ");
		scanf("%d",&id);
		i=0;
		do 
		{
			if (ptr->id == id)
			{
				// printf("ID= %d\n",ptr->id);
				printf("Name= %s\n",ptr->name);
				printf("age= %d\n",ptr->age);
				printf("gender= %d\t",ptr->gender);
				printf("notes: 1 for men & 2 for female\n");
				printf("reserve = %d\n", ptr->reserve);
				i++;
				break;
			}
			else {}
			ptr_prievious=ptr;
			ptr=ptr->next;
		}while (ptr_prievious->next != null);
		if (i == 1)
		{
			printf("For Edit Name enter 1:\n");
			printf("For Edit Age enter 2:\n");
			printf("For Edit Gender enter 3:\n");
			printf("for Deleting The Patient enter 4\n");
			scanf("%d", &choice);
			switch (choice)
			{
				case 1:	// Edit name
				printf("Enter the new Name PLZ:");
				scanf("%s", &ptr_prievious->name);
				break;
				
				case 2:	// Edit Age
				printf("Enter the new Age PLZ:");
				scanf("%d", &ptr_prievious->age);
				break;
				
				case 3:	// Edit Gender
				printf("Enter the new Gender PLZ:");
				scanf("%d", &ptr_prievious->gender);
				break;
				
				case 4:
				if( ptr_prievious == header)
				{
					header= ptr_prievious->next;
				}
				else
				{
					ptr_prievious->next = ptr->next;
				}
				free(ptr);
				break;
				
				default:
				break;
			}
		}
		else 
		{
			printf("This ID not exist\n");
		}
	}
}
void reserve_slot(void)
{
	u8 i=null;
	patient * ptr = header;
	patient * ptr_prievious = header;
	if (header == null)
	{
		printf("There Is NO Patients For Reserve\n");
	}
	else 
	{
		printf("Insert ID Will will reserve For = ");
		scanf("%d",&id);
		i=0;
		do 
		{
			if (ptr->id == id)
			{
				if (ptr->reserve == 0)
				{
					printf("from 2 to 2:30 is slot '1'\n");
					printf("from 2:30 to 3 is slot '2'\n");
					printf("from 3 to 3:30 is slot '3'\n");
					printf("from 4 to 4:30 is slot '4'\n");
					printf("from 4:30 to 5 is slot '5'\n");
					printf("Availabel slots is :\n");
					for (u8 j=0;j<5;j++)
					{
						if (slots[j] == false)
						{
							printf("slot '%d'\n",j+1);
						}
					
						else {}
					}
				}
				else 
				{
					printf("This ID already reserve a slot\n");
					i=55;
					break;
				}
				i++;
				break;
			}
			else {}
			ptr_prievious=ptr;
			ptr=ptr->next;
		}while (ptr_prievious->next != null);
		if (i == 1)
		{
			printf("Enter Slot Number To Reserve: ");
			scanf("%d", &choice);
			slots[choice-1] = true;
			// printf("slot=%d",slots[choice-1]);
			ptr->reserve = choice;
		}
		else if (i==0)
			printf("This ID Not Exists\n");
		else {}
	}
}
void cancel_slot(void)
{
	u8 i=null;
	patient * ptr = header;
	patient * ptr_prievious = header;
	if (header == null)
	{
		printf("There Is NO Patients For canceling Reservation\n");
	}
	else 
	{
		printf("Insert ID Will will CANCEL his reserve = ");
		scanf("%d",&id);
		i=0;
		do 
		{
			if (ptr->id == id)
			{
				if (ptr->reserve == 0)
				{
					printf("This Patient Already Hasn't Reserve YET\n");
				}
				else 
				{
					slots[ptr->reserve-1]=false;
					ptr->reserve = false;
					printf("CANCEL reservation completed\n");
				}
				i++;
				break;
			}
			else {}
			ptr_prievious=ptr;
			ptr=ptr->next;
		}while (ptr_prievious->next != null);
		if (i=0)
		{
			printf("This ID Not Exists\n");
		}
		else {}
	}
}