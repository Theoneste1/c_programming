/*This is a c programming which will check if ip address is valid or not*/
/*It will use the libraries such as stdio.h, string.h, stdlib.h, stdbool.h*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
//ip address has 4 parts, and the following function will check the validate of each part
/*
1. Ip address is not start by zero unless it is only zero.
2. Between 0 and 255.
3. It should only contains digit numbers between 0 and 9.
4. It should have 3 dots
*/

bool is_this_part_validate(char *string){

int length=strlen(string), i,j;

//not start by zero
if((string[0]=='0' && strlen(string)>1)==true){
return false;
}

//numbers should be between 0 and 9 digit

for(i=0; i<length; i++){
if((string[i]>='0' && string[i]<='9')==false){
return false;
}
}
//check if the  number is between 0 and 255
return(string>="0" && string<="255");
}


//checking the validite of whole ip address
bool is_ip_valid(char *ip){

int i,j,dots=0, count=0;
int length;

//check the three dots
for(i=0; i<strlen(ip); i++){
if(ip[i]=='.'){
dots++;
}
}
if(dots!=3){
return false;
}
//tokenize the ip address to make it into array

// check if it contains three dots;
char *token=strtok(ip,".");
while(token){//if token is not pointing to the end of sentence
//check if the token is validate string
if(is_this_part_validate(token)==false){
return false;
}
token=strtok(NULL,"."); //this line replace . with the next string :) Note here
++count;
if(token==NULL){
return count==4;
}

}

}

int main(){

is_ip_valid("01.2.3.4.5")? printf("Validated\n"):printf("Not Validated\n");
is_ip_valid("1.1.1.2")? printf("Validated\n"):printf("Not Validated\n");
is_ip_valid("255.255.255.255")? printf("Validated\n"):printf("Not Validated\n");
is_ip_valid("255.255.255.256")? printf("Validated\n"):printf("Not Validated\n");
is_ip_valid("2567")? printf("Validated\n"):printf("Not Validated\n");
return 0;
}

