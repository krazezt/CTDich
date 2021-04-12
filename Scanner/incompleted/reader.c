/* 
 * @copyright (c) 2008, Hedspi, Hanoi University of Technology
 * @author Huu-Duc Nguyen
 * @version 1.0
 */

#include <stdio.h>
#include "reader.h"

FILE *inputStream;
int lineNo, colNo;                        //lineNo là số chỉ vị trí dòng, bắt đầu từ 1, colNo là vị trí kí tự trong dòng, bắt đầu từ 1
int currentChar;

int readChar(void) {                      //Đọc từng kí tự trong file, thực hiện tăng giá trị của lineNo và colNo để kiểm soát vị trí dang đọc trong file
  currentChar = getc(inputStream);
  colNo ++;
  if (currentChar == '\n') {
    lineNo ++;
    colNo = 0;
  }
  return currentChar;
}

int openInputStream(char *fileName) {
  inputStream = fopen(fileName, "rt");
  if (inputStream == NULL)
    return IO_ERROR;
  lineNo = 1;
  colNo = 0;
  readChar();
  return IO_SUCCESS;
}

void closeInputStream() {
  fclose(inputStream);
}