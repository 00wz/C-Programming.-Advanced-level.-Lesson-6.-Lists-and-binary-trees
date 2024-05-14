#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STR_SIZE 2000
typedef struct list
{
	char* word;
	struct list *next;
}list;

/* Без заглавного элемента и без двойного
указателя*/
list* insert2(char* value,list *head);
void print_list(list * head);
void delete_list(list *head);
void removeOdd(list *head);

int main(int argc, char** argv)
{
	list *w_list=NULL;
	char word[STR_SIZE]="";
	int ch = ' ';
	int i=0;
	while(EOF != (ch = getchar()))
	{
		switch(ch)
		{
			case '.':
			case ' ':
				word[i] = '\0';
				if(i > 0)
				{
					w_list = insert2(word, w_list);
				}
				i=0;
				break;
			default:
				word[i++] = ch;
				if(i>=STR_SIZE)
				i=0;//Защита от переполнения строки
		}
		if('.' == ch)
		break;
	}
	
	removeOdd(w_list);
	print_list(w_list);
	
	delete_list(w_list);
	return 0;
}

void removeOdd(list *head)
{
	list *odd;
	while(head)
	{
		if(head -> next)
		{
			odd = head -> next;
			head -> next = odd -> next;
			head = odd -> next;
			free(odd);
		}
		else
		{
			break;
		}
	}
}

void delete_list(list * l)
{
	list * c =l;
	list * n;
	while(c != NULL) 
	{
		n = c->next;
		free(c->word);//Очищаем паять под слово
		free(c);
		c = n;
	}
}

/* Без заглавного элемента и без двойного указателя*/
list* insert2(char* value,list *head)
{
	list *res = (list*)calloc(1,sizeof(list));
	int len = strlen(value);//определяем размер строки
	res->word = malloc(len+1);//выделяем память под строку
	strcpy(res->word, value);//копируем строку в память
	res->next = head;//смещаем указатель на следующий
	return res;
}

void print_list(list * head)
{
	if(head ->next)
	{
		print_list(head -> next);
	}
	printf("%s ", head -> word);
}
