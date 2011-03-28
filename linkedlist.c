#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

struct node* BuildOneTwoThree();
int Length(struct node* head);
void Push(struct node** headRef, int newData);
void CountTest();
int Count(struct node*,int);
void GetNthTest();
int GetNth(struct node* head, int index); 
void DeleteListTest();
void DeleteList(struct node** headRef);
void PopTest();
int Pop(struct node** headRef);
void InsertNth(struct node** headRef, int index, int data); 
void InsertNthTest(); 
void SortedInsertTest();
void SortedInsert(struct node** headRef, struct node* newNode); 
void TestAppend();
void Append(struct node**,struct node**);
struct node* BuildOneTwo(); 
void InsertSort(struct node** headRef); 
void TestInsertSort();
void TestFrontBackSplit();
void FrontBackSplit(struct node* source,
struct node** frontRef, struct node** backRef); 
void FrontBackSplit();
void TestRemoveDuplicates();
void RemoveDuplicates(struct node* head);
void MoveNode(struct node** destRef, struct node** sourceRef); 
void MoveNodeTest(); 
void TestAlternatingSplit();
void AlternatingSplit(struct node* source,
struct node** aRef, struct node** bRef); 
struct node* ShuffleMerge(struct node* a, struct node* b); 
void TestShuffleMerge();
struct node* SortedMerge(struct node* a, struct node* b);
void TestSortedMerge(); 
struct node* SortedIntersect(struct node* a, struct node* b);
void TestSortedIntersect(); 
void ReverseTest(); 
void Reverse(struct node** headRef); 
void RecursiveReverseTest();
void RecursiveReverse(struct node** headRef); 
 
struct node {
int data;
struct node* next;
};

int main()
{
//CountTest();
//GetNthTest();
//DeleteListTest();
//PopTest();
//InsertNthTest();
//SortedInsertTest();
//TestAppend();
//Finish the test insert sort..
//TestInsertSort();
//TestFrontBackSplit();
//TestRemoveDuplicates();
//MoveNodeTest();
//TestAlternatingSplit();
//TestShuffleMerge();
//TestSortedMerge();
//TestSortedIntersect();
//ReverseTest();
RecursiveReverseTest();
return 0;
}


// Build and return the list {1, 2, 3}
struct node* BuildOneTwoThree() {
struct node* head = NULL; // Start with the empty list
Push(&head, 3);
// Use Push() to add all the data
//Push(&head, 4);
Push(&head, 2);
//Push(&head, 2);
Push(&head, 1);
return(head);
}
struct node* BuildOneTwo() {
struct node* head = NULL; // Start with the empty list
//Push(&head, 4);
Push(&head, 3);
//Push(&head, 3);
//Push(&head, 3);
//Push(&head, 3);
Push(&head,2);
Push(&head, 1);
//Push(&head, 1);

// Use Push() to add all the data
/*Push(&head, 8);
Push(&head, 60);
Push(&head, 400);
Push(&head, 2);*/
return(head);
}
// Given a reference (pointer to pointer) to the head
// of a list and an int, push a new node on the front of the list.
// Creates a new node with the int, links the list off the .next of the
// new node, and finally changes the head to point to the new node.
void Push(struct node** headRef, int newData) {
struct node* newNode =
(struct node*) malloc(sizeof(struct node));
// allocate node
newNode->data = newData;
// put in the data
newNode->next = (*headRef);
// link the old list off the new node
(*headRef) = newNode;
// move the head to point to the new node
}


// Return the number of nodes in a list
int Length(struct node* head) {
int count = 0;
struct node* current = head;
while (current != NULL) {
count++;
current=current->next;
}
return(count);
}


//Problem 1
void CountTest() {
struct node* myList = BuildOneTwoThree();
int count = Count(myList, 2);
printf("%d \n",count);
// build {1, 2, 3}
// returns 1 since there's 1 '2' in the list
}
/*
Given a list and an int, return the number of times that int occurs
in the list.
*/
int Count(struct node* head, int searchFor) {

int count=0;
struct node* curr = head;
while(curr!=NULL)
{
  if(curr->data == searchFor)
    count++;
  curr = curr->next;

}
return count;

}


//2nd problem

void GetNthTest() {
struct node* myList = BuildOneTwoThree();
int lastNode = GetNth(myList, 2);
printf("Searched node is %d \n",lastNode);
}


