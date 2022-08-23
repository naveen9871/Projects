#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>


void insertfirst(int data, char foodname[25], int quantity, float price);
void insertmid(int pos, int data, char foodname[25], int quantity, float price);
void insertend(int data, char foodname[25], int quantity, float price);
void updatefood(int udata, int uquantity);
void foodlist();
void order_view(int order, int quantity, int or_no);
void main_menu();
void deletefood(int serial);
int countitem();



void cls();
void echo(char print[]);
void br(int line);
void pre(int tab);
void span(int space);
void pwelcome();
void middle1(void);
void middtab1(void);
void backuploader(void);

struct Node{

	char foodname[50];
	int quantity;
	float price;
	int data;
	struct Node *next;

};

//Global Type
typedef struct Node node ;
node *head, *list;

int main()
{
	system("title RESTAURANT MANAGEMENT SYSTEM");
	system("mode con: cols=80 lines=30");
	
	pwelcome();
	Sleep(300);
	cls();
	
	int c=0; int any;
	int cardno[100];
	float cardmoney[100];
	float totalmoney = 0;
	int total_order[100];
	int order_quantity[100];
	int order=0;
	int uquantity;
	int citem;
	
	head = NULL;
	insertend(1,"Hot Cake  ",8,720.83);
	insertend(2,"Coffee    ",46,70.23);
	insertend(3,"Ice-Cream",46,70.23);
	insertend(4,"Sandwich ",34,60.23);
	insertfirst(5,"Burger   ",23,120.23);
	insertend(6,"Pizza    ",13,100.67);
	insertend(7,"Grill    ",7,520.29);
	insertend(8,"Naan Bread",121,35.13);
	insertend(9,"Cold Drinks",73,20.13);
	
	mainmenu:
	br(1);
	main_menu();
	int main_menu_choice;
	br(1); pre(4); fflush(stdin); scanf("%d",&main_menu_choice);
	
	if((main_menu_choice >=1 && main_menu_choice <=3)){

		if(main_menu_choice == 1){
			foodlist:
			cls();
			printf("=> 0. Main Menu ");
			foodlist();
		}
		
		else if( main_menu_choice == 2){

			adminpanelchoice:

			int admin_panel_choice;

			cls(); middle1() ;   pre(4);  printf("1. Main Menu\n\n\t"); Sleep(300);
			printf("Please Enter Password or ( 1 to Back in Main Menu ) : ");


			fflush(stdin);  scanf("%d",&admin_panel_choice);
			if(admin_panel_choice==123){

				node *temp;
				temp = list;
				adminchoice:

				cls();  br(5); pre(4); echo("You are on Admin Pannel\n\n");
				pre(4);
				printf(" 1. Total Cash Today \n\n");Sleep(250);pre(4);
				printf(" 2. View Card Pay \n\n");Sleep(250);pre(4);
				printf(" 3. Add Food \n\n");Sleep(250);pre(4);
				printf(" 4. Delete Food \n\n");Sleep(250);pre(4);
				printf(" 5. Instant Food List \n\n");Sleep(250);pre(4);
				printf(" 6. Item Counter \n\n");Sleep(250);pre(4);
				printf(" 7. Backup System\n\n");Sleep(250);pre(4);
				printf(" 8. Instant Order Preview\n\n");Sleep(250);pre(4);
				printf(" 0. Main Menu \n\n");
				printf("Enter Your option: ");
				Sleep(250);
				
				int adminchoice;
				fflush(stdin);   scanf("%d",&adminchoice);
				
				if(adminchoice==1){

					cls();  middle1(); pre(4);   printf("Todays Total Cash : %0.2f  \n",totalmoney);

					Sleep(2000);

					goto adminchoice;
				}
				
				else if(adminchoice==4){

					cls();
					middle1();pre(2);
					printf("Enter Serial No of the Food To Delete : ");
					fdelete:
					int fdelete;
					fflush(stdin); scanf("%d",&fdelete);
					node *temp;
					temp=list;
					while(temp->data != fdelete){
						temp = temp->next;
					}
					if(temp->data==fdelete){
						deletefood(fdelete);
					}
					else{
						br(2); pre(2); printf("Please Enter Correct Number :  "); Sleep(500);
						goto fdelete;
					}


					goto adminchoice;
				}
				
				else if(adminchoice==3){

					foodadd:
					cls();
					char ffoodname[25];
					int fquantity;
					int fdata;
					float fprice;
					int fposi;

					br(3);pre(4);      printf(" Enter Food Name :  ");
					fflush(stdin);     scanf("%[^\n]s",ffoodname);
					fquantity:
					fflush(stdin);
					br(2);pre(4);
					printf(" Enter Food Quantity :  ");
					scanf("%d",&fquantity); fflush(stdin);

                    foodserial:
					br(2);pre(4);  printf(" Enter Food Serial :  ");
                    scanf("%d",&fdata);
                    node *exist;
                    exist = list;
                    while(exist->data!=fdata){
                        if(exist->next==NULL){
                            break;
                        }
                        exist=exist->next;
                    }
                    if(exist->data==fdata){
                        cls(); br(5);pre(3);  printf(" Food Serial Already Exists, Please Re-Enter  "); Sleep(2000);
                        goto foodserial;
                    }

                    fprice:
                    fflush(stdin);
					br(2);pre(4);  printf(" Enter Food Price :  ");fflush(stdin);
					scanf("%f",&fprice);

					br(2);pre(4);  printf("Submiting data");for(int cs=0;cs<4;cs++){printf(" .");Sleep(500);}

					insertend(fdata,ffoodname,fquantity,fprice);
					br(2);pre(4);      printf("Adding Food  Successfull....\n");
					Sleep(2000);
					goto adminchoice;
				}
				else if(admin_panel_choice==1){
				goto mainmenu;
			}
			else{
				br(2); pre(4);  printf("Please Enter Correct Choice");
				goto adminpanelchoice;
			}

		}

		else if(main_menu_choice==3){
			cls();
			middle1(); pre(3); printf("Thank You For Using Our System \n\n\n\n\n\n\n");
			Sleep(1000);

			exit(1);

		}

	}
	else{
		br(2); pre(4); printf("Please Enter Correct Choice"); Sleep(300);
		goto mainmenu;
	}


	int get_food_choice;


	br(2); pre(3);fflush(stdin);
	printf("Place Your Order: ") ;
	scanf("%d",&get_food_choice);

	if(get_food_choice==0){
		goto mainmenu;
	}

	node *temp;

	temp = list ;

	while(temp->data != get_food_choice){

		temp = temp->next;
		if(temp==NULL){
			br(2); pre(4);  echo("Please Choose From List: "); br(2); Sleep(1000);
			goto foodlist;
		}

	}
	if(get_food_choice == temp->data){

		fcquantity:
		br(2); pre(4);
		printf("Enter Food Quantity : ");

		int fcquantity;

		fflush(stdin); scanf("%d",&fcquantity); cls();



		if(fcquantity==0){
			cls(); middle1();pre(3); printf("Quantity Can not be Zero "); Sleep(2000);
			cls();
			goto foodlist;
		}
		else if(fcquantity>temp->quantity){
			cls(); middle1();pre(3); printf("Out of Stock ! "); Sleep(2000);

			goto foodlist;
		}

		middle1();pre(4);  printf("Choice food %s  its price is %0.2f \n\n",temp->foodname,temp->price*fcquantity);pre(4);
		printf("1. Confirm to buy this \n\n");pre(4);
		printf("2. Food List \n\n");
		printf("Press 1 to confirm and 2 to back to list :");

		confirm:
		int confirm;

		fflush(stdin); scanf("%d",&confirm);

		if(confirm == 1 ){

			br(2);pre(4);
			printf(" 1. Cash ");
			br(2);pre(4);
            printf(" 2. Credit\n");
            printf("Select Method Of payment 1-2: ");
			payment:
			int payment;

			fflush(stdin);  scanf("%d",&payment);
}
}
}
}

