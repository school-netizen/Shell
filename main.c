#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
//int repl(char[]);
char isOLDpath='n';
char old_path[100]={0};
int repl();
int echo(char[]);
int main() {
  // Flush after every printf
  setbuf(stdout, NULL);

  repl();
  return 0;
}

int repl(){
  char input[100];
  while(1){
    printf("$ ");
    fgets(input,100,stdin);
    int cmd_len=strlen(input);
    input[cmd_len-1]='\0';

    char cmd_exit[]="exit 0";
    if(!strcmp(input,cmd_exit)){
      exit(0);
    }

    else if(echo(input)){
        for(int i=5;i<cmd_len-1;i++){
            printf("%c",input[i]);
        }
        printf("\n");
    }

    else if(!strncmp(input,"type ",5)){
        char typeOF[cmd_len-5];
        strcpy(typeOF,input+5);

        int isbuiltin=0;
        if(!strcmp(typeOF,"exit")||!strcmp(typeOF,"echo")||!strcmp(typeOF,"type")){
            printf("%s is a shell builtin",typeOF);
            isbuiltin=1;
        }
        if(!isbuiltin){
            char* path=getenv("PATH");
            char *path_copy=strdup(path);
            char* token=strtok(path_copy,":");
            int isExe=0;
            struct dirent *entry;

//            while(token){
//                DIR *dir=opendir(token);
//                while(entry=readdir(dir)){
//                    if(!strcmp(entry->d_name,typeOF)){
//                        printf("%s is %s/%s",typeOF,token,typeOF);
//                        isExe=1;
//                    }
//                    if(isExe){
//                        break;
//                    }
//                }
//                closedir(dir);
//
//                if(isExe){
//                    break;
//                }
//                token=strtok(NULL,":");
//            }
            while(token){
                DIR *dir=opendir(token);
                while(entry=readdir(dir)){
                    if(!strcmp(entry->d_name,typeOF)){
                        printf("%s is %s/%s",typeOF,token,typeOF);
                        isExe=1;
                    }
                    if(isExe)
                        break;
                }
                if(isExe)
                    break;
                token=strtok(NULL,":");
            }
            if(!isExe){
                printf("%s: not found",typeOF);
            }
        }
       printf("\n"); 
    }else if(!strcmp(input,"pwd")){
        printf("%s\n",getcwd(NULL,0));
    }else if(!strncmp(input,"cd ",3)){
        char dir[cmd_len-3];
        strcpy(dir,input+3);

        if(!strcmp(dir,"-")&&isOLDpath=='n'){
            printf("Old path not set\n");
        }
        else{
            char curr_dir[strlen(getcwd(NULL,0))];
            strcpy(curr_dir,getcwd(NULL,0));
            if(!strcmp(dir,"-")&&isOLDpath=='y'){
                chdir(old_path);
            }else if(!strcmp(dir,"~")){
                char *home=getenv("HOME");
                chdir(home);
                isOLDpath='y';
            }else if(!chdir(dir)){
                isOLDpath='y';
            }else{
                printf("cd to %s failed\n",dir);
            }

            if(isOLDpath=='y'){
                strcpy(old_path,curr_dir);
            }
        }
   }
   else{
    printf("%s: command not found\n",input);
   }
  }
  return 0;
}

int echo(char input[]){
  char cmd_echo[]="echo ";
  int iscmd_echo=1;
  for(int i=0;i<5;i++){
    if(input[i]!=cmd_echo[i]){
        iscmd_echo=0;
        break;
     }
  }
  return iscmd_echo;
}
