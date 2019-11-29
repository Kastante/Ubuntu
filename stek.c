#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <locale.h>


//создание структуры
typedef struct Stek		//структура Стек
{
	char* name;			//поле Имя
	char* number;		//поле Телефон
	struct Stek* next;	//указатель на структуру типа Stek
} Stek;					//переменная структуры Stek

//добавление элемента
void push(Stek** head, char* inName, char* inNumber)
{
	Stek* tmp = (Stek*)malloc(sizeof(Stek));
	tmp->name = inName;
	tmp->number = inNumber;
	tmp->next = *head;
	*head = tmp;
}

//вывод элемента стека
int pop(Stek **head)
{
	Stek* cur;
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
}

//вывод листа
void printLinkedList(Stek** head)
{
	Stek* cur;
	while (*head != NULL)
	{
		cur = *head;
		*head = (*head)->next;
		printf("%s %s\n\r", &(cur->name), &(cur->number));
		free(cur);
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	Stek* stekptr = NULL;
	/*stekptr = (Stek*) malloc(sizeof(struct Stek));*/
	char command[5];
	char* inName = (char*)malloc(sizeof(inName));
	char* inNumber = (char*)malloc(sizeof(inNumber));
	while (1)
	{
		printf("Введите команду push/pop или list\n");
		scanf("%s", command);
		if (command[1] == 'u')
		{
			printf("Введите через проблем имя и номер: ");
			scanf("%s %s", &inName, &inNumber);
			push(&stekptr, inName, inNumber);
		}
		else if (command[1] == 'o')
		{
			pop(&stekptr);
			/*printf("\n%s %d\n выведен из стека", data.name, data.number);*/
		}
		else if (command[1] == 'i')
		{
			printf("Вывод списка:\n");
			printLinkedList(&stekptr);
			printf("Список удален\n");
		}
		else if (command[1] == 'x')
		{
			break;
		}
	}

}
