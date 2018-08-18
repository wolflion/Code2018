/*
 * 代码在94/515
 * fileinfo.c -- use stat() to obtain and print file properties
 *            - some members are just numbers...
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    struct stat info;      // buffer for file info
    if(argc > 1)
        if(stat(argv[1],&info) != -1){
            show_stat_info(argv[1],&info);
            return 0;
        }
        else
            perror(argv[1]);   // report stat() errors    
    return 1;
}

/*
 *  displays some info from stat in a name=value format
 */
show_stat_info(char *fname, struct stat *buf)
{
    printf("  mode: %o\n",buf->st_mode);  // type+mode
    printf("  links: %d\n",buf->st_nlink);  // #links
    printf("  user: %d\n",buf->st_uid);  // user id
    printf("  group: %d\n",buf->st_gid);  // group id
    printf("  size: %d\n",buf->st_size);  // file size
    printf("  modtime: %d\n",buf->st_mtime);  // modified
    printf("  name: %s\n",fname);  // filename
}
