#include<iostream>
#include<string>

#include"LinkedList.h"

void fillList(LinkedList<int>* aList);
void convertList(LinkedList<int>* aList, std::string number);
void printList(LinkedList<int>* aList);

void evenUpLists(LinkedList<int>* firstList, LinkedList<int>* secondList);

LinkedList<int>* addLists(LinkedList<int>* firstList, LinkedList<int>* secondList);

void main()
{
	LinkedList<int>* firstList = new LinkedList<int>();
	LinkedList<int>* secondList = new LinkedList<int>();
	LinkedList<int>* answerPtr = new LinkedList<int>();

	bool quit = false;
	do {
		std::string again;

		firstList->clear();
		secondList->clear();

		fillList(firstList);
		fillList(secondList);

		evenUpLists(firstList, secondList);
		answerPtr = addLists(firstList, secondList);
		

		std::cout << std::endl << std::endl << "your answer is : ";
		printList(answerPtr);

		std::cout << std::endl << "Press any key to run again or \".\" to quit: ";
		std::getline(cin, again);
		if (again == ".")
		{
			quit = true;
		}

	} while (!quit);
}

void fillList(LinkedList<int>* aList)
{
	
	std::string number ="";
	do {
		std::cout << std::endl << std::endl << "Enter an integer to add : ";
		std::getline(std::cin, number);
	} while (number == "");

	convertList(aList,number);
}

void convertList(LinkedList<int>* aList, std::string number)
{
	for (int i = 0; i < number.length(); i++)
	{
		int intNumber = number[i] - '0';
		aList->insert(1, intNumber);
	}
}

void evenUpLists(LinkedList<int>* firstList, LinkedList<int>* secondList)
{
	if (firstList->getLength() < secondList->getLength())
	{
		int oneLength = firstList->getLength();
		int difference = secondList->getLength() - oneLength;
		oneLength += 1;
		for (int i = 0;i < difference; i++)
		{
			firstList->insert(oneLength +i , 0);
		}
	}
	if (secondList->getLength() < firstList->getLength())
	{
		int onelength = secondList->getLength();
		int difference = firstList->getLength() - onelength;
		onelength += 1;
		for (int i = 0; i < difference;i++)
		{
			secondList->insert(onelength + i, 0);
		}
	}
	
}



void printList(LinkedList<int>* aList)
{
	
	for (int i = 1;i < aList->getLength()+1;i++)
	{
		std::cout << aList->getEntry(i);
	}
}

LinkedList<int>* addLists(LinkedList<int>* firstList, LinkedList<int>* secondList)
{

	LinkedList<int>* answerPtr = new LinkedList<int>();
	bool addOne = false;
	for (int i= 1; i <= firstList->getLength();i++)
	{
		
		int num = firstList->getEntry(i) + secondList->getEntry(i);
		if (addOne)
		{
			num = num + 1;
			std::cout << std::endl << "num in add one = " << num;
			addOne = false;
		}
		if (num >= 10)
		{
			num = num - 10;
			addOne = true;		
		}
		std::cout<<::std::endl << "num = " << num;
		answerPtr->insert(1, num);
	}

	return answerPtr;
}


