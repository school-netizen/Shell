//search recursively:

#include <stdio.h>
#include <string.h>
#include <dirent.h>
// #include <unistd.h>
// #include <stdlib.h>
void list_DIR_recursively(char *dirname){
    DIR *dir=opendir(dirname);
    if (!dir)
    {
        return;
    }
    
    struct dirent *entity;
    while (entity=readdir(dir))
    {
        printf("%s\n",entity->d_name);
        if (entity->d_type==DT_DIR && strcmp(entity->d_name,".") && strcmp(entity->d_name,".."))
        {
            char path[100]={0};
            strcat(path,dirname);
            strcat(path,"/");
            strcat(path,entity->d_name);
            list_DIR_recursively(path);
        }   
    }
    closedir(dir);
}

int main(){

    char path[100]="C:/Users/USER/Dev Pathak Btech CSE/C programming DevPathak B-Tech CSE";
    list_DIR_recursively(path);
    return 0;
}