// Given a list and an index, return the data
// in the nth node of the list. The nodes are numbered from 0.
// Assert fails if the index is invalid (outside 0..lengh-1).
int GetNth(struct node* head, int index) {
// Your code
//int position = Length(head);
int i = 0;

struct node* curr = head;

while(curr!=NULL)
{

  if(i == index)
    return curr->data;
  curr = curr->next;
  i++;  
  assert(index >= 0 && curr!=NULL);
}
return -1;

}


//3rd problem

void DeleteListTest() {

struct node* myList = BuildOneTwoThree();
// build {1, 2, 3}
DeleteList(&myList); // deletes the three nodes and sets myList to NULL

if(myList == NULL)
{
  printf("success \n");
}
else
{
  printf("abcd %d \n",myList->data);
}

}


void DeleteList(struct node** headRef) {

struct node* curr;
while((*headRef) != NULL)
{
  curr = *headRef;
  (*headRef) = (*headRef)->next;
  free(curr);
  
}

}

//Problem 4
void PopTest() {
struct node* head = BuildOneTwoThree();
int a = Pop(&head); // deletes "1" node and returns 1
printf("%d \n",a);
int b = Pop(&head); // deletes "2" node and returns 1
printf("%d \n",b);
int c = Pop(&head); // deletes "3" node and returns 1
printf("%d \n",c);
int len = Length(head);
printf("%d \n",len);
// the list
}

/*
The opposite of Push(). Takes a non-empty list
and removes the front node, and returns the data
which was in that node.
*/
int Pop(struct node** headRef) {
// your code...
assert((*headRef) != NULL);
struct node* curr = *headRef;
*headRef = (*headRef)->next;
int value = curr->data;
free(curr);
return value;
}


//Problem 5

void InsertNthTest() {
struct node* head = NULL;
InsertNth(&head, 0, 13);
struct node* curr = head;
while(curr != NULL)
{
  printf("%d \n",curr->data);
  curr = curr->next;
}
InsertNth(&head, 1, 42);
curr = head;
while(curr != NULL)
{
  printf("%d \n",curr->data);
  curr = curr->next;
}
InsertNth(&head, 1, 5);
curr = head;
while(curr != NULL)
{
  printf("%d \n",curr->data);
  curr = curr->next;
}
DeleteList(&head);
while(curr != NULL)
{
  printf("%d \n",curr->data);
  curr = curr->next;
}
}
// start with the empty list
// build {13)
// build {13, 42}
// build {13, 5, 42}
// clean up after ourselves


/*
A more general version of Push().
Given a list, an index 'n' in the range 0..length,
and a data element, add a new node to the list so
that it has the given index.
*/
void InsertNth(struct node** headRef, int index, int data) {
// your code...
  int i=0;
  struct node* curr = *headRef;
  struct node* new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
if(index == 0)
{
  new_node->next = (*headRef);
  (*headRef) = new_node;
}
else
{
  while((curr) != NULL)
  {
    if(i == index - 1)
    {
      new_node->next = curr->next;
      curr->next = new_node;
    }
    curr = curr->next;
    i++;  
  }

}

}

void SortedInsertTest()
{
struct node* head = BuildOneTwoThree();
struct node* newNode = (struct node*)malloc(sizeof(struct node));
newNode->data = 5;
newNode->next = NULL;
SortedInsert(&head,newNode);
struct node* curr = head;
while(curr != NULL)
{
  printf("%d \n",curr->data);
  curr = curr->next;
}

}
//Given a sorted list, insert the node at the right place.
void SortedInsert(struct node** headRef, struct node* newNode) {
// Your code...
struct node* temp;
struct node* curr = *headRef;
if(curr != NULL)
{
  while(curr != NULL)
  {
    if(curr->data > newNode->data)
      break;
    temp = curr;
    curr = curr->next;
  }
  newNode->next = curr;
  if(temp!= NULL)
  {
    temp->next = newNode;
   // curr = newNode;
  }
  else
  {
    (*headRef) = newNode;
    
  }

}
else
{
  (*headRef) = newNode; 
}

}

void TestInsertSort() {
struct node* head = BuildOneTwo();
InsertSort(&head);
struct node* temp = head;
while(temp != NULL)
{
  printf("sorted list is %d \n",temp->data);
  temp = temp->next;
}

}