void cls(){
	system("cls");
}

void echo(char print[]){
	printf("%s",print);
}

void br(int line){
	for(int i=0; i<line;i++){
		printf("\n");
	}
}

void pre(int tab){
	for(int i=0; i<tab;i++){
		printf("\t");
	}
}

void span(int space){
	for(int i=0; i<space;i++){
		printf(" ");
	}
}

void main_menu(){
	cls();
	br(5); pre(3); echo("---> 1. Food List"); Sleep(200);
	br(2); pre(3); echo("---> 2. Admin Panel"); Sleep(200);
	br(2); pre(3); echo("---> 3. Exit");  Sleep(200);
	br(1);
}

void insertfirst(int data, char foodname[25], int quantity, float price){
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data = data ;
	temp->price = price;
	strcpy(temp->foodname,foodname);
	temp-> quantity = quantity;
	temp->next = head;
	head = temp;
	list = head ;
}

void insertend(int data, char foodname[25], int quantity, float price){
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data = data;
	temp->price = price;
	temp-> quantity = quantity;
	strcpy(temp->foodname,foodname);
	temp->next = NULL;

	if(head==NULL){
		head = temp;
		list = head;
	}
	else{
		while(head->next != NULL){
			head = head->next;
		}
		head->next = temp;
	}
}

