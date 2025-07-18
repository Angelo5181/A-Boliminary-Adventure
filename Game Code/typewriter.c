#include <string.h>
#include <windows.h>
#include <stdio.h>

const unsigned int delay = 17; // in milliseconds

void typeWriter(char text[20]) {
  int length = strlen(text);
  for (int i = 0; i < length; i++) {
    printf("%c", *(text + i));
    Sleep(delay);
  }
  printf("\n");
}

/**
 * *text is just a string, can be like: "Sample Text"
 * removeNewLine determines whether to remove the final '\n' from fgets()
 */
void typeWriterPointer(char *text, bool removeNewLine){
  printf("text:%s\n",text);
  int length = strlen(text);
  for (int i = 0; i < length; i++) {
    if(removeNewLine){
      if((i+1) == length && *(text + i) == '\n'){
        printf("\0");
      }else{
        printf("%c", *(text + i));
      }  
    } else {
      printf("%c", *(text + i));
    }
    Sleep(delay);
  }
  printf("\n");
  //printf("%d %s\n", length, text);
}