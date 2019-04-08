#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include "command.h"
#include "coder.h"

int main(int argc, char *argv[])
{
  if (argc > 4) {
    printf("Invalid number of arguments\n");
    return -1;
  }

  if (strcmp(argv[1], "encode") == 0 /*&& strcmp(argv[2], "points.txt") == 0 && strcmp(argv[3], "units.bin") == 0*/) {
    encode_file(argv[2], argv[3]);
  } else if (strcmp(argv[1], "decode") == 0 /*&& strcmp(argv[2], "units.bin") == 0 && strcmp(argv[3], "points.txt") == 0*/) {
    decode_file(argv[2], argv[3]);
  } else {
    printf("Invalid command\n");
    return -1;
  }

  return 0;
}
