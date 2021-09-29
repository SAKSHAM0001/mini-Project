#include<iostream>
#include<conio.h>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
#include<cstring>
#include<stdio.h>
#include<windows.h>
#include<fstream>
using namespace std;
void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

using namespace std;
class library{
	private:
		struct node{
			int bid,sid,copy;
			string sname,saddr,smob,bname,aname,date;
			node *next_add;
		};
		node *head=NULL;
	public:
		void start();
		void mainmenu();
		void stud_menu();
		void studentlogin();
		void search_book();
		void bookissue();
		void bookdeposit();
		void admin_menu();
		void adminlogin();
		void load_student_data();
		void insert_student_record();
		void search_student_record();
		void edit_student_record();
		void del_student_record();
		void show_student_record();
		void load_book_data();
		void insert_book_record();
		void search_book_record();
		void edit_book_record();
		void del_book_record();
		//void sort();
		void show_book_record();
};
void library::start(){
	system("cls");
	gotoxy(35,11);
	cout<<"LIBRARY";
	gotoxy(35,14);
	cout<<"MANAGEMENT";
	gotoxy(35,17);
	cout<<"SYSTEM";
//	cout<<"\n\n Developer: Saksham";
	
	getch();
}

void library::mainmenu(){
	char ch;
	start();
	library bk;
	

	do{
	system("cls");
	 cout<<"----------------------------------------------------------------------------------- \n";
    cout<<"                        Lovely Professional University                               \n";
    cout<<"                                CENTRAL LIBRARY                                      \n";
    cout<<"------------------------------------------------------------------------------------\n";
    cout<<"                               Applications Starts                                   \n";
	cout<<"\n\n\n\tLOGIN";
	cout<<"\n\n\t1.STUDENT LOGIN";	
	cout<<"\n\n\t2.ADMIN LOGIN";	
	cout<<"\n\n\t3.EXIT";
	cout<<"\n\n\tPlease select your option(1-3)";	
	ch=getche();
	switch(ch){
		case '1':
			studentlogin();
			break;
		case '2':
			adminlogin();
			break;
		case '3':
			exit(3);
			break;
		default:
			cout<<"invalid choice, Try Again";
			
	}	
	}while(ch!=3);
	
	
}
void library::stud_menu(){
	system("cls");
	int b;
	cout<<"\n\n\n\tSTUDENT MENU";
	cout<<"\n\n\t1.BOOK DEPOSIT";
	cout<<"\n\n\t2.BOOK ISSUE";
	cout<<"\n\n\t3.SEARCH BOOK";
	cout<<"\n\n\t4.BACK TO MAIN MENU";
	cout<<"\n\n\t5.EXIT";
    cout<<"\n\n\tPlease Enter your choice(1-5)";
    cin>>b;
    switch(b){
    	
    	case 1:
    		head=NULL;
			load_book_data();
    		bookdeposit();
    		break;
		case 2:
			head=NULL;
			load_book_data();
    		bookissue();
    		break;
		case 3:
			head=NULL;
			load_book_data();
    		search_book();
			break;
		case 4:
    		return;
    		break;
    	case 5:
    		exit(5);
    		break;
		default:
    		cout<<"Invalid Choice, Try Again";
    		

	}
stud_menu();

}   

void library::search_book(){
	system("cls");
	int found=0;
	string t_name;
	cout<<"\n\n\t\t\t-------------------------------------";
	cout<<"\n\n\t\t\t       Search Book      ";
	cout<<"\n\n\t\t\t-------------------------------------";
	if(head==NULL){
		cout<<"\n\n Linked List is Empty....";
	}
	else{
		cout<<"\n\n BOOK NAME : ";
		cin>>t_name;
		system("cls");
		node *ptr=head;
		while(ptr!=NULL){
			if(ptr->bname==t_name){
				cout<<"\n\n\t\t\t-------------------------------------";
				cout<<"\n\n\t\t\t     Search Specific Book Record      ";
				cout<<"\n\n\t\t\t-------------------------------------";
				cout<<"\n\nBook ID       : "<<ptr->bid;
				cout<<"\n\nBook Name     : "<<ptr->bname;
				cout<<"\n\nBook Author   : "<<ptr->aname;
				cout<<"\n\nNo. Of Copies : "<<ptr->copy<<endl;
				system("pause");
				found++;
			}
			ptr=ptr->next_add;
		}
		if(found==0){
			cout<<"\n\nBook ID not Found";
			cout<<"\nFor search again";
			system("pause");
			search_book();
		}
	}
	
}

