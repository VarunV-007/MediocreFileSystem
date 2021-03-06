#ifndef DISK_H
#define DISK_H

#define MAX_BLOCKS 100
#define BLOCK_SZ 4096

int d_init_init();
int init_disk();
int init_disk_first_time();
int write_block(const void*);
int write_block_at(int, const void*);
int read_block(int, void*);
void free_disk();
int erase_block(int);

#endif
