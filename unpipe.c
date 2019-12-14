#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int ret_val;
	int pfd[2];
	char buff[32];
	char string1[] = "Hello, From unnamed pipe!";

	ret_val = pipe(pfd); /* Создание pipe */

	if (ret_val != 0) { /* Проверка на создание pipe */
		printf("Ошибка при создании Pipe");

		exit(1); /* Print error message and exit */
	}
	if (fork() == 0) {
		/*создание дочернего процесса */
		//close(pfd[0]); // Закрыть конец для чтения
		ret_val = write(pfd[1], string1, strlen(string1)); /*запись в pipe*/
		if (ret_val != strlen(string1)) {
			printf("Запись в pipe не удалась");
			exit(2);
		}
	}
	else {
		/*родитель */
		//close(pfd[1]); /* close the write end of pipe */
		ret_val = read(pfd[0], buff, strlen(string1)); /* Read from pipe */
		if (ret_val != strlen(string1)) {
			printf("Считалось не то что ожидалось\n");
			exit(3); /* Print error message and exit */
		}
		printf("Родитель считал: \"%s\" из дочерки\n", buff);
	}
	exit(0);
}