void library::bookissue(){
	char ch;
	do{
		system("cls");
	fstream file;
	int studentid;
	string studentname,bookname,authname,dated;
	cout<<"\n\n\t\t\t-------------------------------------";
	cout<<"\n\n\t\t\tISSUE BOOK     ";
	cout<<"\n\n\t\t\t-------------------------------------";
	cout<<"\n\nStudent ID      : ";cin>>studentid;
	cout<<"\n\nStudent Name    : ";cin>>studentname;
	cout<<"\n\nBook issued     : ";cin>>bookname;
	cout<<"\n\nAuthor Name     : ";cin>>authname;
	cout<<"\n\ndate of issuing : ";cin>>dated;
	node *new_node=new node;
	new_node->sid=studentid;
	new_node->sname=studentname;
	new_node->bname=bookname;
	new_node->aname=authname;
	new_node->date=dated;
	new_node->next_add=NULL;
	if(head==NULL){
		head=new_node;
	}
	else{
		node *ptr=head;
		while(ptr->next_add!=NULL){
			ptr=ptr->next_add;
		}
		ptr->next_add=new_node;
	}
	file.open("issuedlist.txt",ios::out|ios::app);
	file<<studentid<<setw(10)<<studentname<<setw(25)<<bookname<<setw(25)<<authname<<setw(25)<<dated<<endl;
	file.close();
	cout<<"\n\n\tBook Issued Successfully....\n";
	cout<<"\n\nDo you want to issue more books...[Y/N]? ";
	cin>>ch;
	}while(ch=='Y'|ch=='y');

}

void library::bookdeposit(){
		char ch;
	do{
		system("cls");
	fstream file;
	int studentid;
	string studentname,bookname,authname,dated;
	cout<<"\n\n\t\t\t-------------------------------------";
	cout<<"\n\n\t\t\tISSUE BOOK     ";
	cout<<"\n\n\t\t\t-------------------------------------";
	cout<<"\n\nStudent ID      : ";cin>>studentid;
	cout<<"\n\nStudent Name    : ";cin>>studentname;
	cout<<"\n\nBook returned   : ";cin>>bookname;
	cout<<"\n\ndate of return  : ";cin>>dated;
	node *new_node=new node;
	new_node->sid=studentid;
	new_node->sname=studentname;
	new_node->bname=bookname;
	new_node->date=dated;
	new_node->next_add=NULL;
	if(head==NULL){
		head=new_node;
	}
	else{
		node *ptr=head;
		while(ptr->next_add!=NULL){
			ptr=ptr->next_add;
		}
		ptr->next_add=new_node;
	}
	file.open("returnlist.txt",ios::out|ios::app);
	file<<studentid<<setw(10)<<studentname<<setw(25)<<bookname<<setw(25)<<dated<<endl;
	file.close();
	cout<<"\n\n\tBook returned Successfully....\n";
	cout<<"\n\nDo you want to return more books...[Y/N]? ";
	cin>>ch;
	}while(ch=='Y'|ch=='y');
	

}

void library::studentlogin(){

	system("cls");
	string pin,uid;
	cout << "\n       <=======>  Library Management System(LMS) <=======>\n";
	cout<<"\n\n\n\tSTUDENT LOGIN";
	cout<<"\nEnter Student Username         : ";cin>>uid;
	cout<<"\nEnter Password PIN To Access   : "; cin >> pin;
	if (pin == "1234"&uid=="user") {
	stud_menu();
	}
	else {
		cout << "\nWrong PIN or Username\n";
		system("pause");
	    //system("cls");
		return;
	}	
}