void InsertSort(struct node** headRef) { // Your code
struct node* sortedList = NULL;
struct node* head = *headRef;
while(head != NULL)
{
  SortedInsert(&sortedList,head);
  head = head->next;

}

struct node* p = sortedList;
while(p != NULL)
{
  printf("%d  \n",p->data);
  p = p->next;

}

}



void TestAppend()
{
struct node* aList = BuildOneTwoThree();
struct node* head = aList;
struct node* bList = BuildOneTwo();
struct node* head1 = bList;
printf("address of a head is  %p \n",aList);
Append(&head,&head1); 
printf("address of a head is  %p \n",aList);

struct node* head2 = aList;
while(head != NULL)
{ 
  printf("%d \n",head->data);
  head = head->next;  
}
  
}

// Append 'b' onto the end of 'a', and then set 'b' to NULL.
void Append(struct node** aRef, struct node** bRef) {
// Your code...
struct node* tempA = *aRef;
struct node* temp = *aRef;
while((tempA)!= NULL)
{
  printf("aref in loop is %d \n",(tempA)->data);
  temp = tempA;
  (tempA) = (tempA)->next;
}
temp->next = (*bRef);
(*bRef) = NULL;

}

void PrintList(struct node* head)
{
  struct node* temp = head;
  if(head == NULL)
    printf("Linked list is empty ..... \n \n" );
  else
    printf("Printing the linked list ..... \n \n" );
  while(temp != NULL)
  {
    printf("%d \n",temp->data);
    temp = temp->next;
  }
}
void TestFrontBackSplit()
{
struct node* head = BuildOneTwo();
struct node* frontHead = NULL;
struct node* backHead = NULL;
FrontBackSplit(head,&frontHead,&backHead);
struct node* headf = frontHead;
printf("Head List \n _______________________________ \n");
PrintList(headf);
struct node* headb = backHead;
printf("Back List \n _______________________________ \n");
PrintList(headb);
}

/*
Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.
*/
void FrontBackSplit(struct node* source,
struct node** frontRef, struct node** backRef) {
// Your code...

(*frontRef) = source;
struct node* front = (*frontRef);
int length = Length(source); 
int index = 0,iterations;
if(length == 1)
{
  iterations = length - 1;
}
else
{
  if(length%2 == 0)
    iterations = length/2 - 1;
  else
    iterations = length/2;
}
while(front != NULL)
{
   if(iterations  == index)
   {
    (*backRef) = front->next;
    front->next = NULL;
    break;
   }
index++;
front = front->next;
}

}

void TestRemoveDuplicates()
{
  struct node* head = BuildOneTwo();
  printf("Original linked list with duplicates is \n \n");
  PrintList(head);
  RemoveDuplicates(head);
  printf("Linked list without duplicates is \n \n");
  PrintList(head);

}

/*
Remove duplicates from a sorted list.
*/
void RemoveDuplicates(struct node* head) {
// Your code...
struct node* temp = head;
while(temp != NULL)
{
  struct node* temp1 = temp->next;
  if(temp1 != NULL)
  {
    if(temp->data == temp1->data)
    {
      struct node* duplicate = temp->next;
      while(temp->data == duplicate->data)
      {
        //temp->next = (temp->next)->next
        duplicate = duplicate->next;
       
      }
      temp->next = duplicate;
    }
  }

    temp = temp->next;
}


}


void MoveNodeTest() {
struct node* a = BuildOneTwoThree();
struct node* b = BuildOneTwoThree();
// the list {1, 2, 3}
PrintList(a);
PrintList(b);
MoveNode(&a, &b);
printf("Printing new dest .... \n \n");
PrintList(a);
printf("Printing new source .... \n \n");
PrintList(b);
// a == {1, 1, 2, 3}
// b == {2, 3}
}
/*
Take the node from the front of the source, and move it to
the front of the dest.
It is an error to call this with the source list empty.
*/
void MoveNode(struct node** destRef, struct node** sourceRef) {
// Your code
if((*sourceRef) != NULL)
{
  struct node* dest = (*destRef);
  (*destRef) = (*sourceRef);
  struct node* source = (*sourceRef)->next;
  (*sourceRef) = source; 
  (*destRef)->next = dest;
}

}

void TestAlternatingSplit()
{
  struct node* source = BuildOneTwoThree();
 // PrintList(source);
  struct node* aRef = NULL;
  struct node* bRef = NULL;
  AlternatingSplit(source,&aRef,&bRef);
  printf("Sorted list is ..... \n \n");
  PrintList(bRef);
  PrintList(aRef);  
} 

