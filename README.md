cat
---

A buggy, insecure, non-portable but simple implementation of GNU's `/bin/cat`.
See `man 1 cat`.

### get started

```
$ make
$ ./cat Makefile
```

### try this

```
$ ./cat > foo.c
void
foo (void) {
  printf("writing from commandline - but not echo");
}
^C
$
```