void library::adminlogin(){
	system("cls");
	string pin,uid;
	cout << "\n       <=======>  Library Management System(LMS) <=======>\n";
	cout<<"\n\n\n\tADMIN LOGIN";
	cout<<"\nEnter Admin Username         : ";cin>>uid;
	cout<<"\nEnter Password PIN To Access : "; cin >> pin;
	if (pin == "1234"&uid=="admin") {
	admin_menu();
	}
	else {
		cout << "\nWrong PIN or Username\n";
		system("pause");
	    //system("cls");
		return;
	}	
}

void library::admin_menu(){
	p:
		system("cls");
	int b;
	cout<<"\n\n\n\tADMIN MENU";
	cout<<"\n\n\t1.ADD NEW STUDENT RECORD";
	cout<<"\n\n\t2.SEARCH STUDENT RECORD";
	cout<<"\n\n\t3.DISPLAY ALL STUDENT RECORD";
	cout<<"\n\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\n\t6.ADD NEW BOOK RECORD";
	cout<<"\n\n\t7.SEARCH BOOKS RECORD";
	cout<<"\n\n\t8.DISPLAY ALL BOOK RECORD";
	cout<<"\n\n\t9.MODIFY BOOK RECORD";
	cout<<"\n\n\t10.DELETE BOOK RECORD";
	cout<<"\n\n\t11.BACK TO MAIN MENU";
	cout<<"\n\n\t12.EXIT";
    cout<<"\n\n\tPlease Enter your choice(1-12)";
    cin>>b;
    switch(b){
    	
    	case 1:
    		insert_student_record();
    		break;
		case 2:
    		head=NULL;
    		load_student_data();
    		search_student_record();
    		break;
		case 3:
    		head=NULL;
    		load_student_data();
    		show_student_record();
    		break;
		case 4:
    		head=NULL;
    		load_student_data();
    		edit_student_record();
    		break;
		case 5:
    		head=NULL;
    		load_student_data();
    		del_student_record();
    		break;
		case 6:
    		insert_book_record();
    		break;
		case 7:
    		head=NULL;
			load_book_data();
			search_book_record();
			break;
		case 8:
			head=NULL;
			load_book_data();
			show_book_record();
			break;
		case 9:
			head=NULL;
			load_book_data();
			edit_book_record();
    		break;
		case 10:
			head=NULL;
			load_book_data();
			del_book_record();
    		break;
		case 11:
    		return;
    		break;
    	case 12:
    		exit(12);
    		break;
		default:
    		cout<<"Invalid Choice, Try Again";
    		

	}
	getch();
	goto p;
}   

void library::load_student_data(){
	fstream file;
	int st_id;
	string st_name,st_addr,st_mob;
	file.open("studentlist.txt",ios::in);
	if(file){
		file>>st_id>>st_name>>st_addr>>st_mob;
		while(!file.eof()){
			node *new_node=new node;
			new_node->sid=st_id;
			new_node->sname=st_name;
			new_node->saddr=st_addr;
			new_node->smob=st_mob;
			new_node->next_add=NULL;
			//to check whether node is first or not
			if(head==NULL){
				head=new_node;
			}
			else{
				node *ptr=head;
				while(ptr->next_add!=NULL){
					ptr=ptr->next_add;
				}
				ptr->next_add=new_node;
			}
			file>>st_id>>st_name>>st_addr>>st_mob;	
		}
		file.close();
	}
}

