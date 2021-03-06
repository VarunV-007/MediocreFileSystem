#include "common.h"
#include "inode_handler.h"

int fill_dir_ent(struct dir_block_t *dir_block, char *entry, enum type_t type) {
	int i;
	for (i = 0; i < MAX_DIRENT_NB; ++i) {
		// empty entry => free
		if (!(strlen(dir_block->dir_ent[i].name))) {
			break;
		}
	}
	if (i >= MAX_DIRENT_NB) {
		printf("not enough directory entries available\n");
		return 1;
	}
	strcpy(dir_block->dir_ent[i].name, entry);
	dir_block->dir_ent[i].type = type;
	
	if (type == REG_FILE) {
		dir_block->dir_ent[i].inode_id = get_inode();
		printf("inode id: %d\n", dir_block->dir_ent[i].inode_id);
		set_nlink(dir_block->dir_ent[i].inode_id, 1);	
	}
	
	return 0;
}
