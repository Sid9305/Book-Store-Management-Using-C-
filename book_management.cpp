#include<iostream>
#include<string.h>
using namespace std;
class Book_store
{
	public:
		char book_name[30];
		char author[30];
		char publisher[30];
		float price;
		int no_of_copies_issued;
		int no_of_copies_available;
		int no_of_copies_return,current_books,num;
		int current_return_books,temp;
		Book_store()
		{
			cout<<"\nthis is a menu driven program\n\n";
			cout<<"\nEnter the name of the book:"<<endl;
			cin>>book_name;
			cout<<"\n\nEnter the name of the author:"<<endl;
			cin>>author;
			if (author[0]=='a' || author[0]=='A' || author[0]=='e' || author[0]=='E' || author[0]=='i' || author[0]=='I' || author[0]=='o' || author[0]=='O' || author[0]=='u' || author[0]=='U')
			{
				no_of_copies_available=100;
		    }
			else
			{
				no_of_copies_available=20;
				
			}  
			temp=no_of_copies_available;
			if(no_of_copies_available==100)
			{
				price=175.45;
			}
			else
			{
				price=450.99;
			}
		}
		void accept()
		{
			cout<<"\n\nEnter number of copies to be issued:";
			cin>>no_of_copies_issued;
		}
		void sell()
		{
			if(no_of_copies_issued<=no_of_copies_available)
			{
				cout<<"\nBook is availabe in store\n Total Price is "<<(no_of_copies_issued*price)<<endl;
				no_of_copies_available-=no_of_copies_issued;
			}
			else
			{
				cout<<"Not available"<<endl;
			}
        }
		void return1()
		{
			cout<<"\nTo return the book, Here's the procedure\n"<<endl;
			cout<<"\nThe book you would like to return is "<<book_name<<" By "<<author<<endl;
			cout<<"\nThe price of the book is "<<price<<endl;
			cout<<"\nNumber of copies you would like to return: ";
			cin>>no_of_copies_return;
			cout<<"\nThe price of the return is deducted by 10%, if you are okay with it then press 1, if you would like to cancel your return then click any other key.";
			cin>>num;
			if(num==1)
			{
				int total;
				total=price*no_of_copies_return-((price*no_of_copies_return)/10);
				cout<<"\nHere's the amount you have been refunded for returning the book, that is "<<total<<endl;
				current_return_books=no_of_copies_available+no_of_copies_return;
				no_of_copies_available=current_return_books;
			}
			cout<<"Books :"<<no_of_copies_available;
		}
		void display()
		{
			cout<<"\nThe information of the book sold:"<<endl;
			cout<<"\nBook name is "<<book_name<<endl;
			cout<<"\nAuthor of the book is "<<author<<endl;
			cout<<"\nPrice of the book per unit is "<<price<<endl;
		}
		void current_status()
		{
			if(current_return_books==no_of_copies_available)
			{
				cout<<"\nThe book which is has been returned '"<<book_name<<"' has this "<<current_return_books<<" copies available now"<<endl;
			}
			else if(no_of_copies_available!=temp)
			{
				cout<<"\nThe book which is been sold '"<<book_name<<"' has this "<<no_of_copies_available<<" copies available now"<<endl;
			}
			else
			{
				cout<<"\nBook name is "<<book_name<<endl;
			    cout<<"\nAuthor of the book is "<<author<<endl;
			    cout<<"\nPrice of the book is per unit "<<price<<endl;
				cout<<"\nBook hasn't been sold, the current status is "<<no_of_copies_available<<endl;
			}	
		}
};
int main()
{
	int n,cont;
	Book_store bn;
	do
	{
	cout<<"\nWhat would you like to do?\n1)Buy a book\n2)Return a book\n3)want to know the current status of the book you are interested in?\n4)To exit\n\nPress the respective number keys\n";
	cin>>n;
	switch(n)
	{
		case 1:
			cout<<"\nYou wished to buy a book\nHere's the following procedure:\n"<<endl;
			bn.accept();
			bn.sell();
			bn.display();
			break;
		case 2:
			bn.return1();
			break;
		case 3:
			bn.current_status();
			break;
		case 4:
		exit(0);
		break;		
	}
	cout<<"\npress 1 if you wish to continue, any other key if you would like to exit. ";
	cin>>cont;
	}while(cont==1);
	
}

