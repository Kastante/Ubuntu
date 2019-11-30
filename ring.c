// Stek.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <locale.h>


//создание структуры
typedef struct Stek		//структура Стек
{
	char* info;			//поле информации
	struct Stek* next;	//указатель на следующую структуру типа Stek
	struct Stek* prev;	//указатель на пердыдущую структуру типа Stek
} Stek;					//переменная структуры Stek

//добавление элемента
void push(Stek** head, char* inInfo)
{
	Stek* tmp = (Stek*)malloc(sizeof(Stek));
    if (*head == NULL)
    {
        tmp->info = inInfo;
        tmp->next = tmp;
        tmp->prev = tmp;
        *head = tmp;
    }
    else
    {
        tmp->info = inInfo;
        tmp->prev = *head;
    	tmp->next = (*head)->next;
    	(*head)->next = tmp;
    	(tmp->next)->prev = tmp;
    	*head = tmp;
    }
}

//вывод элемента стека
int pop(Stek **head)
{
	printf("Voshli v pop\n\r");
	if (*head == NULL)
	{
		printf("Стек пуст\n\r");
	}
	else if (((*head)->prev) == *head)
	{
	    printf("%s\n\r", &((*head)->info));
	    free(*head);
	    *head = NULL;
	   	printf("Вывели первый элемент из списка\n");
	}
	else
	{
	    Stek *cur = *head;
	    (cur->prev)->next = cur->next;
	    (cur->next)->prev = cur->prev;
	    printf("%s\n\r", &(cur->info));
	    *head = cur->prev;
	    free(cur);
	    printf("Вывели последний из списка\n");
	}

}

//вывод листа
void printLinkedList(Stek** head)
{
    Stek *cur = *head;
    int length = 0;
    if(*head == NULL)
    {
        printf("Список пуст\n\r");
    }
    else
    {
    	printf("-Вывод списка-\n");
        printf("Элементы:\n");
        do
        {
            printf("%s\n\r", &((*head)->info));
            length++;
            *head = (*head)->next;
        }   while (*head != cur);
        printf("Длина списка: %d\n\r", length);
    }
}

//вывод элемента с информацией
void printOnes(Stek** head)
{
    char Ones;
    printf("Введите информацию из ячейки:\n\r");
    scanf("%s\n\r", Ones);
    while (((*head)->info) != Ones)
    {
        *head = (*head)->next;
    }
    printf("%s\n\r", (*head)->info);
}

int main() {
	setlocale(LC_ALL, "Rus");
	Stek* stekptr = NULL;
	char command[5];
	char* inInfo = (char*)malloc(sizeof(char)*20);
	while (1)
	{
		printf("Введите команду push/pop или list\n");
		scanf("%s", command);
		if (command[1] == 'u')
		{
			printf("Введите через проблем имя и номер: ");
			scanf("%s", &inInfo);
			push(&stekptr, inInfo);
		}
		else if (command[1] == 'o')
		{
			pop(&stekptr);
		}
		else if (command[1] == 'i')
		{
			printLinkedList(&stekptr);
		}
		else if (command[1] == 'e')
		{
		    printOnes(&stekptr);
		}
		else if (command[1] == 'x')
		{
			break;
		}
	}

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
