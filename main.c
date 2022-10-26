#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


char cd[] = "cd";
char cwd[] = "pwd";
char echo[] = "echo";
char special_char_for_echo[] = "-e";
char special_char_for_echo1[] = "\n";
char special_char_for_echo2[] = "\t";
char ls[] = "ls";
char path_forls[] = "";
char Exit[] = "exit";
char Thread_Command[] = "&t";

//Path for ls
char *arg0 = "ls";
char *arg1 = "/Assignment";
char *arg2 = "/lakshyalodu";
char *arg3 = "/home";

int command_checker(char *checker){
    if(strcmp(checker,cd) == 0){
        return 1;
    }else if(strcmp(checker,cwd) == 0){
        return 2;
    }else if(strcmp(checker,echo) == 0){
        return 3;
    }else if(strcmp(checker,ls) == 0){
        return 4;
    }else if(strcmp(checker,Thread_Command) == 0){
    	return 9;
    }
    else if(strcmp(checker, Exit) == 0){
    	return 17;
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

void helper_for_echo(char *String){
    int flag1 = 0;
    int count = 0;
    for(int i = 0;String[i] != '\0';i++){
        if(String[i] == '/'){
            flag1 = 1;
            count = i;
        }else if(flag1 == 1 && count+1 == i){
            if(String[i] == 'n'){
                printf("\n");
            }else if(String[i] == 't'){
                printf("\t");
            }else{
                flag1 = 0;
            }
        }else{
            flag1 = 0;
            printf("%c",String[i]);
        }
    }
}

int main(){

    char *token, input_string[100], output_string[100], *checker, *temp,Helper_For_cd[100];
    int count, num, flag, start, end, space;
    while(1){
        count = 0, num= 0, flag = 0;
        gets(input_string);

        token = strtok(input_string," ");
        checker = token;
        token = strtok(NULL," ");
        num = command_checker(checker);
        if(num == 1){
            getcwd(Helper_For_cd, 100);
        	
            chdir(token);
            token = strtok(NULL," ");
            getcwd(output_string,100);
            
            if((strcmp(output_string,Helper_For_cd) == 0)){
            	printf("\nInvalid Path...\n\n");
            }
        }else if(num == 2){
            printf("%s\n",getcwd(output_string,100));
        }else if(num == 3){
            
                if((strcmp(special_char_for_echo,token) == 0)){
                    token = strtok(NULL, " ");
                    while(token != NULL){
                        helper_for_echo(token);
                        token = strtok(NULL, " ");
                    }
                }else{
                    while(token != NULL){
                        printf("%s ",token);
                        token = strtok(NULL," ");}
                }
            
            printf("\n");
        }else if(num == 4){
            int a = 0;	
            pid_t t;
            t = fork();
            if(t == 0){
                execl("/home/lakshyalodu/Downloads/Assignment2/ls",arg0,arg1,arg2,arg3,(char *) NULL);
            }else if(t > 0){
                wait();
           
            }    
        }else if(num == 9){
        	printf("Hello i am going to implement all commands by using threads.");
        }else if(num == 17){
        	break;
        }
    }


    return 0;
}