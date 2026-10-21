/*Create a class representing a `Book` with attributes like `title`, `author`, and `publishedYear`.
 Demonstrate the instantiation of objects using array and accessing their attributes.*/
#include<iostream>
#include<string>

using namespace std;

class Book
{
	public:
		string title;
		string author;
		int publishedyear;
};

int main()
{
	Book b[3];
	
	b[0].title ="Wings of Fire";
	b[0].author ="Abdil Kalam";
	b[0].publishedyear =2000;
	
	b[1].title ="Harry Potter";
	b[1].author ="J.K.Rowling";
	b[1].publishedyear =1980;
	
	b[2].title ="Bhgavat Geeta";
	b[2].author ="Vedvyas";
	b[2].publishedyear =1890;
	
	
	for (int i=0;i<3;i++)
	{
		cout << "\n Book" << i+1 << endl;
		cout << "Title:" << b[i].title << endl;
		cout << "Author:" << b[i].author << endl;
		cout << "Published Year:" << b[i].publishedyear <<endl;
	}
	return 0;
}
