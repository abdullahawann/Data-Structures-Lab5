#include <iostream>
using namespace std;

class SinglyLinkedList;

struct node
{
	friend class SinglyLinkedList;
	int data;
	node* next;
};

class SinglyLinkedList
{
	node* top;
	int currsize;

public:
	SinglyLinkedList()
	{
		top=NULL;
		currsize=0;
	}

	void push(int val)
	{
		node*temp = new node;
		temp->next = top;
		temp->data = val;
		top = temp;
		currsize++;
	}

	int size()
	{
		return currsize;
	}

	bool isempty()
	{
		if(top == NULL)
			return true;
		else 
			return false;
	}

	bool Top(node& ad)
	{
		if(isempty())
		{
			return false;
		}
		else
		{
			ad=*top;
			return true;
		}
	}

	void pop()
	{
		if(isempty())
		{
			cout << "Stack is empty" << endl;
		}
		else
		{
			top=top->next;
			currsize--;
		}
	}

	SinglyLinkedList sort(SinglyLinkedList ll)
	{
		SinglyLinkedList s;
		while(!ll.isempty())
		{
			int temp=ll.top->data;
			ll.pop();
		   while(!s.isempty() && s.top->data < temp)
		   {
			   ll.push(s.top->data);
			   s.pop();
		   }
		   s.push(temp);
		}
		return s;
	}

	void delete_mid_value()
	{
		if(isempty())
		{
			cout<<"stack empty"<<endl;
		}
		else
		{
			int count=((currsize+1)/2)-2;
			node*cur=top;
			while(count>0){
				cur=cur->next;
				count--;
			}
			cur->next=cur->next->next;
			currsize--;

			cout << "The middle value of stack deleted" << endl;
		}
	}

	bool palindrome(SinglyLinkedList ll)
	{
		SinglyLinkedList st;
		node*cur=ll.top;
		int check;
		while(cur!=NULL)
		{
			st.push(cur->data);
			cur=cur->next;
		}
		cur=ll.top;
		while(cur!=NULL)
		{
			check=st.top->data;
			st.pop();
			if(cur->data != check)
				return false;
			cur=cur->next;
		}
		return true;
	}

	void sum(int val)
	{
		node*temp, *cur;
		temp=top;
		int flag=0;

		while(temp->next!=nullptr)
		{
			cur=temp->next;
			while(cur!=NULL)
			{
				if(temp->data+cur->data==val)
				{
					cout << "in stack " << temp->data << "+" << cur->data << "=" <<val << endl;
					cur=cur->next;
					flag=1;
				}
				else
				{
					cur=cur->next;
					continue;
				}
			}
			temp=temp->next;
		}
		if(flag==0)
			cout << "No two element in stack exist whose sum is " << val << endl;
	}

	void display()
	{
		node *cur;
		cur=top;
		while(cur!=nullptr)
		{
			cout<<cur->data<<" ";
			cur=cur->next;
		}
		cout<<endl;
	}
};

int main()
{
	SinglyLinkedList l1;
	node* ad = new node;

	cout<< "Before entering elements the function isEmpty returns the value : " << l1.isempty() << endl;
	l1.push(10);
	l1.push(11);
	l1.push(12);
	l1.push(11);
	l1.push(10);
	cout << "The elements of stack are : "; 
	l1.display();
	cout<< "Size of the stack is : " << l1.size() << endl;
	cout<< "After entering elements the function isEmpty returns the value : " << l1.isempty() << endl;
	cout<< "The function top returns the value : " << l1.Top(*ad) << endl;

	if(l1.palindrome(l1) == 1)
	{
		cout << "The stack is palindrome" << endl;
	}
	else
	{
		cout << "The stack is not a palindrome" << endl;
	}

	l1=l1.sort(l1);
	cout << "After sorting the stack becomes : ";
	l1.display();
	l1.sum(5);
	l1.delete_mid_value();
	cout << "Top value of stack popped" << endl;
	l1.pop();
	cout << "After popping and deleting the mid value stack becomes : ";
	l1.display();
	cout << "The time complexity of code is O(1)" << endl;
	cout << endl;

	system("pause");
	return 0;
}

//The time complexity of code is O(1)