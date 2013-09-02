#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>

void Copyfile(char *fp,char *tp)
{
    int sfd,tfd;
    int judge=1;
    struct stat f;
    char c;

    if((tfd=open(tp,O_RDONLY))!=-1)
    {
        printf("this file exits,intput 1 dor rewrite ,o for skip.\n");
        scanf("%d",&judge);
    }
    if(judge==1)
    {
        close(tfd);
        sfd=open(fp, O_RDONLY);
        tfd=open(tp, O_RDWR|O_CREAT);
        fstat(sfd,&f);
        while(read(sfd,&c,1)>0)
        {
            write(tfd,&c,1);
        }
        //change the priority

        chown(tp,f.st_uid,f.st_gid);
        chmod(tp,f.st_mode);
        close(sfd);
        close(tfd);
    }else
    {
        close(tfd);
    }
}

void Copydirection(char *fp,char *tp)
{
    int judge=1;
    DIR *dir_from,*dir_to;
    char fpath[100],tpath[100],path_f[100],path_t[100];
    struct stat stat_from,stat_to,fstat,tstat;
    struct dirent *fdirent,*tdirent;
    //open the from direction
    dir_from=opendir(fp);
    dir_to=opendir(tp);
    //judge the direction exits
    stat(fp,&stat_from);
    if(dir_to!=NULL)
    {
        printf("this direction exits,rewrite or skip(please input 1 for rewrite ,0 for skip:\n");
        scanf("%d",&judge);
    }
    if(judge==1)
    {
        if(dir_to==NULL)
        {
            //create by the priority of path_from
            mkdir(tp,stat_from.st_mode);
            chown(tp,stat_from.st_uid,stat_from.st_gid);
            dir_to=opendir(tp);
        }else
        {
            chmod(tp,stat_from.st_mode);
            chown(tp,stat_from.st_uid,stat_from.st_gid);
        }
        strcpy(path_f,fp);
        strcpy(path_t,tp);
        strcpy(fpath,fp);
        strcpy(tpath,tp);
        //time to begin to copy:
        while((fdirent=readdir(dir_from))!=NULL)
        {
            //jude is or not "." ".."
            if(strcmp(fdirent->d_name,".")!=0&&strcmp(fdirent->d_name,"..")!=0)
            {
                //copy the direction
                strcat(fpath,"/");
                strcat(fpath,fdirent->d_name);
                strcat(tpath,"/");
                strcat(tpath,fdirent->d_name);
                lstat(fpath,&stat_from);
                fstat.st_mode=stat_from.st_mode;
                //jude is a link
                if(S_ISLNK(fstat.st_mode))
                {
                    printf("%s is a link file.\n",fpath);
                }else 

                    if((S_IFMT&fstat.st_mode)==S_IFREG)
                    {
                        //judge is file or direction
                        //if is file , read and copy it
                        printf("copy the file %s.....\n",fpath);
                        Copyfile(fpath,tpath);
                        strcpy(fpath,path_f);
                        strcpy(tpath,path_t);
                    }else if((S_IFMT&fstat.st_mode)==S_IFDIR){
                        //is drection
                        printf("copy the direction %s.....\n",fpath);
                        Copydirection(fpath,tpath);
                        strcpy(fpath,path_f);
                        strcpy(tpath,path_t);
                    }
            }
        }
    }
}
//////////////////////////////////////////////////////////////
int main(int argc,char* argv[])
{
    DIR *dir_from,*dir_to;
    char path_from[100],path_to[100],path_f[100],path_t[100];
    char fpath[100],tpath[100];
    struct stat stat_from,stat_to,fstat,tstat;
    struct dirent *fdirent,*tdirent;

    if(argc != 3)
    {
        printf("input error!!\nusage is : cpdir source_dir destination_dir\n"); 
        exit(0);
    }

    // input the from direction
    // printf("please input the from direction:\n");
    //scanf("%s",path_from);
    //open the from direction

    //dir_from=opendir(path_from);
    dir_from = opendir(argv[1]);

    if(dir_from == NULL)
    {
        printf("error,the direction is not exist\n");
        return 0;
    }
    if(stat(argv[1],&stat_from)!=0){
        printf("error,wrong to get stat\n");
        return 0;
    }
    //succcess open the from direction

    //printf("please input the to direction:\n");
    //scanf("%s",path_to);
    //open the to direction
    //dir_to=opendir(path_to);
    dir_to = opendir(argv[2]);
    //judge the direction exits
    //not exit,create the direction
    if(dir_to == NULL)
    {
        //create by the priority of path_from
        mkdir(path_to,stat_from.st_mode);
        chown(path_to,stat_from.st_uid,stat_from.st_gid);
        dir_to=opendir(path_to);
    }else
    {
        chmod(path_to,stat_from.st_mode);
        chown(path_to,stat_from.st_uid,stat_from.st_gid);
    }
    strcpy(path_f,argv[1]);
    strcpy(path_t,argv[2]);
    strcpy(fpath,argv[1]);
    strcpy(tpath,argv[2]);
    //time to begin to copy:
    printf("begin to copy direction:\n");
    while((fdirent=readdir(dir_from))!=NULL)
    {
        //jude is or not "." ".."
        if(strcmp(fdirent->d_name,".") !=0 && strcmp(fdirent->d_name,"..") != 0)
        {
            //copy the direction
            strcat(fpath,"/");
            strcat(fpath,fdirent->d_name);
            strcat(tpath,"/");
            strcat(tpath,fdirent->d_name);
            lstat(fpath,&stat_from);
            fstat.st_mode=stat_from.st_mode;
            //jude is a link
            if(S_ISLNK(fstat.st_mode))
            {
                printf("%s is a link file.\n",fpath);
            }else if((S_IFMT&fstat.st_mode)==S_IFREG){//judge is file or direction
                //if is file , read and copy it
                printf("copy the file %s.....\n",fpath);
                Copyfile(fpath,tpath);
                strcpy(fpath,path_f);
                strcpy(tpath,path_t);
            }else if((S_IFMT&fstat.st_mode)==S_IFDIR){
                //is drection
                printf("copy the direction %s.....\n",fpath);
                Copydirection(fpath,tpath);
                strcpy(fpath,path_f);
                strcpy(tpath,path_t);
            }
        }
    }
    return 0;
}