void library::insert_student_record(){
	char ch;
	do{
		system("cls");
	fstream file;
	int studentid;
	string studentname,studentaddr,studentmob;
	cout<<"\n\n\t\t\t-------------------------------------";
	cout<<"\n\n\t\t\tCreate New Node & Insert Record      ";
	cout<<"\n\n\t\t\t-------------------------------------";
	cout<<"\n\nStudent ID      : ";cin>>studentid;
	cout<<"\n\nStudent Name    : ";cin>>studentname;
	cout<<"\n\nStudent Address : ";cin>>studentaddr;
	cout<<"\n\nStudent Mobile  : ";cin>>studentmob;
	node *new_node=new node;
	new_node->sid=studentid;
	new_node->sname=studentname;
	new_node->saddr=studentaddr;
	new_node->smob=studentmob;
	new_node->next_add=NULL;
	if(head==NULL){
		head=new_node;
	}
	else{
		node *ptr=head;
		while(ptr->next_add!=NULL){
			ptr=ptr->next_add;
		}
		ptr->next_add=new_node;
	}
	file.open("studentlist.txt",ios::out|ios::app);
	file<<studentid<<setw(10)<<studentname<<setw(25)<<studentaddr<<setw(50)<<studentmob<<endl;
	file.close();
	cout<<"\n\n\tNew Node Created Successfully....\n";
	cout<<"\n\nDo you want to add more Record...[Y/N]? ";
	cin>>ch;
	}while(ch=='Y'|ch=='y');
}

void library::search_student_record(){
	system("cls");
	int t_id,found=0;
	cout<<"\n\n\t\t\t-------------------------------------";
	cout<<"\n\n\t\t\t       Search Specific Record      ";
	cout<<"\n\n\t\t\t-------------------------------------";
	if(head==NULL){
		cout<<"\n\n Linked List is Empty....";
	}
	else{
		cout<<"\n\n STUDENT ID : ";
		cin>>t_id;
		system("cls");
		node *ptr=head;
		while(ptr!=NULL){
			if(ptr->sid==t_id){
				cout<<"\n\n\t\t\t-------------------------------------";
				cout<<"\n\n\t\t\t     Specific Student Record      ";
				cout<<"\n\n\t\t\t-------------------------------------";
				cout<<"\n\nStudent ID      : "<<ptr->sid;
				cout<<"\n\nStudent Name    : "<<ptr->sname;
				cout<<"\n\nStudent Address : "<<ptr->saddr;
				cout<<"\n\nStudent Mobile  : "<<ptr->smob<<endl;
			//	system("pause");
				found++;
			}
			ptr=ptr->next_add;
		}
		if(found==0){
			cout<<"\n\nStudent ID not Found";
		}
	}
	
}

void library::edit_student_record(){
	system("cls");
	fstream file,file1;
	int t_id,found=0,sid,studentid;
	string sname,studentname,saddr,studentaddr,smob,studentmob;
	cout<<"\n\n\t\t\t-------------------------------------";
	cout<<"\n\n\t\t\t          Edit Specific Record      ";
	cout<<"\n\n\t\t\t-------------------------------------";
	if(head==NULL){
		cout<<"\n\n Linked List is Empty....";
	}
	else{
		cout<<"\n\nStudent ID to be edited : ";
		cin>>t_id;
		system("cls");
		file.open("studentlist.txt",ios::in);
		file1.open("studentlist1.txt",ios::app|ios::out);
		file>>studentid>>studentname>>studentaddr>>studentmob;
		while(!file.eof()){
			if(t_id==studentid){
				system("cls");
				cout<<"\n\n\t\t\t-------------------------------------";
				cout<<"\n\n\t\t\t       Edit Student Record      ";
				cout<<"\n\n\t\t\t-------------------------------------";
				cout<<"\n\nStudent ID      : ";
				cin>>sid;
				cout<<"\n\nStudent Name    : ";
				cin>>sname;
				cout<<"\n\nStudent Address : ";
				cin>>saddr;
			    cout<<"\n\nStudent Mobile  : ";
				cin>>smob;
				file1<<sid<<setw(10)<<sname<<setw(25)<<saddr<<setw(50)<<smob<<endl;
			    cout<<"\n\n Edited Record Successfully\n";
			   // system("pause");
				found++;
			}
			else{
				file1<<studentid<<setw(10)<<studentname<<setw(25)<<studentaddr<<setw(50)<<studentmob<<endl;
			}
			file>>studentid>>studentname>>studentaddr>>studentmob;
		}
		file.close();
		file1.close();
		remove("studentlist.txt");
		rename("studentlist1.txt","studentlist.txt");
		if(found==0){
			cout<<"\n\nStudent ID not Found";
		}
	}
}

