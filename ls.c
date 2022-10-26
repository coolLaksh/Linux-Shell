#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>

char special_char_1[] = ".";
char special_char_2[] = "..";


int main(){
    DIR *directory;
    struct dirent *entry;
    char s[100];
    getcwd(s,100);
    directory = opendir(s);
    if(directory){
        entry = readdir(directory);
        while(entry != NULL){
            if(!(strcmp(entry->d_name, special_char_1) == 0) && !(strcmp(entry->d_name,special_char_2) == 0)){
                printf("%s \n",entry->d_name);
            }
            entry  = readdir(directory);
        }
    }
    closedir(directory);
    return 0;
}
