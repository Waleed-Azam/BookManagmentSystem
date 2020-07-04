#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class BookManagementSystem{
	public:
		float price;
		 int book_id;
		 int status;
		BookManagementSystem()
		{
			price=0;
			book_id=0;
		}
		virtual void create_customer()
		{
		}
	
		virtual void sell_book()
		{
			
		}
	
};
class Book:public BookManagementSystem{
	public:
    int book_id;
    char book_name[20];
    char author[20];
    float price;
    int update;   //updating the status in word it is basically a status fromt eh source code
public:
		virtual void addbook()
		{
			
		}
		virtual void viewbook()
		{
			
		}
		virtual void searchbook()
		{
			
		}
		virtual void deletebook()
		{
			
		}
  inline void acceptbook()
    {
        cout<<"Enter book id: ";
        cin>>book_id;
        cin.ignore();
        cout<<"Enter book name: ";
        cin.getline(book_name,20);
        cin.ignore();
        cout<<"Enter author name: ";
        cin.getline(author,20);
        //cin.ignore();
        cout<<"Enter price: ";
        cin>>price;
        status = 0;
    }
   void display()
    {
    	cout<<"*****************************************"<<endl;
        cout<<"Name   : "<<book_name<<endl;
        cout<<"ID     : "<<book_id<<endl;
        cout<<"Author : "<<author<<endl;
        cout<<"Price  : "<<price<<endl;
        if(status == 0)
        {
            cout<<"Status : Book is available"<<endl;
        }
        else
        {
            cout<<"Status : Book is not available"<<endl;
        }
        cout<<"*****************************************"<<endl;
    }
    
};

class customer:public BookManagementSystem,public Book{
	public:
		//Transaction t;
		char cus_name[20];  //mem_number is repalced by customer name
		int customer_no;   //customer number
	
		int duration;
	friend void create_member(customer&);
	customer()
	{
		
	}
	~customer()
	{
		
	}
};
void create_member(customer& m)
	{
			cout<<"Welcome to the Book Management System"<<endl;
			cout<<"Please Enter the name of customer for furthre Processings"<<endl;
			cin.getline(m.cus_name,20);
			cout<<"Enter Custmer number if you are member of the book shop"<<endl;
			cin>>m.customer_no;
		}
class Transaction:public BookManagementSystem,public Book{    ///Updation and addtion 
	public:
		Book obj;
		void addbook()
		{
    	obj.acceptbook();
    	fstream wr;
    	wr.open("./book_data.txt",ios::app);
    	wr.write((char *)&obj,sizeof(obj));
    	cout<<"*****************************************"<<endl;  
    	cout<<"Book Added Successfully"<<endl;
    	cout<<"*****************************************"<<endl;
		}
    void viewbook()
    {
    	fstream rd;
    	rd.open("./book_data.txt",ios::in);
    	rd.seekg(0,ios::end);
    	int size = rd.tellg()/sizeof(obj);
    	rd.seekg(0,ios::beg);
    	for(int i=1;i<=size;i++)
    	{
        rd.read((char*)&obj,sizeof(obj));
        obj.display();
    	}	
  }

    void searchbook()
    {
    	fstream rd;
        rd.open("./book_data.txt",ios::in);
        char n[50];
        cout<<"Enter name of book: ";
        cin>>n;
        rd.seekg(0,ios::end);
        int size = rd.tellg()/sizeof(obj);
        rd.seekg(0,ios::beg);
        int flag = 0;
        for(int i=1;i<=size;i++)
        {
            rd.read((char*)&obj,sizeof(obj));
            if(strcmp(n,obj.book_name) == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            cout<<"Sorry We didn't find that book !"<<endl;
        }
        else
        {
    	    cout<<"*****************************************"<<endl;
    	    cout<<"Book Found"<<endl;
    	    cout<<"*****************************************"<<endl;
            obj.display();
        }
	}
    void deletebook()
    {
    	fstream rd,wr;
        rd.open("./book_data.txt",ios::in);
        wr.open("./temp.txt",ios::app);
        char n[50];
        cout<<"Enter name of the Book :";
        cin>>n;
        rd.seekg(0,ios::end);
        int size = rd.tellg()/sizeof(obj);
        rd.seekg(0,ios::beg);
        int flag = 0;
        for(int i=1;i<=size;i++)
        {
            rd.read((char*)&obj,sizeof(obj));
            if(strcmp(n,obj.book_name)==0)
            {
                cout<<"Book Removed"<<endl;
            }
            else
            {
                wr.write((char *)&obj,sizeof(obj));
            }
        }
        rd.close();
        wr.close();
        remove("./book_data.txt");
        rename("./temp.txt","./book_data.txt");

	}
};
int main()
{
    int choice;
    int Number_of_books;
    //Library *l1;
    Book *bb;
    Transaction t1;
    customer m1;
    
    create_member(m1);
    
    cout<<"enter number of books you want to buy"<<endl;
    cin>>Number_of_books;
    if(Number_of_books<20)
    {
		
    cout<<"********************* Welcome To Library Management System ********************"<<endl;
    while(1)
    {
        cout<<"What would you want me to do ?"<<endl;
        cout<<"1. Add Book"<<endl;
        cout<<"2. View Book"<<endl;
        cout<<"3. Search Book"<<endl;
        cout<<"4. Delete a book"<<endl;
        cout<<"5. Exit"<<endl;
        cin>>choice;
        if(choice == 1)
        {
          //  t1.viewbook();
            bb=&t1;
            bb->addbook();
        }
        else if(choice == 2)
        {
           //Transaction t1;
           bb=&t1;
           bb->viewbook();
             //t1.searchbook();
        }
        else if(choice == 3)
        {
           Transaction t1;
           bb=&t1;
           bb->searchbook();
           
        }
        else if(choice == 4)
        {
           // Transaction t1;
           bb=&t1;
            bb->deletebook();
           
        }
        else
        {
            break;
        }
    }
    cout<<"Thank You for using our software"<<endl<<"Have a Nice Day !"<<endl<<"All Rights Momina Azam_NTU_Faisalabad BS Computer Science Student, Semester 2nd, Jult 2020"<<endl;
  }
  else
  {
  	cout<<"Sorry no book available for your choice"<<endl;
	}
    return 0;
}
