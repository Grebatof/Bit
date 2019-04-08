#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include "hhh.h"

#define N 1000000

int main()
{
  FILE *fileG = NULL;
  FILE *fileB = NULL;
  fileB = fopen("uncompressed.bin", "wb");
  fileG = fopen("compressed.bin", "wb");


  uint32_t number;
  uint8_t * buf = (uint8_t *) malloc(sizeof(uint8_t));
  size_t size;

  for (int i = 0; i < N; i++) {

    number = generate_number();

    fwrite(&number, sizeof(uint32_t), 1, fileB);

    //buf = &number;
    size = encode_varint(number, buf);
    fwrite(buf, sizeof(uint8_t), size, fileG);

  }

  fseek(fileB, 0, SEEK_SET);
  fseek(fileG, 0, SEEK_SET);
  int k, j;
  uint32_t numberBad, numberGood;
  uint8_t * bufer = (uint8_t *) malloc(sizeof(uint8_t));

  // int garbage;
  //
  //
  // bufer = &garbage;

  // for (int i = 0; i < N; i++) {
  //
  //   fread(&numberBad, sizeof(uint32_t), 1, fileB);
  //   //printf("%6.d  ", numberBad);
  //
  //   //fread(bufer, sizeof(uint8_t), 1, fileG);
  //   //numberGood = decode_varint(&bufer);
  //   //printf("%6.d\n", numberGood);
  //
  // }

  for (k = 0, j = 0; j < N; k++, j++) {

    fseek(fileG, k, SEEK_SET);
    fread(bufer, sizeof(uint8_t), 4, fileG);
    numberGood = decode_varint((const uint8_t **)&bufer);
    fread(&numberBad, sizeof(uint32_t), 1, fileB);
    if (numberGood > 127) k++;
    if (numberGood > 16383) k++;
    if (numberGood > 2097151) k++;

    if (numberBad != numberGood) {
      printf("!!!!!!!!!!!!!!\n");
      break;
    }

    //printf("j = %3.d numberGood = %6.d numberBad = %6.d k = %3.d\n", j, numberGood, numberBad, k);

  }

  // for (int i = 1; i < 4; i++) {
  //   fseek(fileG, N - 4 + i, SEEK_SET);
  //   fread(bufer, sizeof(uint8_t), 4 - i, fileG);
  //   numberGood = decode_varint(&bufer);
  //   printf("%6.d %d\n", numberGood, N - 4 + i);
  // }

  fclose(fileB);
  fclose(fileG);

  return 0;
}







//  РАБОТА НАГЛЯДНО С N +- ЭЛЕМЕНТОМ
//  РАБОТА НАГЛЯДНО С N +- ЭЛЕМЕНТОМ
//  РАБОТА НАГЛЯДНО С N +- ЭЛЕМЕНТОМ
//  РАБОТА НАГЛЯДНО С N +- ЭЛЕМЕНТОМ
//  РАБОТА НАГЛЯДНО С N +- ЭЛЕМЕНТОМ




// int main()
// {
//   FILE *fileG = NULL;
//   FILE *fileB = NULL;
//   fileB = fopen("uncompressed.bin", "r+b");
//   fileG = fopen("compressed.bin", "r+b");
//
//
//   uint32_t number;
//   uint8_t * buf;
//   size_t size;
//
//
//   for (int i = 0; i < N; i++) {
//
//     number = generate_number();
//     printf("%d %6.d\n", i, number);
//
//     fwrite(&number, sizeof(uint32_t), 1, fileB);
//
//     buf = &number;
//     size = encode_varint(number, buf);
//     fwrite(buf, sizeof(uint8_t), size, fileG);
//
//   }
//
//
//   printf("!!!!!!!!!!!!!!!!!!!!!\n");
//
//
//   fseek(fileB, 0, SEEK_SET);
//   fseek(fileG, 0, SEEK_SET);
//   int k, j;
//   uint32_t numberBad, numberGood;
//   uint8_t * bufer;
//
//   int garbage;
//
//   bufer = &garbage;
//
//   for (int i = 0; i < N; i++) {
//
//     fread(&numberBad, sizeof(uint32_t), 1, fileB);
//     //printf("%6.d  ", numberBad);
//
//     //fread(bufer, sizeof(uint8_t), 1, fileG);
//     //numberGood = decode_varint(&bufer);
//     //printf("%6.d\n", numberGood);
//
//   }
//
//   for (k = 0, j = 0; j < N; k++, j++) {
//
//     fseek(fileG, k, SEEK_SET);
//     fread(bufer, sizeof(uint8_t), 4, fileG);
//     numberGood = decode_varint(&bufer);
//
//     if (numberGood > 127) k++;
//     if (numberGood > 16383) k++;
//     if (numberGood > 2097151) k++;
//
//     printf("j = %3.d numberGood = %6.d k = %3.d\n", j, numberGood, k);
//
//   }
//
//   // for (int i = 1; i < 4; i++) {
//   //   fseek(fileG, N - 4 + i, SEEK_SET);
//   //   fread(bufer, sizeof(uint8_t), 4 - i, fileG);
//   //   numberGood = decode_varint(&bufer);
//   //   printf("%6.d %d\n", numberGood, N - 4 + i);
//   // }
//
//   fclose(fileB);
//   fclose(fileG);
//
//   return 0;
// }




//  РАБОТА НАГЛЯДНО С 1 ЭЛЕМЕНТОМ
//  РАБОТА НАГЛЯДНО С 1 ЭЛЕМЕНТОМ
//  РАБОТА НАГЛЯДНО С 1 ЭЛЕМЕНТОМ
//  РАБОТА НАГЛЯДНО С 1 ЭЛЕМЕНТОМ
//  РАБОТА НАГЛЯДНО С 1 ЭЛЕМЕНТОМ

// int main()
// {
//   FILE *fileG = NULL;
//   FILE *fileB = NULL;
//   int number;
//   uint32_t number1;
//
//   fileB = fopen("fileB.bin", "r+b");
//   fileG = fopen("fileG.bin", "r+b");
//
//
//   number = 56;
//   fwrite(&number, sizeof(int), 1, fileB);
//
//   uint32_t i = 200;
//   uint8_t * buf = &i;
//   size_t size;
//   uint32_t value;
//
//   printf("good file %d\n", i);
//
//   size = encode_varint(i, buf);
//
//   fwrite(buf, sizeof(uint8_t), 1, fileG);
//   ++buf;
//   fwrite(buf, sizeof(uint8_t), 1, fileG);
//   --buf;
//   value = decode_varint(&buf);
//
//   printf("good file %d\n", value);
//
//
//
//
//   fseek(fileB, 0, SEEK_SET);
//   fseek(fileG, 0, SEEK_SET);
//   int kkkkkkk = 100;
//   fread(&number, sizeof(int), 1, fileB);
//   uint8_t * buuf = &kkkkkkk;
//   printf("%X %d\n", buuf, *buuf);
//   fread(buuf, sizeof(uint8_t), 2, fileG);
//   printf("%X %d\n", buuf, *buuf);
//   number1 = decode_varint(&buuf);
//   printf("bad file %d\ngood file %d\n", number, number1);
//
//
//   fclose(fileB);
//   fclose(fileG);
//   return 0;
// }
