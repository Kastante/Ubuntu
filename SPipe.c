#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUF 1024

//вызов поля
void vismass(int mass[10][10])
{
	for (int i = 0; i <= 9; i++) {
		printf("\n");
		for (int j = 0; j <= 9; j++) {
			printf("%d ", mass[i][j]);
		}
	}
}

//вызов массива условий
void viscond(int cond[])
{
	for (int i = 0; i <= 9; i++)
		printf("%d ", cond[i]);
}

//вызов суммы массива условий
void vissumcond(int cond[])
{
	int d = 0;
	for (int i = 0; i <= 9; i++) {
		d = d + cond[i];
	}
	printf("%d ", d);
}

//подсчет суммы массива
void vissummass(int mass[10][10])
{
	int d = 0;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			if (mass[i][j] == 1)
				d++;
		}
	}
	printf("%d ", d);
}

//массив условий
void condit(int cond[])
{
	int count = 0;
	int x = 0;

	srand(time(NULL));
	while (count < 25) {
		count = 0;
		for (int i = 0; i <= 9; i++) {
			if (count < 25) {
				cond[i] = rand() % 4 + 1;
				if ((count + cond[i]) < 25) {
					count = count + cond[i];
					printf("\n %d\n", count);
				}
				else {
					cond[i] = 25 - count;
					count = 25;
					printf("\n%d\n", count);
				}
			}
			else {
				cond[i] = 0;
			}
		}
	}
	viscond(cond);
	vissumcond(cond);
}

//рандомный массив 10х10 из 0\1 (25 - 1)
void field(int cond[], int mass[10][10])
{
	int max = 0;
	srand(time(NULL));
	for (int i = 0; i <= 9; i++) {
		int x = 0;
		for (int j = 0; j <= 9; j++) {
			if (x < cond[i]) {
				mass[i][j] = rand() % 2;
				if (mass[i][j] == 1)
					x++;
			}
			else if (mass[i][9] == 0 && i == 9 && x < 3) {
				mass[i][9] = 1;
			}
			else {
				mass[i][j] = 0;
			}
		}
	}
	vismass(mass);
}

//отправка pipe
int output(int coord[])
{
	int fd;
	char* output = "/tmp/output";

	mkfifo(output, 0666);			//созднание pipe

	fd = open(output, O_WRONLY);	//--
	write(fd, coord, 2);			//запись в pipe
	close(fd);						//ожидание чтение другого

	unlink(output);					//удаление pipe

	return 2;
}

//прием pipe
int input(int mass[10][10], int counter)
{
	int fd;
	char* input = "/tmp/input";
	char buf[MAX_BUF];

	fd = open(input, O_RDONLY);
	read(fd, buf, MAX_BUF);
	scan(buf, mass, counter);
	printf("Received: %s\n", buf);
	close(fd);

	return 1;
}

//проверка поля
void scan(char* buf, int mass[10][10], int counter)
{	
	int i = buf[0];
	int j = buf[1];
	if (mass[i][j] == 1) {
		printf("Попадание! %d %d\n", i, j);
		mass[i][j] = 0;
		counter--;
		printf("counter = %d\n", counter);
	}
	if (counter == 0) {
		printf("Противников больше не осталось. Победа за 1м");
	}
}



int main() {
	int cond[10];					//массив условий
	int mass[10][10];				//поле
	condit(cond);					//заполнение массива условий (массив распределения)
	field(cond, mass);				//заполнение поля
	int coord[2], program, cur = 1, counter = 25;
	while (program == 0)
	{
		switch (cur) {
			case 1: {
				printf("\nКапитан, нужны новые координаты цели через пробел! (X Y) 0-9\n");
				scanf("%d", &coord[0]);
				cur = output(coord);
				break;
			}
			case 2: {
				cur = input(mass, counter);
				break;
			}
		}
	}
	return 0;
}
