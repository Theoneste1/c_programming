/*This programming will take the sentense entered by user the make it into an different words*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define delimitter " "


int main(){

 char sentence[1000];
 
 printf("Please, enter the sentence that you want:\n");
  // we use this function to clean the buffer
   fflush(stdin);
   fgets(sentence, 500, stdin);
  
 //This will separate the whole sentence based on delimitter defined which is "."
  char *token=strtok(sentence," ");
  //loop in all words which are in the sentence
  while(token!=NULL){
   //token not NULL, Then print it
    printf("%s\n",token);
   //take a dot and replace it with the next word
   //The following statement will then help in going to the next word,
   // If there is not, it will point to null
   token=strtok(NULL, " ");
  }
 
return 0;
}

 
