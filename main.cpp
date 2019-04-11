#include <iostream>
#include "heap.h"
#include <cstring>
#include <string>
#include <math.h>
#include <stdio.h>


int main()
{	
	HeapQ<std::string> obj;
	int input;
	do{
		printf("Menu option: \n");
		printf("Input 1 to insert student, 2 to delete person, 3 to show top person, 4 to print all names, and 5 to end program.");
		std::cin>> input;

		if(input == 1)
		{
			bool another = true;
			do{
				std::string name;
				int priority;
				printf("input a name you would like to store in the heap: ");
				std::cin >> name;
				printf("Enter the priority of the name: ");
				std::cin >> priority;

				obj.Insert(name,priority);

				std::string choice;
				printf("Would you like to enter another name? \n");
				printf("input Y if yes and N if no: ");
				std::cin>> choice;

				if(choice == "Y" || choice =="y")
				{
					another = true;
				}
				else if(choice == "N" || choice == "n"){
					another = false;
				}

			}while(another);
		}
		else if(input == 2)
		{

			std::cout << "you deleted: " << obj.ExtractMax() << " from the list \n";
		}
		else if(input == 3)
		{
			//printf("%c is at the top of the heap \n", obj.peak());
			std::cout << obj.peak() << " is at the to of the heap \n";
		}
		else if(input == 4)
		{

			int depth = log2(obj.GetHeap_size());
			obj.PrintHeap(0,depth + 1);
		}

	}while(input != 5);

	return 0;
}
