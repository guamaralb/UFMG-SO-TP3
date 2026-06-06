#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  int pid = fork();
  if (pid == 0) {
    volatile int *p = 0;
    *p = 42;
    printf("nulltest: FAIL (child not killed)\n");
    exit(0);
  }
  int status;
  wait(&status);
  if (status != 0)
    printf("nulltest: OK (child killed with status %d)\n", status);
  else
    printf("nulltest: FAIL (child exited normally)\n");
  exit(0);
}
