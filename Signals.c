#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define RESET	"\033[0m"
#define RED		"\033[1;31m"
#define YELLOW	"\033[1:33m"
#define WHITE	"\033[1:37m"

struct sigaction sa;

void sigHandler(int sigNum) {
    printf("-----------------\n\rHandler starts...\n\r");
    if (sigNum == SIGHUP)       printf("Получено SIGHUP(1)\n\r");
    if (sigNum == SIGINT)       printf("Получено SIGINT(2)\n\r");
    if (sigNum == SIGQUIT)      printf("Получено SIGQUIT(3)\n\r");
    if (sigNum == SIGILL)       printf("Получено SIGILL(4)\n\r");
    if (sigNum == SIGTRAP)      printf("Получено SIGTRAP(5)\n\r");
    if (sigNum == SIGABRT)      printf("Получено SIGABRT(6)\n\r");
    if (sigNum == SIGBUS)       printf("Получено SIGBUS(7)\n\r");
    if (sigNum == SIGFPE)       printf("Получено SIGFPE(8)\n\r");
    if (sigNum == SIGKILL)      printf("Получено SIGKILL(9)\n\r");
    if (sigNum == SIGUSR1)      printf("Получено SIGUSR1(10)\n\r");
    if (sigNum == SIGSEGV)      printf("Получено SIGSEGV(11)\n\r");
    if (sigNum == SIGUSR2)      printf("Получено SIGUSR2(12)\n\r");
    if (sigNum == SIGPIPE)      printf("Получено SIGPIPE(13)\n\r");
    if (sigNum == SIGALRM)      printf("Получено SIGALRM(14)\n\r");
    if (sigNum == SIGTERM)      printf("Получено SIGTERM(15)\n\r");
    if (sigNum == SIGSTKFLT)    printf("Получено SIGSTKFLT(16)\n\r");
    if (sigNum == SIGCHLD)      printf("Получено SIGCHLD(17)\n\r");
    if (sigNum == SIGCONT)      printf("Получено SIGCONT(18)\n\r");
    if (sigNum == SIGSTOP)      printf("Получено SIGSTOP(19)\n\r");
    if (sigNum == SIGTSTP)      printf("Получено SIGTSTP(20)\n\r");
    if (sigNum == SIGTTIN)      printf("Получено SIGTTIN(21)\n\r");
    if (sigNum == SIGTTOU)      printf("Получено SIGTTOU(22)\n\r");
    if (sigNum == SIGURG)       printf("Получено SIGURG(23)\n\r");
    if (sigNum == SIGXCPU)      printf("Получено SIGXCPU(24)\n\r");
    if (sigNum == SIGXFSZ)      printf("Получено SIGXFSZ(25)\n\r");
    if (sigNum == SIGVTALRM)    printf("Получено SIGVTALRM(26)\n\r");
    if (sigNum == SIGPROF)      printf("Получено SIGPROF(27)\n\r");
    if (sigNum == SIGWINCH)     printf("Получено SIGWINCH(28)\n\r");
    if (sigNum == SIGIO)        printf("Получено SIGIO(29)\n\r");
    if (sigNum == SIGPWR)       printf("Получено SIGPWR(30)\n\r");
    if (sigNum == SIGSYS)       printf("Получено SIGSYS(31)\n\r");
    printf("Handler ends...\n\r---------------\n\r");
}

