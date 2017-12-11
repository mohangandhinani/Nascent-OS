#ifndef _TARFS_H
#define _TARFS_H

extern char _binary_tarfs_start;
extern char _binary_tarfs_end;

struct posix_header_ustar {
  char name[100];
  char mode[8];
  char uid[8];
  char gid[8];
  char size[12];
  char mtime[12];
  char checksum[8];
  char typeflag[1];
  char linkname[100];
  char magic[6];
  char version[2];
  char uname[32];
  char gname[32];
  char devmajor[8];
  char devminor[8];
  char prefix[155];
  char pad[12];
};

int
open_s(char *d_path,int flags);
int
read_s(int fd, char *buffer, int num_bytes);
int
close_s(int fd);
void
initialise_fds();
int
open_dir(char *d_path);
int
read_dir(int fd, char *buffer);
int
close_dir(int fd);
int convert_oct_int(char *oct_string);
struct posix_header_ustar* get_next_tar_header(struct posix_header_ustar* present_header);
int file_exists(char* f_name);
uint64_t print_elf_file(char* binary_name);
void tarfs_test();
int file_des_validator(int fd);
#endif
