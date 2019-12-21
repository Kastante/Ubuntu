#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <iostream>
#include <string>

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

//проверка поля
char * scan(char* buf, int mass[10][10], int counter)
{
	std::string line;
	char* recv;
	int i = buf[0];
	int j = buf[1];
	if (mass[i][j] == 1) {
		mass[i][j] = 0;
		counter--;
		std::string line = "Попадание!";

	}
	if (counter == 0) {
		std::string line = "Противников больше не осталось.";
	}
	return strcpy(recv, line.c_str ());
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

//серверная часть (настройка и подключение)
void server() {
	int listenfd = 0, connfd = 0;
	struct sockaddr_in serv_addr;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&serv_addr, '0', sizeof(serv_addr));
	memset(sendBuff, '0', sizeof(sendBuff));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(5000);

	bind(listenfd, (struct sockaddr*) & serv_addr, sizeof(serv_addr));

	listen(listenfd, 10);
}

//серверная часть (ожидание подключения к серверу)
void serverIn(int mass[10][10], int counter) {
	int sockfd = 0, n = 0;
	char sendBuff[1025];
	char data[1025], recvBuff[1025];
	struct sockaddr_in serv_addr;

	while (1) {
		memset(recvBuff, '0', sizeof(recvBuff));
		connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);

		sockfd = socket(AF_INET, SOCK_STREAM, 0

		memset(&serv_addr, '0', sizeof(serv_addr));

		serv_addr.sin_family = AF_INET;
		serv_addr.sin_port = htons(5001);

		n = read(sockfd, recvBuff, sizeof(recvBuff) - 1);

		char * data = scan(recvBuff, mass, counter);
		recvBuff[n] = 0;

		snprintf(sendBuff, sizeof(sendBuff), "%s\r\n", data);
		write(connfd, sendBuff, strlen(sendBuff));

		close(connfd);
	}
}

//клиентская часть (отправка координат)
void client() {
	int sockfd = 0, n = 0;
	char recvBuff[1024], sendBuff[1024];
	struct sockaddr_in serv_addr;

//бесконечный опрос сервера
	while (1) {
		scanf("%s\n\r", sendBuff);

		memset(recvBuff, '0', sizeof(recvBuff));
		if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		{
			printf("\n Error : Could not create socket \n");
			return 1;
		}

		memset(&serv_addr, '0', sizeof(serv_addr));

		serv_addr.sin_family = AF_INET;
		serv_addr.sin_port = htons(5001);

		if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
		{
			printf("\n inet_pton error occured\n");
			return 1;
		}

		if (connect(sockfd, (struct sockaddr*) & serv_addr, sizeof(serv_addr)) < 0)
		{
			printf("\n Error : Connect Failed \n");
			return 1;
		}

		send(sockfd, sendBuff, sizeof(sendBuff), 0);
		sendBuff[n] = 0;
		n = read(sockfd, recvBuff, sizeof(recvBuff) - 1)
		recvBuff[n] = 0;

		if (fputs(recvBuff, stdout) == EOF)
		{
			printf("\n Error : Fputs error\n");
		}
	}

	if (n < 0)
	{
		printf("\n Read error \n");
	}
}

/*//отправка pipe
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
}*/

int main() {
	int cond[10];					//массив условий
	int mass[10][10];				//поле
	condit(cond);					//заполнение массива условий (массив распределения)
	field(cond, mass);				//заполнение поля
	int coord[2], program = 0, cur = 1, counter = 25;
	server();
	while (program == 0)
	{
		switch (cur) {
			case 1: {
				printf("\nКапитан, нужны новые координаты цели через пробел! (X Y) 0-9\n");
				scanf("%s\n\r", coord);
				printf("%s", coord[1]);
				printf("output");
				serverIn(mass, counter);
				//cur = output(coord);
				break;
			}
			case 2: {
				//cur = input(mass, counter);
				client();
				printf("input");
				break;
			}
		}
	}
	return 0;
}
