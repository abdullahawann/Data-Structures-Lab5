#include <iostream>
using namespace std;

class Queue;

struct node
{
	friend class Queue;
	int data;
	node *next;
};

class Queue
{
	int currsize;
	int maxsize;
	node* front;
	node* rear;

public:
	Queue(int max)
	{
		currsize=0;
		front=NULL;
		rear=NULL;
		maxsize=max;
	}

	int size()
	{                            
		return currsize;         
	}

	bool isempty()
	{                      
		if(rear==NULL)
			return 1;            
		else 
			return 0; 
	}

	bool frontone(node &ad)
	{                
		if(front !=nullptr)
		{
			ad=*front;
			return 1;                     
		}
		else 
			return false;
	}

	void dequeue()
	{                         
		if(isempty())
			cout << "Queue is empty" << endl;
		else if(front != rear)
		{
		    node*temp;
		    temp=front;
			front=front->next;
			rear->next=front;                  
			delete temp;
			currsize--;
		}
		else
		{
			node*temp;
			temp=front;
			front=NULL;
			rear=NULL;
			delete temp;
			currsize--;
		}
	}

	void enqueue(int val)
	{                             
		node*temp=new node;
		temp->data=val;
		if(currsize==maxsize)
		{
			cout<<"Queue is full"<<endl;
		}
		else if(isempty())
		{
			front=temp;
			rear=temp;
			currsize++;
		}
		else
		{
			temp->next=front;
			rear->next=temp;
			rear=temp;
			currsize++;
		}
	}

	void display()
	{                                     
		node*cur=front;
		int count=0;
		while(count<currsize)
		{
			cout<<cur->data<<" ";
			cur=cur->next;
			count++;
		}
		cout << endl;
	}
};

int main()
{
	Queue l1(5);
	node* a = new node;
	 
	cout<< "Before entering elements the function isEmpty returns the value " << l1.isempty() << endl;
	cout<< "Before entering elements the size of the queue is : " << l1.size() << endl;
	l1.enqueue(10);
	l1.enqueue(11);
	l1.enqueue(12);
	l1.enqueue(13);
	l1.enqueue(14);
	cout << "The elements of queue are : ";
	l1.display();
	l1.enqueue(15);                                  //this will not be added because queue is full
	cout << "New size of queue is " << l1.size() << endl;
	cout << "The function Front returns the value : " << l1.frontone(*a) << endl;
	l1.dequeue();
	cout << "After deleting front element queue becomes : ";
	l1.display();
	cout << "The time complexity of code is O(1)" << endl << endl;

	system("pause");
	return 0;
}

// The time complexity if code is O(1)