#include <fstream.h>	// libraries


class Phonebook
{
private:
	char FirstName [12];
	char LastName [12];
	char AreaCode [4];
	char PhoneNumber[8];


public:
	Phonebook();
	void operator [] (const Phonebook &PhoneNumber);
	void operator () (const Phonebook &AreaCode, &PhoneNumber);
	void operator = (const Phonebook &FirstName, const Phonebook &LastName, const Phonebook &AreaCode, const Phonebook &PhoneNumber);

	void print()const;


};


void main()
{
	fstream book;


	book.open("phonebook.txt", ios::in);
	if (!book)
		cout << "ERROR! opening phonebook.txt" << endl;
	book >> FirstName >> LastName >> AreaCode >> PhoneNumber;


	Phonebook *array=NULL, objeto;
	array = new Phonebook[5];

	for (int i=0; i<= 5; i++)


}
