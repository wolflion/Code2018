// 代码在书上101/515
/* ls02.c
 * purpose list contents of directory of directories
 * action if no args,use . else list files in args
 * note uses stat and pwd.h and grp.h
 * BUG: try ls02 /tmp
 */
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

void do_ls(char []);
void dostat(char *);
void show_file_info(char *, struct stat *);
void mode_to_letters(int, char []);
char *uid_to_name(uid_t);
char *gid_to_name(gid_t);


int main(int argc, char const *argv[])
{
    if(argc == 1)
        do_ls(".");
    else
        while(--argc){
            printf("%s:\n",*++argv);
            do_ls(*argv);
        }
    return 0;
}

/*
 * list files in directory called dirname
 */
void do_ls(char dirname[])
{
    DIR *dir_ptr;   // the directory
    struct dirent *direntp;  // each entry

    if((dir_ptr = opendir(dirname)) == NULL)
        fprintf(stderr,"ls01: cannot open %s\n",dirname);
    else
    {
        while((direntp = readdir(dir_ptr)) != NULL)
            printf("%s\n",direntp->d_name);
        closedir(dir_ptr);
    }
}

void dostat(char *filename)
{
    struct stat info;
    if(stat(filename,&info) == -1)  // cannot stat
        perror(filename);    // say why
    else
        show_file_info(filename,&info);
}

/*
 * display the info about filename. The info is stored in struct at *info_p
 */
void show_file_info(char * filename,  struct stat *info_p)
{
    char *uid_to_name(),*ctime(),*gid_to_name(),*filemode();
    void mode_to_letters();
    char modestr[11];

    mode_to_letters(info_p->st_mode,modestr);

    printf("%s",modestr);
    printf("%4d",(int)info_p->st_nlink);
    printf("%-8s",uid_to_name(info_p->st_uid));
    printf("%-8s",gid_to_name(info_p->st_gid));
    printf("%8ld",(long)info_p->st_size);
    printf("%.12s",4+ctime(&info_p->st_mtime));
    printf("%s\n",filename);
}

void mode_to_letters(int mode, char str[])
{
    // 103/515
}