/*
Given the source list, split its nodes into two shorter lists.
If we number the elements 0, 1, 2, ... then all the even elements
should go in the first list, and all the odd elements in the second.
The elements in the new lists may be in any order.
*/
void AlternatingSplit(struct node* source,
struct node** aRef, struct node** bRef) {
// Your code
//(*aRef) = source;
struct node* tempA = source;
int length = Length(source);
int iterations = 0;
while(iterations != (length))
{
  iterations++;
  if(iterations%2)
     MoveNode(bRef,&source);
  else
    MoveNode(aRef,&source);

//  if(tempA != NULL)
//    tempA = tempA->next;
}

}


void TestShuffleMerge()
{
  struct node* a = BuildOneTwo();
  struct node* b = BuildOneTwoThree();
  struct node* merged = ShuffleMerge(a,b);  
  struct node* temp = merged;
  PrintList(temp);
}

/*
Merge the nodes of the two lists into a single list taking a node
alternately from each list, and return the new list.
*/
struct node* ShuffleMerge(struct node* a, struct node* b) {
// Your code
struct node* merged = NULL;
while((a != NULL) || (b != NULL))
{
  if(b != NULL)
    MoveNode(&merged,&b);

  if(a != NULL)
    MoveNode(&merged,&a);

} 
return merged;

}

void TestSortedMerge()
{
  struct node* a = BuildOneTwo();
  struct node* b = BuildOneTwoThree();
  struct node* merged = SortedMerge(a,b);  
  struct node* temp = merged;
  PrintList(temp);

}


/*
Takes two lists sorted in increasing order, and
splices their nodes together to make one big
sorted list which is returned.
*/
struct node* SortedMerge(struct node* a, struct node* b) {
// your code...
struct node* merged = NULL;
while((a != NULL) || (b != NULL))
{
  if((a != NULL) && (b != NULL))
  {
    if(a->data < b->data)
     MoveNode(&merged,&a);
    else if(a->data > b->data)
     MoveNode(&merged,&b);

  }
  else if(a != NULL)
     MoveNode(&merged,&a);
  else if(b != NULL)
     MoveNode(&merged,&b);

}

return merged;

}

void TestSortedIntersect()
{
  struct node* a = BuildOneTwo();
  struct node* b = BuildOneTwoThree();
  struct node* merged = SortedIntersect(a,b);  
  struct node* temp = merged;
  PrintList(temp);
} 

/*
Compute a new sorted list that represents the intersection
of the two given sorted lists.
*/
struct node* SortedIntersect(struct node* a, struct node* b) {
// Your code
struct node* head = NULL;

while((a != NULL) && (b != NULL))
{
  if(a->data == b->data)
  {
    Push(&head,a->data);
    a = a->next;
    b = b->next;
  }
  else if(b->data < a->data)
  {
    while(b != NULL)
    {
      if(b->data < a->data)
        b = b->next;
      else
        break;
    } 
  }
  else if(b->data > a->data)
  {
     while(a != NULL )
     {
       if(b->data > a->data)
         a = a->next;
       else
         break;
     }

  }  
   
}
return head;

}

void ReverseTest() {
struct node* head;
head = BuildOneTwoThree();
PrintList(head);
Reverse(&head);
PrintList(head);
DeleteList(&head);
}

void Reverse(struct node** headRef) {
// your code...

struct node* headTemp = (*headRef);
struct node* prevNode = NULL;
struct node* newNode = NULL;
while((*headRef) != NULL)
{
  newNode = (*headRef)->next;
  (*headRef)->next = prevNode;
  prevNode = (*headRef);
  (*headRef) = newNode;  
}
(*headRef) = prevNode;

}

void RecursiveReverseTest()
{
  struct node* head = BuildOneTwoThree();
  PrintList(head);
  RecursiveReverse(&head);
  PrintList(head);
}

/*
Recursively reverses the given linked list by changing its .next
pointers and its head pointer in one pass of the list.
*/
void RecursiveReverse(struct node** headRef) {
// your code...

struct node* next = (*headRef)->next;
struct node* previous = (*headRef);
(*headRef) = next;

if((*headRef) != NULL)
{
  RecursiveReverse(headRef);

}

if((*headRef) == NULL)
  (*headRef) = previous;
else
{
  next->next = previous;
  previous->next = NULL;
}
}
