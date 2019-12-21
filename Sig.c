#include <stdio.h>
#include <signal.h>

void sig_handler(int signum) {
	signal(signum, sig_handler);
	printf("Сигнал пойман %i", signum);
}

int main(int argc, char** argv) {
	signal(SIGTERM, sig_handler);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while(1) pause();
}
