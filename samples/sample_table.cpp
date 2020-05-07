#include <iostream>
#include <vector>

#include "Unsorted.h"
#include "Sorted.h"
#include "Hash.h"

using namespace std;

int main()
{
	//Неупорядоченные--------------------------------------------------
	{
		Unsorted_table a({ {0,1}, {5,5}, {1, 10} });

		cout << a.size() << endl << a << endl;

		a.insert(4, 4);

		cout << a << endl;

		a.del(5);

		cout << a << endl;

		cout << a.size() << endl;
	}


	//Упорядоченные----------------------------------------------------

	{
		cout << endl << "------------------------------------------------------------" << endl << endl;

		Sorted_table a({ {0,1}, {5,5}, {1, 10} });

		cout << a.size() << endl << a << endl;

		a.insert(4, 4);

		cout << a << endl;

		a.del(5);

		cout << a << endl;

		cout << a.size() << endl;
		
	}
	
	//ХЭШ--------------------------------------------------------------

	{
		cout << endl << "------------------------------------------------------------" << endl << endl;

		Hash_table a(3);
		a.insert(0, 1);
		a.insert(5, 5);
		a.insert(1, 10);

		cout << a.size() << endl << a << endl;

		a.insert(4, 4);

		cout << a << endl;

		a.del(5);

		cout << a << endl;

		cout << a.size() << endl;

	}

	return 0;
}