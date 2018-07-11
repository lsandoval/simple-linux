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

  for (i = 0; i < argc; i++)
    {
      syscall (SYS_write, fd, argv [i], length (argv [i]));
      syscall (SYS_write, fd, STRING_COMMA_LEN (" "));
    }
  syscall (SYS_write, fd, STRING_COMMA_LEN ("\n"));

  syscall (SYS_exit, 0);
  return 0;
}