void library::del_student_record(){
	system("cls");
	fstream file,file1;
	int t_id,found=0,studentid;
	string studentname,studentaddr,studentmob;
	cout<<"\n\n\t\t\t-------------------------------------";
	cout<<"\n\n\t\t\t          Delete Specific Record      ";
	cout<<"\n\n\t\t\t-------------------------------------";
	if(head==NULL){
		cout<<"\n\n Linked List is Empty....";
	}
	else{
		cout<<"\n\nStudent ID to be deleted : ";
		cin>>t_id;
		system("cls");
		file.open("studentlist.txt",ios::in);
		file1.open("studentlist1.txt",ios::app|ios::out);
		file>>studentid>>studentname>>studentaddr>>studentmob;
		while(!file.eof()){
			if(t_id==studentid){
				system("cls");
				cout<<"\n\n\t\t\t-------------------------------------";
				cout<<"\n\n\t\t\t       Delete Specific Record      ";
				cout<<"\n\n\t\t\t-------------------------------------";
				cout<<"\n\n deleted Record Successfully\n";
			//	system("pause");
				found++;
			}
			else{
				file1<<studentid<<setw(10)<<studentname<<setw(25)<<studentaddr<<setw(50)<<studentmob<<endl;
			}
			file>>studentid>>studentname>>studentaddr>>studentmob;
		}
		file.close();
		file1.close();
		remove("studentlist.txt");
		rename("studentlist1.txt","studentlist.txt");
		if(found==0){
			cout<<"\n\nStudent ID not Found";
		}
	}
}

void library::show_student_record()
{
	system("cls");
	cout<<"\n\n\t\t\t-------------------------------------";
	cout<<"\n\n\t\t\t           Show All Record      ";
	cout<<"\n\n\t\t\t-------------------------------------";
	if(head==NULL){
		cout<<"\n\n Linked List is Empty....";
	}
	else{
		cout<<"\n\nStudent ID\tStudent Name\tStudent Address\t\tStudent Mobile";
		node *ptr=head;
		while(ptr!=NULL){
			cout<<"\n"<<ptr->sid<<"\t\t"<<ptr->sname<<"\t\t"<<ptr->saddr<<"\t\t\t"<<ptr->smob;
			ptr=ptr->next_add;
		}
		cout<<endl;
		//system("pause");
	}
}
void library::load_book_data(){
	fstream file;
	int b_id,b_copy;
	string b_name,a_name;
	file.open("booklist.txt",ios::in);
	if(file){
		file>>b_id>>b_name>>a_name>>b_copy;
		while(!file.eof()){
			node *new_node=new node;
			new_node->bid=b_id;
			new_node->bname=b_name;
			new_node->aname=a_name;
			new_node->copy=b_copy;
			new_node->next_add=NULL;
			//to check whether node is first or not
			if(head==NULL){
				head=new_node;
			}
			else{
				node *ptr=head;
				while(ptr->next_add!=NULL){
					ptr=ptr->next_add;
				}
				ptr->next_add=new_node;
			}
			file>>b_id>>b_name>>a_name>>b_copy;	
		}
		file.close();
	}
}

