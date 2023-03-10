#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ASCII_SIZE	256
#define STR_SIZE	128

typedef enum {
	compress = 1,
	decompress,				// automatically 2
} Menu;

typedef struct buffer {		// byte-based
	char data;
	int idx;
} Buffer;


void count_ascii_freq(int* char_freq, char* filename);					// frequency of each ascii element
void buffer_set(Buffer* buf, int data, int idx);						// sets the buffer
void push_buffer (Buffer* buf, FILE* output, int data, int size);		// push bit-based (buffer is byte-based) buffer

/* compress */
void compress_file(char* filename);										// compress the file
void my_encode_head(FILE* output, int length, char* top);
void my_encode_body(FILE* input, FILE* output, int length, char* top);	// sub-function of compress_file()

/* decompress */
void decompress_file(char* filename);									// decompress the file
void my_decode_body(FILE* input, FILE* output) ;						// sub-function of decompress_file()
int get_character(Buffer* buf);

void print_menu() 
{
	printf("=== HUFFMAN COMPRESS PROGRAM === \n");
	printf("Which mode do you want?\n");
	printf("(1) compress,  (2) decompress\n");
	printf("> ");
}


int main () {
	int menu;
	char filename[STR_SIZE];

	print_menu();
	scanf("%d", &menu);

	switch (menu) {
		case compress:
			printf("compress!\n");
			printf("Enter the target file > ");
			scanf("%s", filename);
			compress_file(filename);

			break;
		case decompress:
			printf("decompress!\n");
			printf("Enter the target file > ");
			scanf("%s", filename);
			decompress_file(filename);

			break;
		default:
			printf("Wrong input...\n");
			printf("Bye!!\n");
			break;
	}

	printf("Done..!!\n");

	return 0;
}


void compress_file(char* filename) 
{
	FILE* input = NULL;
	FILE* output = NULL;
	int char_freq[ASCII_SIZE] = {0};
	char top_char[15] = {0};		// last 16 is EOF

	count_ascii_freq(char_freq, filename);
	/* get the top-15 */
	get_top_char(char_freq, top_char);
	/* top_char contains freq in freq-order */

	input = fopen(filename, "rb");
	output = fopen(strcat(filename, ".myzip"), "wb");

	if (input == NULL || output == NULL) {
		fprintf(stderr, "Failed to open file \n");
		return ;
	}

	my_encode_head(output, 15, top_char);			// save the top-15 frequent chars at the start of the output
	my_encode_body(input, output, 15, top_char);

	fclose(input);
	fclose(output);
}



/*
The basic structure is similar to compress_file()
*/
void decompress_file(char* filename)
{
    FILE *input = NULL;
    FILE *output = NULL;

    input = fopen(filename, "rb");
    output = fopen(strcat(filename, ".unzip"), "wb");

    if (input == NULL || output == NULL) {
		fprintf(stderr, "Failed to open file \n");
		return ;
	}

    my_decode_body(input, output);
    
    fclose(input);
    fclose(output);
}

void my_decode_body(FILE* input, FILE* output)
{
    Buffer input_buffer;	// read input from file stream (8 bit)
    Buffer my_buffer;		// writes 5 bit data to 8 bit

	buffer_set(&input_buffer, 0, 0);
	buffer_set(&my_buffer, 0, 0);
	int byte, ch;

	while (1)
	{
		if (input_buffer.idx == 0) {
			byte = fgetc(input);

			if (byte == EOF) break;
			buffer_set(&input_buffer, byte, 8);	// by 8 bit
		}

		/* get next bit */
		// the bit at the front (msb) will be assigned to bit (int)
		int bit = input_buffer.data >> 7;
		// get the bit and decrease the count
		buffer_set(&input_buffer, input_buffer.data << 1, input_buffer.idx - 1);

		/* push the bit into my_buffer */
		push_buffer(&my_buffer, output, bit, 1);

		if ((ch = get_character(&my_buffer)) != -1)	{	// it is a compressed bit
			fputc(ch, output);
			buffer_set(&my_buffer, 0, 0);
		}

	}
}

