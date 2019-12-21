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
    if (sigNum == SIGHUP)       printf("Получено %sSIGHUP%s%s(1)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGINT)       printf("Получено %sSIGINT%s%s(2)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGQUIT)      printf("Получено %sSIGQUIT%s%s(3)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGILL)       printf("Получено %sSIGILL%s%s(4)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGTRAP)      printf("Получено %sSIGTRAP%s%s(5)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGABRT)      printf("Получено %sSIGABRT%s%s(6)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGBUS)       printf("Получено %sSIGBUS%s%s(7)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGFPE)       printf("Получено %sSIGFPE%s%s(8)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGKILL)      printf("Получено %sSIGKILL%s%s(9)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGUSR1)      printf("Получено %sSIGUSR1%s%s(10)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGSEGV)      printf("Получено %sSIGSEGV%s%s(11)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGUSR2)      printf("Получено %sSIGUSR2%s%s(12)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGPIPE)      printf("Получено %sSIGPIPE%s%s(13)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGALRM)      printf("Получено %sSIGALRM%s%s(14)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGTERM)      printf("Получено %sSIGTERM%s%s(15)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGSTKFLT)    printf("Получено %sSIGSTKFLT%s%s(16)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGCHLD)      printf("Получено %sSIGCHLD%s%s(17)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGCONT)      printf("Получено %sSIGCONT%s%s(18)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGSTOP)      printf("Получено %sSIGSTOP%s%s(19)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGTSTP)      printf("Получено %sSIGTSTP%s%s(20)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGTTIN)      printf("Получено %sSIGTTIN%s%s(21)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGTTOU)      printf("Получено %sSIGTTOU%s%s(22)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGURG)       printf("Получено %sSIGURG%s%s(23)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGXCPU)      printf("Получено %sSIGXCPU%s%s(24)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGXFSZ)      printf("Получено %sSIGXFSZ%s%s(25)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGVTALRM)    printf("Получено %sSIGVTALRM%s%s(26)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGPROF)      printf("Получено %sSIGPROF%s%s(27)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGWINCH)     printf("Получено %sSIGWINCH%s%s(28)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGIO)        printf("Получено %sSIGIO%s%s(29)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGPWR)       printf("Получено %sSIGPWR%s%s(30)%s\n\r", YELLOW, RESET, RED, RESET);
    if (sigNum == SIGSYS)       printf("Получено %sSIGSYS%s%s(31)%s\n\r", YELLOW, RESET, RED, RESET);
    printf("Handler ends...\n\r---------------\n\r");
}

int sigCatcher(void) {
    printf("-----------------------------------------------------\n\rCatcher starts (settings for signals interception)...\n\r");
    if (signal(SIGHUP, sigHandler) == SIG_ERR)       printf("Не получилось поймать сигнал SIGHUP(1)!!!\n\r");
    if (signal(SIGINT, sigHandler) == SIG_ERR)       printf("Не получилось поймать сигнал SIGINT(2)!!!\n\r");
    if (signal(SIGQUIT, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGQUIT(3)!!!\n\r");
    if (sigaction(SIGILL, &sa, 0) == -1)             printf("Не получилось поймать сигнал SIGILL(4)!!!\n\r");
    if (signal(SIGTRAP, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGTRAP(5)!!!\n\r");
    if (signal(SIGABRT, sigHandler) == SIG_ERR)      printf("Не получилось поймать сигнал SIGABRT(6)!!!\n\r");
    if (sigaction(SIGBUS, &sa, 0) == -1)             printf("Не получилось поймать сигнал SIGBUS(7)!!!\n\r");
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
    while (sigPtr <=30) {
        sigPtr++;

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
            sleep(2);
            printf("\n\n\r");
        }

    }
    return 0;
}