void library::insert_book_record(){
	char ch;
	do{
		system("cls");
		system("cls");
		fstream file;
		int bookid,bookcopy;
		string bookname,authname;
		cout<<"\n\n\t\t\t-------------------------------------";
		cout<<"\n\n\t\t\tCreate New Node & Insert Record      ";
		cout<<"\n\n\t\t\t-------------------------------------";
		cout<<"\n\nBook ID       : ";cin>>bookid;
		cout<<"\n\nBook Name     : ";cin>>bookname;
		cout<<"\n\nAuthor Name   : ";cin>>authname;
		cout<<"\n\nNo. Of Copies : ";cin>>bookcopy;
		node *new_node=new node;
		new_node->bid=bookid;
		new_node->bname=bookname;
		new_node->aname=authname;
		new_node->copy=bookcopy;
		new_node->next_add=NULL;
		if(head==NULL){
		head=new_node;
		}
		else{
			node *ptr=head;
			while(ptr->next_add!=NULL){
				ptr=ptr->next_add;
			}
			ptr->next_add=new_node;
		}
		file.open("booklist.txt",ios::out|ios::app);
		file<<bookid<<setw(10)<<bookname<<setw(25)<<authname<<setw(30)<<bookcopy<<endl;
	
		file.close();
		cout<<"\n\n\tNew Node Created Successfully....\n";
		cout<<"\n\nDo you want to add more Record...[Y/N]? ";
		cin>>ch;
	}while(ch=='Y'|ch=='y');	
}

void library::search_book_record(){
	system("cls");
	int t_id,found=0;
	cout<<"\n\n\t\t\t-------------------------------------";
	cout<<"\n\n\t\t\t       Search Specific Record      ";
	cout<<"\n\n\t\t\t-------------------------------------";
	if(head==NULL){
		cout<<"\n\n Linked List is Empty....";
	}
	else{
		cout<<"\n\n BOOK ID : ";
		cin>>t_id;
		system("cls");
		node *ptr=head;
		while(ptr!=NULL){
			if(ptr->bid==t_id){
				cout<<"\n\n\t\t\t-------------------------------------";
				cout<<"\n\n\t\t\t     Search Specific Book Record      ";
				cout<<"\n\n\t\t\t-------------------------------------";
				cout<<"\n\nBook ID       : "<<ptr->bid;
				cout<<"\n\nBook Name     : "<<ptr->bname;
				cout<<"\n\nBook Author   : "<<ptr->aname;
				cout<<"\n\nNo. Of Copies : "<<ptr->copy<<endl;
			//	system("pause");
				found++;
			}
			ptr=ptr->next_add;
		}
		if(found==0){
			cout<<"\n\nBook ID not Found";
		}
	}
	
}

void library::edit_book_record(){
	system("cls");
	fstream file,file1;
	int t_id,found=0,bid,bookid,copy,bookcopy;
	string bname,bookname,aname,authname;
	cout<<"\n\n\t\t\t-------------------------------------";
	cout<<"\n\n\t\t\t          Edit Specific Record      ";
	cout<<"\n\n\t\t\t-------------------------------------";
	if(head==NULL){
		cout<<"\n\n Linked List is Empty....";
	}
	else{
		cout<<"\n\n Book ID to be edited : ";
		cin>>t_id;
		system("cls");
		file.open("booklist.txt",ios::in);
		file1.open("booklist1.txt",ios::app|ios::out);
		file>>bookid>>bookname>>authname>>bookcopy;
		while(!file.eof()){
			if(t_id==bookid){
				system("cls");
				cout<<"\n\n\t\t\t-------------------------------------";
				cout<<"\n\n\t\t\t       Edit Specific Record      ";
				cout<<"\n\n\t\t\t-------------------------------------";
				cout<<"\n\nBook ID       : ";
				cin>>bid;
				cout<<"\n\nBook Name     : ";
				cin>>bname;
				cout<<"\n\nAuthor Name   : ";
				cin>>aname;
				cout<<"\n\nNo. of copies : ";
				cin>>copy;
			    file1<<bid<<setw(10)<<bname<<setw(25)<<aname<<setw(30)<<copy<<endl;
			    cout<<"\n\n Edited Record Successfully\n";
			   // system("pause");
				found++;
			}
			else{
				file1<<bookid<<setw(10)<<bookname<<setw(25)<<authname<<setw(30)<<bookcopy<<endl;
			}
			file>>bookid>>bookname>>authname>>bookcopy;
		}
		file.close();
		file1.close();
		remove("booklist.txt");
		rename("booklist1.txt","booklist.txt");
		if(found==0){
			cout<<"\n\nBook ID not Found";
		}
	}
}

