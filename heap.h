#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <stdio.h>
#include <math.h>

template <class T>
struct Heapobj{
	T data;
	int key;
};

template<class T>
class HeapQ{
	private:
		Heapobj<T>* arr;
		int heap_size;
		int size;

		void IncreaseKey(int, int);
		void Maxheapify(int);
		void BuildMaxHeap();
		void resizeHeap();

	public:
		HeapQ(){
			size = 10;
			heap_size = 0;
			arr = new Heapobj<T>[size];
		}
		~HeapQ(){
			delete [] arr;
		}
		T ExtractMax();
		T peak();
		void Insert(T, int);
		void PrintHeap(int,int);
		int GetHeap_size();
};

/***********************************************************************************************/
//ResizeHeap function										/
//Used to resize the heap if the user enters more than 10 people in the tree			/
/***********************************************************************************************/
	template<class T>
void HeapQ<T>::resizeHeap()
{
	size = size * 2;
	Heapobj<T> *temp = new Heapobj<T>[size];
	for(int i = 0; i < heap_size; i++)
	{
		temp[i] = arr[i];
	}
	arr = temp;
}

/***********************************************************************************************/
//GetHeap_size function										/
//Used in my main as a way to determine the level of my tree to print				/
/***********************************************************************************************/
	template<class T>
int HeapQ<T>::GetHeap_size()
{
	return heap_size;
}

/***********************************************************************************************/
//IncreaseKey function										/
//called by enqueue, used to put the names in a tree form from highest to lowest		/
/***********************************************************************************************/
	template <class T>
void HeapQ<T>::IncreaseKey(int i, int key)
{
	int parent = floor(i/2);
	if(arr[i].key > key)
	{
		std::cout << "ERROR" << std::endl;
	}
	else{
		arr[i].key = key;
		while(i > 1 && arr[i].key > arr[parent].key)
		{
			Heapobj<T> temp = arr[i];
			arr[i] = arr[parent];
			arr[parent] = temp;
			i = parent;
		}
	}
}

/***********************************************************************************************/
//ExtractMax function										/
//Also Known as dequeue, used to delete the to priority person and return their name.		/
//Then calls maxheapify to put tree in heap order.						/
/***********************************************************************************************/
	template <class T>
T HeapQ<T>::ExtractMax()
{
	T temp = arr[0].data;
	arr[0] = arr[heap_size - 1];
	heap_size = heap_size - 1;
	Maxheapify(0);
	return temp;
}

/***********************************************************************************************/
//Peak Function											/
//Returns the name with the highest priority in the tree					/
/***********************************************************************************************/
	template<class T>
T HeapQ<T>::peak()
{
	return arr[0].data;
}

/***********************************************************************************************/
//Insert function										/
//Also known as enqueue, Used to insert person with their priority into the tree.		/									/***********************************************************************************************/
	template <class T>
void HeapQ<T>::Insert(T name, int priority)
{
	if(heap_size == size)
		resizeHeap();


	heap_size = heap_size + 1;
	arr[heap_size - 1].data = name;
	arr[heap_size - 1].key = priority;
	IncreaseKey(heap_size - 1, priority);
	Maxheapify(0);
}

/***********************************************************************************************/
//Print Heap function										/
//Used to print out the array in a heap tree from.						/
/***********************************************************************************************/
	template<class T>
void HeapQ<T>::PrintHeap(int level, int depth)
{
	int left = level;
	for(int i = 0; i < depth; i++)
	{
		for(int j = 0; j <= (pow(2,i) - 1); j++)
		{
			if((left + j) >= heap_size)
			{
				std::cout << "*" << "\t";
			}
			else
				std::cout << arr[left + j].data << "\t";
		
				//cout << arr[left + j].key << "\t";
		}
		std::cout << std::endl;
		left = 2*left + 1;
	}
}

/***********************************************************************************************/
//Maxheapify Function										/
//Used to reorganize tree if extract function was called and the top of the tree was deleted.	/									//												/
/***********************************************************************************************/
	template<class T>
void HeapQ<T>::Maxheapify(int i)
{
	int left = (2 * i);
	int right = (2 * i + 1);
	int largest;

	if(left <= heap_size && arr[left].key > arr[i].key)
	{
		largest = left;
	}
	else
	{
		largest = i;
	}
	if(right <= heap_size && arr[right].key > arr[largest].key)
	{
		largest = right;
	}
	if(largest != i)
	{
		std::swap(arr[i],arr[largest]);
		Maxheapify(largest);
	}
}

#endif