int sigCatcher(void) {
    printf("-----------------------------------------------------\n\rCatcher starts (settings for signals interception)...\n\r");
    if (signal(SIGHUP, sigHandler) == SIG_ERR)       printf("Не получилось поймать сигнал SIGHUP(1)!!!\n\r");
    if (signal(SIGINT, sigHandler) == SIG_ERR)       printf("Не получилось поймать сигнал SIGINT(2)!!!\n\r");
    if (signal(SIGQUIT, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGQUIT(3)!!!\n\r");
    if (signal(SIGILL, sigHandler) == SIG_ERR)       printf("Не получилось поймать сигнал SIGILL(4)!!!\n\r");
    if (signal(SIGTRAP, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGTRAP(5)!!!\n\r");
    if (signal(SIGABRT, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGABRT(6)!!!\n\r");
    if (signal(SIGBUS, sigHandler) == SIG_ERR)       printf("Не получилось поймать сигнал SIGBUS(7)!!!\n\r");
    if (signal(SIGFPE, sigHandler) == SIG_ERR)       printf("Не получилось поймать сигнал SIGFPE(8)!!!\n\r");
    if (signal(SIGKILL, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGKILL(9) (by design in linux)!!!\n\r");
    if (signal(SIGUSR1, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGUSR1(10)!!!\n\r");
    if (signal(SIGSEGV, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGSEGV(11)!!!\n\r");
    if (signal(SIGUSR2, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGUSR2(12)!!!\n\r");
    if (signal(SIGPIPE, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGPIPE(13)!!!\n\r");
    if (sigaction(SIGALRM, &sa, 0) == -1)            printf("Не получилось поймать сигнал SIGALRM(14)!!!\n\r");
    if (signal(SIGTERM, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGTERM(15)!!!\n\r");
    if (signal(SIGSTKFLT, sigHandler) == SIG_ERR)    printf("Не получилось поймать сигнал SIGSTKFLT(16)!!!\n\r");
    if (signal(SIGCHLD, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGCHLD(17)!!!\n\r");
    if (signal(SIGCONT, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGCONT(18)!!!\n\r");
    if (signal(SIGSTOP, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGSTOP(19) (by design in linux)!!!\n\r");
    if (signal(SIGTSTP, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGTSTP(20)!!!\n\r");
    if (signal(SIGTTIN, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGTTIN(21)!!!\n\r");
    if (signal(SIGTTOU, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGTTOU(22)!!!\n\r");
    if (signal(SIGURG, sigHandler) == SIG_ERR)       printf("Не получилось поймать сигнал SIGURG(23)!!!\n\r");
    if (signal(SIGXCPU, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGXCPU(24)!!!\n\r");
    if (signal(SIGXFSZ, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGXFSZ(25)!!!\n\r");
    if (signal(SIGVTALRM, sigHandler) == SIG_ERR)    printf("Не получилось поймать сигнал SIGVTALRM(26)!!!\n\r");
    if (signal(SIGPROF, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGPROF(27)!!!\n\r");
    if (signal(SIGWINCH, sigHandler) == SIG_ERR)     printf("Не получилось поймать сигнал SIGWINCH(28)!!!\n\r");
    if (signal(SIGIO, sigHandler) == SIG_ERR)        printf("Не получилось поймать сигнал SIGIO(29)!!!\n\r");
    if (signal(SIGPWR, sigHandler) == SIG_ERR)       printf("Не получилось поймать сигнал SIGPWR(30)!!!\n\r");
    if (signal(SIGSYS, sigHandler) == SIG_ERR)       printf("Не получилось поймать сигнал SIGSYS(31)!!!\n\r");
    printf("Catcher ends...\n\r---------------\n\r");
    return 0;
}

int main(void) {
    struct sigaction sa;					//объявление структуры sigaction
    sigset_t newset;						//объявление новой группы сигналов
    sigemptyset(&newset);					//инициализация группы newset
    sigaddset(&newset, SIGALRM);			//добавление сигнала SIGALRM в группу newset
    sigprocmask(SIG_BLOCK, &newset, 0);		//настройка группы newset - блокировка
    sa.sa_handler = sigHandler;				//объявление обработчика
    pid_t sigPid;
    int sigPtr = 0;
	for (int i = 1; i < 31; i++) {
		sigPtr ++;

		if ((sigPid = fork()) == 0) {
       		printf("Дочка создана...\n\r");
        	if ((int)sigPid == 0) {
            	sigCatcher();
       		}
        while (1);
    	}
   		else {
			sleep(1);
        	printf("Parent sends signal number %d to child...\n\r", sigPtr);
		    kill(sigPid, sigPtr);
       		printf("Parent waits\n\r");
        	sleep(1);
			printf("\n\n\r");
		}
/*        if (*sigPtr != 9) {
            printf("Parent additionally kills child program...\n\r");
            kill(sigPid, 9);
        }
        else printf("Additionall kill is not required\n\r");
*/
	}
    return 0;
}
