#include "stdafx.h"
struct DEQ{
	int data;
	DEQ *prev,*next;
};
int size;
DEQ *front,*back;	//beginning and end of the list;
//function add element at the beginning of list;
void pushFront(int p)	
{
	DEQ* pel=new DEQ;
	pel->data=p;
	if(front==NULL){	//add first element;
		back=pel;
		pel->next=NULL;
	}else{
		pel->next=front;
		front->prev=pel;
	}
	front=pel;
	pel->prev=NULL;
	size++;
}
//function add element at the end of list;
void pushBack(int p)
{
	DEQ* pel=new DEQ;
	pel->data=p;
	if (front==NULL)	
	{
		front=pel;
		pel->prev=NULL;
	}else{
		pel->prev=back;
		back->next=pel;
	}
	pel->next=NULL;
	back=pel;
	size++;
}
//function insert element at position "pos";
void insertAt(int pos,int p)
{
	int i=(int)0;
	if(pos<=(int)0){	//add element at the beginning of list;
		pushFront(p);
	}else if(pos>=size)
	{
		pushBack(p);	//add element at the and of list;
	}else{
		DEQ* bef=front;
		DEQ* after;
		DEQ* pel=new DEQ;
		pel->data=p;
		while(i<pos){	//find element, befor which insert new element;
			bef=bef->next;
			i++;
		}
		after=bef->prev;
		bef->prev=pel;
		pel->next=bef;
		pel->prev=after;
		after->next=pel;
		size++;
	}
}
	//get first element
int popFront(void)
{
	int res=front->data;
	front=front->next;
	delete front->prev;
	front->prev=NULL;
	size--;
	return res;
}
	//get last element;
int popBack(void)
{
	int res=back->data;
	back=back->prev;
	delete back->next;
	back->next=NULL;
	size--;
	return res;
}
	//print all list from beginng;
void print(void)
{
	DEQ* pel=front;
	while(pel!=NULL){
		printf("i=%d\n",pel->data);
		pel=pel->next;
	}
}
//function return element by it number;
int at(int pos)
{
	int i=(int)0;
	DEQ* pel=front;
	if((pos<(int)0)||(pos>size-(int)1)){
		puts("Error! Index out of bound!");
		return (int)-1;
	}
	while(i<pos){
		i++;
		pel=pel->next;
	}
	return pel->data;
}
//function delete element by it position;
int deleteAt(int pos)
{
	DEQ*pel=front;
	int res;
	int i=(int)0;
	if(pos<=(int)0)
		return popFront();	//delete first element;
	if(pos>size)
		return popBack();	//delete last element;
	while(i<pos){			//find element;
		i++;
		pel=pel->next;
	}
	res=pel->data;
	pel->prev->next=pel->next;
	pel->next->prev=pel->prev;
	size--;
	delete pel;
	return res;
}
//function delete list;
void delDEQ(void)
{	
	DEQ*pel=front;
	while(pel!=NULL){
		front=pel->next;
		delete pel;
		pel=front;
		size--;
	}
	back=NULL;
}
int _tmain(int argc, _TCHAR* argv[])
{
	for(int i=(int)0;i<4;i++){
		pushBack(i*i);
	}
	puts("print()");
	print();
	getchar();

	puts("insertAt(1,-100)");	//insert element;
	insertAt((int)1,(int)-100);
	print();
	getchar();

	puts("popFront()");		//delete first element; 
	popFront();
	print();
	getchar();

	puts("popBack()");		//delete last element;
	popBack();
	print();
	getchar();

	puts("pushFront(-1)");	//insert element at first position;
	pushFront((int)-1);
	print();
	getchar();

	printf("at(3)=%d\n",at((int)3));//get 3rd element;
	getchar();

	puts("insertAt(size,-3)");	//delete element;
	insertAt(size,(int)-3);
	print();
	getchar();

	puts("deleteAt(1)");	//delete element;
	deleteAt((int)1);
	print();
	getchar();

	puts("Free list");		//delete all elements;
	delDEQ();
	print();
	getchar();
	return 0;
}

