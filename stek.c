#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//создание структуры
typedef struct Stek		//структура Стек
{
	char *name;			//поле Имя
	char *number;		//поле Телефон
	struct Stek *next;	//указатель на структуру типа Stek
} Stek;					//переменная структуры Stek

//добавление элемента
void push(Stek **head, char *inName, char *inNumber)
{
	printf("Push\n");
	Stek *tmp = (Stek*) malloc(sizeof(Stek));
	tmp->name = inName;
	tmp->number = inNumber;
	tmp->next = *head;
	*head = tmp;
	printf("Push+\n");
}

//вывод элемента стека
int pop(Stek **head)
{
	Stek *cur;
	printf("Voshli v pop\n\r");
	if (*head == NULL)
	{
		printf("Стек пуст\n\r");
		exit(EXIT_FAILURE);
	}
	cur = *head;
	*head = (*head)->next;
	printf("%s %s\n\r", &(cur->name), &(cur->number));
	free(cur);
	printf("Вывели последний элемент из стека");
	return 0;
}

//вывод листа
void printLinkedList(Stek **head)
{
	Stek *cur;
	while (*head != NULL)
	{
		printf("\n%s %s\n", &((*head)->name), &((*head)->number));
		cur = *head;
		*head = (*head)->next;
		free(cur);
	}
}

//удаление листа
/*void deleteList(Stek **head)
{
	while ((*head)->)
	{
		pop(head);
		*head = (*head)->next;
	}
	free(*head);
}*/

void main() {
	Stek *stekptr = NULL;
	/*stekptr = (Stek*) malloc(sizeof(struct Stek));*/
	char command[5];
	char *inName = (char *) malloc(sizeof(inName));
	char *inNumber = (char *) malloc(sizeof(inNumber));
	while (1)
	{
		printf("Введите команду push/pop или list\n");
		scanf("%s", command);
		if (command[1] == 'u')
		{
			printf("Введите через проблем имя и номер");
			scanf("%s %s", &inName, &inNumber);
			push(&stekptr, inName, inNumber);
		}
		else if(command[1] == 'o')
		{
			pop(&stekptr);
			/*printf("\n%s %d\n выведен из стека", data.name, data.number);*/
		}
		else if(command[1] == 'i')
		{
			printf("Вывод списка:\n");
			printLinkedList(&stekptr);
			printf("\nСписок удален:\n");
		}
		else if(command[1] == 'x')
		{
			break;
		}
	}

}