void insertmid(int pos, int data, char foodname[25], int quantity, float price){

	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data = data;
	temp->price = price;
	temp-> quantity = quantity;
	strcpy(temp->foodname,foodname);
	while(head->next->data != pos ){
		head = head->next ;
	}
	temp->next = head->next;
	head->next = temp ;
}

void deletefood(int serial){

	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp = list;
	if(temp->data != serial){
		while(temp->next->data != serial){
			temp = temp->next;
		}

		if(temp->next->data == serial){
			temp->next = temp->next->next;
			cls();
			printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);for(int cs=0;cs<4;cs++){printf(" .");Sleep(400);}
			printf("\n\n\n\n\t\t\tDeleted Successfully \n"); Sleep(500);
		}
		else{
			printf("\n\n\n\n\t\t\tFood Item Not Found\n"); Sleep(500);
		}

		head = temp ;

	}
	else{

		temp = temp->next;
		cls();
		printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);for(int cs=0;cs<4;cs++){printf(" .");Sleep(400);}
		printf("\n\n\n\n\t\t\tDeleted Successfully \n"); Sleep(500);
		head = temp ;
		list=head;
	}
}

void updatefood(int udata, int uquantity){

	node *temp;
	temp = list;
	while(temp->data!=udata){
		temp = temp->next;

	}
	if(temp->data == udata){
		temp->quantity = uquantity;
	}
}

int countitem(){
	node *temp;
	temp = list;
	int countitem=0;
	if(temp==NULL){
		countitem = 0;
	}
	else{
		countitem = 1;
		while(temp->next != NULL){
			countitem++;
			temp = temp->next;
		}
	}
	return countitem;
}

void foodlist(){
	printf("\n\t\t"); 
	printf("______________________ ");
	printf("\n\t\t"); 
	printf("|  Food No.  |   Food Name      |  Price       |   In Stock  |");
	printf("\n\t\t"); 
	printf("______________________ ");

	node *temp;
	temp = list;
	while(temp != NULL){
		printf("\n\t\t"); 
		printf("|     %d      |    %s     |    %0.2f    |    %d       |",temp->data,temp->foodname, temp->price, temp->quantity);
		printf("\n\t\t"); 
		printf("______________________ ");

		temp = temp->next ;
		Sleep(100);
	}
}

void order_view(int order, int quantity, int or_no){
	node *temp;
	temp = list;
	while(temp->data != order){
		temp = temp->next;
	}
	if(temp->data == order){
		printf("\n\t\t"); 
		printf("|     %d      |    %s  |     %d     |     %d     |",or_no,temp->foodname,quantity,temp->quantity);
		printf("\n\t\t"); 
		printf("-------------------------------------------------------");
		Sleep(100);
	}
}

void pwelcome(){

	char welcome3[50]=" RESTAURANT";
	char welcome4[50]=" MANAGEMENT SYSTEM";
	printf("\n\n\n\n\n\t\t\t");

	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='D'){
			printf(" %c",welcome3[wlc3]);
		}
		else{
			printf(" %c",welcome3[wlc3]);
		}

		Sleep(100);
	}

	printf("\n\n\n\t\t ");
	for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++){
		if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){
			printf(" %c",welcome4[wlc3]);
		}
		else{
			printf(" %c",welcome4[wlc3]);
		}
		Sleep(125);
	}
	Sleep(200);
}

void backuploader(void){

	for (int i=15;i<=100;i+=5){

		cls();
	

		printf("\n\n\n\n\n\n\n\t\t\t\t");
		printf("%d %% Backing UP DATA...\n\n\t\t",i);

		printf("");

		for (int j=0; j<i;j+=2){

			
			printf(" ");
		

		}
		Sleep(50);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(50);
		}
	}

}

void middle1(void){

	printf("\n\n\n\n\n\n\n");
}

void middtab1(void){
	printf("\t\t\t\t\t");
}