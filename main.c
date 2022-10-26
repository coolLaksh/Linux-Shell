#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

char cd[] = "cd";
char pwd[] = "pwd";
char echo[] = "echo";
char special_char_for_echo[] = "#";
char special_char_for_echo1[] = "'";
char special_char_for_echo2[] = " ";
char ls[] = "ls";
char path_forls[] = "";

int command_checker(char *checker){
    if(strcmp(checker,cd) == 0){
        return 1;
    }else if(strcmp(checker,pwd) == 0){
        return 2;
    }else if(strcmp(checker,echo) == 0){
        return 3;
    }else if(strcmp(checker,ls) == 0){
        return 4;
    }
}

int get_index(char *checker, int start){
    int end;
    char temp[1];
    do{
        temp[0] = checker[start++];
    }while(!(strcmp(temp,special_char_for_echo1) == 0));
    return start;
}

void printIt(char *checker, int start, int end){
    for(int i = start;i<end-1;i++){
        printf("%c",checker[i]);
        
    }
}


int main(){

    char *token, input_string[100], output_string[100], *checker, *temp;
    int count, num, flag, start, end, space;
    while(1){
        count = 0, num= 0, flag = 0;
        gets(input_string);

        token = strtok(input_string," ");
        checker = token;
        token = strtok(NULL," ");
        num = command_checker(checker);
        if(num == 1){
            chdir(token);
            token = strtok(NULL," ");
        }else if(num == 2){
            printf("%s\n",getcwd(output_string,100));
        }else if(num == 3){
            while(token != NULL){
                if(!(strcmp(special_char_for_echo,token) == 0)){
                printf("%s ",token);
                token = strtok(NULL, " ");
                }else{
                    token = strtok(NULL," ");
                    temp = token;
                    start = get_index(temp,0);
                    end = get_index(temp,start+1);
                    printIt(temp, start, end);
                    break;
                }
            }
            printf("\n");
        }else if(num == 4){
            pid_t t;
            //t = fork();
            if(t == 0){
                //execl("./ls.exe","Fun","Assignment2","Desktop","OneDrive","Lenovo","Users","C:",NULL);
            }else if(t > 0){
                //wait();
            }    
        }
    }


    return 0;

    return 0;
}