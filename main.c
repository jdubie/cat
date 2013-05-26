/*
 * Include dependencies
 */

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>


/*
 * Define constants
 */

#define CHUNK_SIZE 256
#define STDIN        0
#define TRUE         1


/*
 * Foward declare helpers
 */

int print_fd (int fd);
int print_filename (char *filename);

int
main (int argc, char *argv[])
{
  if (argc < 1) {
    return -1;
  } else if (argc == 1) {
    print_fd (STDIN);
  } else {
    int i;
    for (i = 1; i < argc; i++) {
      int status = print_filename (argv[i]);
      if (status == -1) {
        printf ("error opening file %d\n", i);
        return status;
      }
    }
  }
  return 0;
}

int
print_filename (char *filename)
{
  int fd = open (filename, 0, O_RDONLY);
  if (fd < 0) return -1;

  print_fd (fd);
  close (fd);

  return 0;
}

int
print_fd (int fd)
{
  while (TRUE) {
    char buf[CHUNK_SIZE];
    ssize_t bytes_read = read (fd, buf, CHUNK_SIZE);
    fwrite (buf, sizeof(char), bytes_read, stdout);

    if (bytes_read == 0) break; /* EOF */
  }
  return 0;
}
