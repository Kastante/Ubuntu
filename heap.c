#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>



//Просто swap
int swap(int heap[], int i, int j)
{
	int temp = heap[i];							//----
	heap[i] = heap[j];							//swap
	heap[j] = temp;								//----
	return 0;
}

//Вывод массива (просто чтобы был)
void heapVis(int length, int heap[])
{
	for (int i = 0; i <= length - 1; i++)
		printf("%d ", heap[i]);
}

//формирование вершины кучи
void inTop(int heap[], int i, int size)
{
	int j = 2 * i + 1;									
	if (j + 1 <= size && heap[j + 1] > heap[j])		//определения максимального основания триады;
		j = j + 1;									

	if (heap[j] > heap[i])
		swap(heap, i, j);
}

//сортировка
void heapSort(int* heap, int size, int length)
{
	int count = 1;
	printf("Ход выполнения:\n");
	while (size > 0)
	{
		if (int i = (size % 2) != 0)
		{
			for (int i = (size / 2); i >= 0; i--)	// Перетаскивание вершины
				inTop(heap, i, size);
		}
		else
		{
			for (int i = (size / 2) - 1; i >= 0; i--)// Перетаскивание вершины
				inTop(heap, i, size);
		}

		printf("%d. ", count);
		heapVis(size + 1, heap);
		printf("\n");

		if (heap[0] > heap[size])					// Исключение залипания при size = 1, когда heap[0] < heap [size]
		{
			printf("   Swap: %d <-> %d\n", heap[0], heap[size]);
			swap(heap, 0, size);
		}
		size--;
		count++;
	}
}

//меню
int menu(int* menu)
{
	printf("\nВыберие 1 из вариантов:\n");
	printf("1. Сделать сортировку кучей\n");
	printf("2. Выход\n>> ");
	scanf("%d", menu);
	return 0;
}

//инициализация рандомной сортировки
void initRandSort()
{
	int length;
	printf("\nВведите количество элементов от 5 до 100: ");
	scanf("%d", &length);

	int heap[100];
	srand(time(NULL));
	for (int i = 0; i <= length - 1; i++)
		heap[i] = rand() % 101;
	printf("Сортируемая куча:\n>> ");
	heapVis(length, heap);
	printf("\n\n");

	heapSort(heap, length - 1, length);

	printf("\nРезультат сортировки:\n>> ");
	heapVis(length, heap);
	printf("\n\r");
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int program = 0;
	int cur;
	while (program == 0)
	{
		menu(&cur);
		switch (cur)
		{
			case 1:
			{
				initRandSort();
				break;
			}
			case 2:
			{
				program = 1;
				break;
			}
			default:
			{
				printf("Такого пункта в меню нет:(\n\r");
			}
		}
	}
	return 0;
}
