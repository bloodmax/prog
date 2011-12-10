#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

 
#ifndef NULL
#define NULL  0
#endif
 
typedef const char*  cchar;
 
 
 struct account  {
   //   int visual;
   //   int number;

     int  data;
     struct account *nextPtr;
 };
 
 // эту функцию - добавления в список данных  можешь удалить у тебя наверное свои есть
 void  add(struct account** plist, int data) {
      if(! plist) {
          (*plist) = (struct account*) malloc(sizeof(struct account));
 

          (*plist)->data     = data;
 
          (*plist)->nextPtr  = NULL;
      } else {
          struct account*  ptr = (struct account*) malloc(sizeof(struct account));
 
 
          ptr->data     = data;
 
          ptr->nextPtr = *plist;
          *plist = ptr;
      }
 
 }

void  adds(struct account* plist, int data) {
	struct account*  first = plist, *last;
	last  = plist->nextPtr;
	int    id, tmp;
/*
	while(plist != NULL) {
		if( (plist->data > data) && (plist->nextPtr->data <= data) ) {
			last = malloc(sizeof(struct account));
			last->nextPtr = plist->nextPtr;
			plist->nextPtr = last;
			last->data = data;
			break;
		}
		plist = plist->nextPtr;}
*/  
	 // while(plist != NULL)

	for( ; last != NULL ; last = last->nextPtr, first = first->nextPtr)  {
		if((first->data < data) && (last->data >= data)) {

		
			 struct account*  ptr = (struct account*) malloc(sizeof(struct account));
 			ptr->data     = data;
			ptr->nextPtr = last;
			first->nextPtr = ptr;

			break;
		}

		if((first->data < data) && (last->nextPtr == NULL)) {

		
			 struct account*  ptr = (struct account*) malloc(sizeof(struct account));
 			ptr->data     = data;
			
			first->nextPtr = last;
			last->nextPtr = ptr;
			ptr->nextPtr = NULL;
			break;
		}
	}              
	         
}





	void  delete(struct account* plist, int pos) {
	struct account*  first;
	struct account*  last;
	int    id, tmp, sch=0;
	first = plist;
	last  = plist->nextPtr;
	pos--;
	for( ; last != NULL ; last = last->nextPtr, first = first->nextPtr) 
	{
	if (pos-1==sch) 
	{
	last=last->nextPtr;
	first->nextPtr=last;
	break;
	}
	sch++;                 
	}           
	}
	 
	void  deletev(struct account* plist, int pos) {
	     struct account*  first;
		struct account*  last;
		int    id, tmp;
		       first = plist;
		       last  = plist->nextPtr;

		   for( ; last != NULL ; last = last->nextPtr, first = first->nextPtr) 
		{
				if (last->data==pos) 
			{
	last=last->nextPtr;
	first->nextPtr=last;
	break;
			}                
		}           
	 }


	 void  sort_list(struct account*  plist) {
		struct account*  first;
		struct account*  last;
		int    id, tmp;

		while(1) {
		       id = 0;
		       first = plist;
		       last  = plist->nextPtr;
		       for( ; last != NULL ; last = last->nextPtr, first = first->nextPtr) {
	 
			   if(first->data > last->data  ) {
	 
				  
	 
				  tmp          = first->data;
				  first->data = last->data;
				  last->data  = tmp;
	 
			   
				  id |= 1;
			   }
		       }
		       if(! id)
			   break;
	 
		};
	 }
	 

	 
	 
	int main(void)
	{
	     struct account* spisok = NULL;
	     struct account* list = NULL;

	   
	 
	 
	     // добавляем в список людей
	 srand(time(NULL));
	int j;int temp2=0;
	for (j=0;j<5;j++){add(&list,rand() % 100);};

	printf("\n  _________________ORIGINAL LIST__________________________ \n");

	     spisok = list;
	     while(spisok != NULL) {
		  printf("number: %d\n",  spisok->data);
		 spisok = spisok->nextPtr;
	     }
	      sort_list(list);
	 

	  printf("\n  __________________SORTED LIST_________________________ \n");
	     spisok = list;
	     while(spisok != NULL) {
		  printf("number: %d\n",  spisok->data);
		 spisok = spisok->nextPtr;
	     }

	//добавление с сортировкой
	  printf("\n  __________________TYPE INTEGER TO ADD_________________________ \n");
	scanf ("%d",&temp2);
	adds(list,temp2);
	printf("\n  ____________________UPDATED LIST_______________________ \n");
	     // выводим отсортированный список
     spisok = list;
     while(spisok != NULL) {
          printf("number: %d\n",  spisok->data);
         spisok = spisok->nextPtr;
     }


 //удаление элемента
 delete(list,3);
  printf("\n  __________________UPDATED LIST (3 element was deleted)_______________________ \n");
     // выводим отсортированный список
     spisok = list;
     while(spisok != NULL) {
          printf("number: %d\n",  spisok->data);
         spisok = spisok->nextPtr;
     }
  printf("\n  __________________TYPE VALUE TO DELETE_________________________ \n");
scanf ("%d",&temp2);

 deletev(list,temp2);
printf("\n  ____________________UPDATED LIST_______________________ \n");
     spisok = list;
     while(spisok != NULL) {
          printf("number: %d\n",  spisok->data);
         spisok = spisok->nextPtr;
     }
  printf("\n  __________________TYPE INTEGER TO ADD_________________________ \n");
scanf ("%d",&temp2);
add(&list,temp2);
printf("\n  ____________________UPDATED LIST_______________________ \n");
     // выводим отсортированный список
     spisok = list;
     while(spisok != NULL) {
          printf("number: %d\n",  spisok->data);
         spisok = spisok->nextPtr;
     }
     puts("\n");
     // чистим список
     while(list != NULL) {
          spisok = list;
          list = list->nextPtr;
          free(spisok);
          spisok = NULL;
     }
     list = NULL;
 

   return 0;
}
 
