#include<iostream>
#include<cstring>

using namespace std;

class Train 
{
	private:
		int trainnumber;
		char trainname[50];
		char source[50];
		char destination[50];
		char traintime[50];
		
		static int traincount;
		
	public:
		// Default Constructor
		Train()
		{
			trainnumber=0;
			strcpy(trainname,"");
			strcpy(source,"");
			strcpy(destination,"");
			strcpy(traintime,"");
			traincount++;
		}
		// Parameterized Constructor
		Train(int no, const char name[],const char src[],const char dest[],const char time[])
		{
			trainnumber=no;
			strcpy(trainname, name);
			strcpy(source,src);
			strcpy(destination,dest);
			strcpy(traintime,time);
			traincount++;
		}
		//destructor
	     ~Train()
		{  
		    traincount--;
		}
		 
		//setters
		void settrainnumber(int no)
		{
			trainnumber = no;
		}
		void settrainname(const char name[])
		{
			strcpy(trainname,name);
		}
		void setsource(const char src[])
		{
			strcpy(source,src);
		}
		void setdestination(const char dest[])
		{
			strcpy(destination,dest);
		}
		void settraintime(const char time[])
		{
			strcpy(traintime,time);
		}
		//Getters
		int gettrainnumber()
		{
			return trainnumber;
		}
		const char* gettrainname()
		{
			return trainname;
		}
		const char* getsource()
		{
			return source;
		}
		const char* getdestination()
		{
			return destination;
		}
		const char* gettraintime()
		{
			return traintime;
		}
		
		
		//Input Train Details
		
		void inputtraindetails()
		{
			cout << "Enter Train Number:";
			cin >> trainnumber;
			
			cout << "Enter Tarin Name:";
			cin.ignore(1000, '\n');
			cin.getline(trainname,50);
			
			cout << "Enter Source:";
			cin.getline(source,50);
			
			cout << "Enter Destination: ";
			cin.getline(destination,50);
			
			cout << "Enter Train Time:";
			cin.getline(traintime,10); 
		
		}
		//Display Train Details
		
		void displaytraindetails()
		{
			cout << "Train Number:" << trainnumber << endl;
			cout << "Train Name:" << trainname << endl;
			cout << "Train Source:" << source << endl;
			cout << "Destination:" << destination << endl;
			cout << "Train Time:" << traintime <<endl;
		}
		
		//static
		static int gettraincount()
		{
			return traincount;
		}
};
// Initialize Static Member
int Train::traincount=0;

class Railwaysystem
{
	private:
		Train trains[100];
		int totaltrains=0;

public:
	Railwaysystem()
	{
		totaltrains=0;
	}
	
	void addtrain()
	{
		if(totaltrains >= 100)
		{
			cout << "Train records are full !\n";
			return;
		}
		trains[totaltrains].inputtraindetails();
		totaltrains++;
		
		cout <<"Train Record added Successfully\n!";
	}
	
	void displayalltrains()
	{
		if(totaltrains==0)
		{
			cout << "No train Records Availabel!\n";
			return;
		}
		
		for(int i=0;i <totaltrains; i++)
		{
			cout << "\n Train" << i+1 << "details:\n";
			trains[i].displaytraindetails();
		}
	}
	
	void searchtrainbynumber(int number)
	{
		for(int i=0; i < totaltrains; i++)
		{
			if(trains[i].gettrainnumber()==number)
			{
				cout << "\n Train Found\n";
				trains[i].displaytraindetails();
				return;
			}
		}
		cout << "Train With Number:" << number << "Not Found: \n";
	}
};


int main()
{
	Railwaysystem railway;
	int choice,number;
	
	do
	{
		cout << "\n --Railway Reservation Sytem Menu----\n";
		cout << "1. Add New Tarin Record\n";
		cout << "2. Display All Train Record\n";
		cout << "3. Search Train By Number\n";
		cout << "4. Exit \n";
		cout << "Enter Your Choice:";
		cin >> choice;
		
		switch(choice)
		{
			case 1:
				railway.addtrain();
				break;
			case 2:
				railway.displayalltrains();
				break;
			case 3:
				cout << "Enter Train Number To Search:";
				cin >> number;
				railway.searchtrainbynumber(number);
				break;
			case 4:
				cout << "Exiting The System..Goodbye\n";
			default:
				cout << "Invalid Choice! Please Try again...\n";
		} 
	}while(choice !=4);
	return 0;
}
	
	
