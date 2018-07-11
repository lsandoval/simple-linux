#include <unistd.h>
#include <link.h>
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
  char **ev = &argv[argc + 1];
  char **evp = ev;

  while (*evp++ != NULL)
    ;

  ElfW(auxv_t) *av = (ElfW(auxv_t) *) evp;
  const ElfW(Phdr) *phdr = NULL;
  size_t phnum = 0;

  for (; av->a_type != AT_NULL; ++av)
    switch (av->a_type)
      {
      case AT_PHDR:
	phdr = (const void *) av->a_un.a_val;
	break;
      case AT_PHNUM:
	phnum = av->a_un.a_val;
	break;
      }

  size_t i;
  size_t loadnum = 0;
  for (i = 0; i < phnum; i++, phdr++)
    if (phdr->p_type == PT_LOAD)
      loadnum++;

  syscall (SYS_exit, !loadnum);
  return 0;
}
