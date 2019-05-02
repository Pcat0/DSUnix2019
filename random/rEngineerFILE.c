#include <stdio.h>

#define true 1
#define false 0

int main(int argc, char *argv[]) {
	FILE *fp = fopen("testFile", "r");
//	fgetc(fp);
//	fp->_IO_read_ptr = fp->_IO_read_base;
	printf("%d\n", '\n');

	fseek(fp, 0, SEEK_END);
	printf("%d\n", fp->_IO_read_end - fp->_IO_read_ptr);
	printf("%d\n", *(fp->_IO_read_ptr-1));
	printf("%d\n", feof(fp));

	fgetc(fp);
	printf("%d\n", fp->_IO_read_end - fp->_IO_read_ptr);
	printf("%d\n", *fp->_IO_read_ptr);
	printf("%d\n", feof(fp));




	while(fp->_IO_read_ptr != fp->_IO_read_base) {
		printf("%c", *fp->_IO_read_ptr);
		fp->_IO_read_ptr -= 1;
	}

/*	printf("_IO_read_ptr: %c\n", *fp->_IO_read_ptr);
	printf("_IO_read_end: %c\n", *fp->_IO_read_end);
	printf("_IO_read_base: %c\n", *fp->_IO_read_base);
	printf("_IO_write_base: %c\n", *fp->_IO_write_base);
	printf("_IO_write_ptr: %c\n", *fp->_IO_write_ptr);
	printf("_IO_write_end: %c\n", *fp->_IO_write_end);
	printf("_IO_buf_base: %c\n", *(fp->_IO_buf_base+1));
	printf("_IO_buf_end: %c\n", *fp->_IO_buf_end);*/
/*	printf("_IO_save_base: %c", *fp->_IO_save_base);
	printf("_IO_backup_base: %c", *fp->_IO_backup_base);
	printf("_IO_save_end: %c", *fp->_IO_save_end);*/
	return 0;
}