int get_character(Buffer* buf)
{
	if ((buf->data >> (buf->idx - 1)) == 0)	// check if the buffer's first bit is 0
		return -1;							// return -1 to indicate it is not compressed

    switch(buf->data)
	{
		case 0b10000:	// is the binary 10000 (comp val)? return 32 (orig val)
			return 32;
		case 0b10001:
			return 101;
		case 0b10010:
			return 116;
		case 0b10011:
			return 111;
		case 0b10100:
			return 97;
		case 0b10101:
			return 104;
		case 0b10110:
			return 110;
		case 0b10111:
			return 115;
		case 0b11000:
			return 105;
		case 0b11001:
			return 114;
		case 0b11010:
			return 100;
		case 0b11011:
			return 108;
		case 0b11100:
			return 117;
		case 0b11101:
			return 109;
		default:		// not a compressed data
			break;
	}

	return -1;			// error checking
}

void buffer_set(Buffer* buf, int data, int idx)
{
	buf->data = data;
	buf->idx = idx;
}

void push_buffer (Buffer* buf, FILE* output, int data, int size)
{
	for(int i = size - 1; i >= 0; i--) {
		buf->data = buf->data << 1;
		buf->data += ((data & (1 << i)) == 0) ? 0 : 1;
		buf->idx++;

		// windows may ignore this causing the program to produce an empty file
		// use >= instead of > to solve the problem, but causes an extra bit to be written
		// Solution : windows (and mac) need initialization of 0 using buffer_set()
		if (buf->idx == 8) {
			fputc(buf->data, output);
			buffer_set(buf, 0, 0);
		}
	}
}

void count_ascii_freq(int* char_freq, char* filename)
{
	FILE *fp = NULL;
	char *buffer = NULL;
	long lsize;
	size_t result;

	fp = fopen(filename, "rb");

	if (fp == NULL) {
		fprintf(stderr, "File open error\n");
		// TODO
		goto __error_file_read__;			// sends to __error_file_read__:, similar to switch-case's case :
	}

	fseek(fp, 0, SEEK_END);					// move pointer to the end
	lsize = ftell(fp);						// size of the file, using the distance of the pointer from the beginning
	rewind(fp);								// rewind the pointer to the beginning

	buffer = (char*) malloc(sizeof(char) * lsize);

	if (buffer == NULL) {
		fputs("File read error\n", stderr);
		// TODO
		goto __error_file_read__;
	}

	result = fread(buffer, 1, lsize, fp);	// space to save; increment by; till; using pointer

	if (result != lsize) {
		fputs("File read error\n", stderr);
		goto __error_file_read__;
	}

	for(int i = 0; i < lsize; i++) {
		char_freq[buffer[i]]++;
	}

__error_file_read__:
	if (fp != NULL) {
		fclose(fp);
	}

	if (buffer != NULL) {
		free(buffer);
	}
}

void my_encode_head(FILE *output, int length, char *top)
{

}

void my_encode_body(FILE* input, FILE* output, int length, char* top)
{
	Buffer my_buffer;
	int byte;
    buffer_set(&my_buffer, 0, 0);

	while (1) {
		byte = fgetc(input);
		if (byte == EOF) 
			break;

		switch (byte) {
		case 32:	// top[0] using for-loop
			push_buffer(&my_buffer, output, 0b10000, 5);	// 16
			break;
		case 101:
			push_buffer(&my_buffer, output, 0b10001, 5);	// 17, increment below
			break;
		case 116:
			push_buffer(&my_buffer, output, 0b10010, 5);
			break;
		case 111:
			push_buffer(&my_buffer, output, 0b10011, 5);
			break;
		case 97:
			push_buffer(&my_buffer, output, 0b10100, 5);
			break;
		case 104:
			push_buffer(&my_buffer, output, 0b10101, 5);
			break;
		case 110:
			push_buffer(&my_buffer, output, 0b10110, 5);
			break;
		case 115:
			push_buffer(&my_buffer, output, 0b10111, 5);
			break;
		case 105:
			push_buffer(&my_buffer, output, 0b11000, 5);
			break;
		case 114:
			push_buffer(&my_buffer, output, 0b11001, 5);
			break;
		case 100:
			push_buffer(&my_buffer, output, 0b11010, 5);
			break;
		case 108:
			push_buffer(&my_buffer, output, 0b11011, 5);
			break;
		case 117:
			push_buffer(&my_buffer, output, 0b11100, 5);
			break;
		case 109:
			push_buffer(&my_buffer, output, 0b11101, 5);
			break;
		case EOF:
			push_buffer(&my_buffer, output, EOF, 8);
			push_buffer(&my_buffer, output, EOF, 8);
			break;
		default: /* Head bit is '0'. */
			push_buffer(&my_buffer, output, byte, 8);
			break;
		}
	}

}