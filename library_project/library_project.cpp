#include <iostream>
#include <fstream>
#include "code.h"
using namespace std;
int main()
{
	Source* sources = nullptr;
	int size = 0;
	int choice;
	while (true)
	{

		cout << "Hello and welcome to our library! \n here is simple menu\n 1.add something (book/magazine/newspaper) \n 2.delete something(book/magazine/newspaper)\n3. Sorting\n4.searching by name and author\n5.count of something\n6.show all\n 7.close store\n choice: ";
		cin >> choice;
		if (choice == 7 or choice > 7)
		{
			break;
		}
		else if (choice == 1)
		{
			fillDB();
		}
		else if (choice == 2)
		{
			clear(sources, size);
			sources = read(size);
			if (sources == nullptr)
			{
				continue;
			}
			printAll(sources, size, true);
			int id;
			cout << "Enter #id :: ";
			cin >> id;

			remove_(sources, size, id);
			break;

		}
		else if (choice == 3)
		{
			int choice;
			cout << "sort by what?\n1.Title\n2.age\nchoice: " << endl;
			cin >> choice;
			Source* books = read(size);
			if (books != nullptr)
			{
				cout << "Before sorting:" << endl;
				printAll(books, size, true);
				sortBooks(books, size, choice);
			}

			cout << "After sorting:" << endl;
			printAll(books, size, true);

			delete[] books;
		}
		else if (choice == 4) {
			Source* finder = read(size);
			string name, author;
			cout << "Enter book name: ";
			cin >> name;
			cout << "Enter book author: ";
			cin >> author;
			find(finder, size, name, author);
			delete[] finder;
		}
		else if (choice == 5) {
			Source* count = read(size);
			count_of(count, size);
			delete[] count;
		}
		else if (choice == 6)
		{
			clear(sources, size);
			sources = read(size);
			if (sources == nullptr) {
				continue;
			}
			printAll(sources, size, true);
		}


	}
}

