#include <unistd.h>
#include <syscall.h>

#define STRING_COMMA_LEN(STR) (STR), (sizeof (STR) - 1)

static int
length (const char *s)
{
  int l;

  for (l = 0; *s++ != 0; l++);
  return l;
}

int
main (int argc, char **argv)
{
  int i;
  int fd = STDOUT_FILENO;

  syscall (SYS_write, fd, STRING_COMMA_LEN ("a\n"));
  i = 7 / 0;
  syscall (SYS_write, fd, STRING_COMMA_LEN ("b\n"));
  syscall (SYS_exit, 0);
  return 0;
}