void library::del_book_record(){
	system("cls");
	fstream file,file1;
	int t_id,found=0,bookid,bookcopy;
	string bookname,authname;
	cout<<"\n\n\t\t\t-------------------------------------";
	cout<<"\n\n\t\t\t          Delete Specific Record      ";
	cout<<"\n\n\t\t\t-------------------------------------";
	if(head==NULL){
		cout<<"\n\n Linked List is Empty....";
	}
	else{
		cout<<"\n\nBook ID to be deleted : ";
		cin>>t_id;
		system("cls");
		file.open("booklist.txt",ios::in);
		file1.open("booklist1.txt",ios::app|ios::out);
		file>>bookid>>bookname>>authname>>bookcopy;
		while(!file.eof()){
			if(t_id==bookid){
				system("cls");
				cout<<"\n\n\t\t\t-------------------------------------";
				cout<<"\n\n\t\t\t       Delete Specific Record      ";
				cout<<"\n\n\t\t\t-------------------------------------";
				cout<<"\n\n deleted Record Successfully\n";
			//	system("pause");
				found++;
			}
			else{
				file1<<bookid<<setw(10)<<bookname<<setw(25)<<authname<<setw(30)<<bookcopy<<endl;
			}
			file>>bookid>>bookname>>authname>>bookcopy;
		}
		file.close();
		file1.close();
		remove("booklist.txt");
		rename("booklist1.txt","booklist.txt");
		if(found==0){
			cout<<"\n\nBook ID not Found";
		}
	}
}

/*
void library::sort(){
	int t_bid,count=0;
	string t_bname,t_aname;
	if(head==NULL){
		cout<<"\n\n Linked List is Empty....";
	}
	node *ptr=head;
	while(ptr!=NULL){
		count++;
		ptr=ptr->next_add;
	}
	for(int i=1;i<=count;i++){
		for(int j=1;j<count;j++){
			if(ptr->bid>ptr->next_add->bid){
				//save data to temp node
				t_bid=ptr->bid;
				t_bname=ptr->bname;
				t_aname=ptr->aname;
				//save data to current node
				ptr->bid=ptr->next_add->bid;
				ptr->bname=ptr->next_add->bname;
				ptr->aname=ptr->next_add->aname;
				//save data to next node
				ptr->next_add->bid=t_bid;
				ptr->next_add->bname=t_bname;
				ptr->next_add->aname=t_aname;
			}
			ptr=ptr->next_add;
		}
	}
}*/
void library::show_book_record()
{
	system("cls");
	cout<<"\n\n\t\t\t-------------------------------------";
	cout<<"\n\n\t\t\t           Show All Record      ";
	cout<<"\n\n\t\t\t-------------------------------------";
	if(head==NULL){
		cout<<"\n\n Linked List is Empty....";
	}
	else{
		cout<<"\n\nBook ID\t\tBook Name\tAuthor Name\tCopies";
		node *ptr=head;
		while(ptr!=NULL){
			cout<<"\n"<<ptr->bid<<"\t\t"<<ptr->bname<<"\t\t"<<ptr->aname<<"\t\t"<<ptr->copy;
			ptr=ptr->next_add;
		}
		cout<<endl;
		//system("pause");
	}
}

int main(){
	library bk;
	bk.mainmenu();
	bk.load_book_data();
	bk.load_student_data();
	//bk.admin();	
	}
