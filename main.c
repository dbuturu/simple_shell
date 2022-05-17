#include "main.h"

int waiting = 0;

void handler(int sig) {
  int status;
  waitpid(-1, &status, WNOHANG);
}

int main() {
  int inte = 1, status, count;
  char *prompt;
  pid_t pid;

  signal(SIGCHLD, handler);
  pid = fork();
  prompt = "($)";
  do {
    if (waiting == 1) {
      while (wait(NULL) != pid)
        ;
    }
    printf("%s", prompt);
    status = execute(get_args(get_line()), pid);
  } while (status);

  return 0;
}

