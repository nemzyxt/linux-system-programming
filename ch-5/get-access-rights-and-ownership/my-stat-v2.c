#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    struct stat filestat;
    struct passwd *user_info;
    struct group *group_info;

    if(argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    if(stat(argv[1], &filestat) == -1) {
        fprintf(stderr, "Can't read file %s: %s\n", argv[1], strerror(errno));
        return errno;
    }

    if((user_info = getpwuid(filestat.st_uid)) == NULL) {
        perror("Can't open username");
        return errno;
    }

    if((group_info = getgrgid(filestat.st_gid)) == NULL) {
        perror("Can't get groupname");
        return errno;
    }

    printf("Inode : %lu\n", filestat.st_ino);
    printf("Size : %zd\n", filestat.st_size);
    printf("Links : %lu\n", filestat.st_nlink);
    //TODO: Fix bugs
    printf("Owner : %d (%s)\n", filestat.st_uid, user_info->pw_name);
    printf("Group : %d (%s)\n", filestat.st_gid, group_info->gw_name);
    printf("Filemode : %o\n", filestat.st_mode);

    return 0;
}
