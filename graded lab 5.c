#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <math.h>
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

typedef struct _pixel
{
	char sign;
	int color;
}pixel;

typedef struct _card
{
	int rows;
	int columns;
	pixel* arr;
}card;

typedef struct _christmas_card
{
	int width;
	int height;
	int num_of_gems;
	card picture;
}christmas_card;

int coordinates2index(int r, int c, int columns);
void set_pixel(pixel* s, char n_sign, int n_color);
void init_card(card* ca, int n_rows, int n_columns, pixel init_pixel);
void free_card(card* ca);
void print_card(card* ca);

void create_christmas_card(christmas_card* cc, int width, int height, int num_of_gems, pixel* colorful_pixels);
void print_christmas_card(christmas_card* cc);
void free_christmas_card(christmas_card* ct);
void paint_christmas_card(christmas_card* cc, pixel* colorful_pixels);


int main()
{
	printf(" ********************* Part 1 ********************* \n");
	
		pixel  colorful_pixels[4];
		printf("Converting indexes, setting and printing color pixels\n\n");
		printf("For 3x3 matrix, 2d index [1][1] after conversion gives 1d index [%d]\n\n", coordinates2index(1, 1, 3));
		set_pixel(&colorful_pixels[0], '*', 2); // green_star
		set_pixel(&colorful_pixels[1], '|', 15); // white_line
		set_pixel(&colorful_pixels[2], '@', 14); // yellow_ornament
		set_pixel(&colorful_pixels[3], ' ', 15); // white space

		HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hconsole, (WORD)colorful_pixels[0].color);
		printf("%c", colorful_pixels[0].sign);
		SetConsoleTextAttribute(hconsole, (WORD)colorful_pixels[1].color);
		printf("%c", colorful_pixels[1].sign);
		SetConsoleTextAttribute(hconsole, (WORD)colorful_pixels[2].color);
		printf("%c", colorful_pixels[2].sign);
		SetConsoleTextAttribute(hconsole, (WORD)colorful_pixels[3].color);
		printf("%c", colorful_pixels[3].sign);
		printf("\n\n");
	
	printf(" ********************* Part 2 ********************* \n");
	
		printf("Initializing and printing card\n\n");
		card card;
		init_card(&card, 15, 10, colorful_pixels[0]);
		print_card(&card);
		free_card(&card);
		printf("\n\n");
	
	printf(" ********************* Part 3 ********************* \n");
	
		christmas_card cc2, cc3;
		printf("Creating and printing tree\n\n");
		create_christmas_card(&cc3, 7, 3, 10, colorful_pixels);
		print_christmas_card(&cc3);
		printf("\n\n");
		create_christmas_card(&cc2, 5, 2, 5, colorful_pixels);
		print_christmas_card(&cc2);
		printf("\n\n");
	
	printf(" ********************* Part 4 ********************* \n");
	
		printf("Decorating and printing tree\n\n");
		paint_christmas_card(&cc3, colorful_pixels);
		print_christmas_card(&cc3);
		printf("\n\n");
		paint_christmas_card(&cc2, colorful_pixels);
		print_christmas_card(&cc2);
		printf("\n\n");
	

	// uncomment also as a part 3 and 4
	
		free_christmas_card(&cc3);
		free_christmas_card(&cc2);
		printf("\n\n");
	
	return 0;
}

int coordinates2index(int r, int c, int columns)
{
	return r * columns + c;
}

void set_pixel(pixel* s, char n_sign, int n_color)
{
	s->sign = n_sign;
	s->color = n_color;
}

void init_card(card* ca, int n_rows, int n_columns, pixel init_pixel)
{
	ca->arr = calloc((size_t)n_rows * n_columns, sizeof(pixel));
	if (ca->arr == NULL)
		exit(-1);
	ca->columns = n_columns;
	ca->rows = n_rows;
	for (int i = 0; i < n_rows * n_columns; i++) 
		ca->arr[i] = init_pixel;
}

void free_card(card* ca)
{
	free(ca->arr);
	ca->columns = 0;
	ca->rows = 0;
}


void print_card(card* ca)
{
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < ca->rows; i++)
	{
		for (int j = 0; j < ca->columns; j++)
		{
			SetConsoleTextAttribute(hconsole, (WORD)ca->arr[coordinates2index(i,j,ca->columns)].color);
			printf("%c", ca->arr[coordinates2index(i, j, ca->columns)].sign);
		}
		printf("\n");
	}

	SetConsoleTextAttribute(hconsole, 15);
}

void create_christmas_card(christmas_card* cc, int width, int height, int num_of_gems, pixel* colorful_pixels)
{
	cc->width = width;
	cc->height = height;
	cc->num_of_gems = num_of_gems;
	pixel init_pixel = {colorful_pixels[3].sign,colorful_pixels[3].color};
	init_card(&cc->picture, height * width, (2 * width) - 1 + (height - 1) * 4, init_pixel);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			for (int k = i * 2 + j; k <= (width) * 2 + (height - 1) * 4 - j - (i * 2) - 1; k += 2)
			{
				set_pixel(&cc->picture.arr[coordinates2index((height - i) * width - j-1, k, (2 * width) - 1 + (height - 1) * 4)], colorful_pixels[0].sign, colorful_pixels[0].color);
			}
		}
	}
}

void print_christmas_card(christmas_card* cc)
{
	print_card(&cc->picture);
}

void free_christmas_card(christmas_card* ct)
{
	free_card(&ct->picture);
	ct->height = 0;
	ct->width = 0;
	ct->num_of_gems = 0;
}

void paint_christmas_card(christmas_card* cc, pixel* colorful_pixels)
{
	srand((unsigned int)time(NULL));
	int i = 0,row,column;
	while (i < cc->num_of_gems)
	{
		row = rand() % cc->picture.rows;
		column = rand() % cc->picture.columns;
		if (cc->picture.arr[coordinates2index(row, column, cc->picture.columns)].sign == '*')
		{
			set_pixel(&cc->picture.arr[coordinates2index(row, column, cc->picture.columns)], colorful_pixels[2].sign, colorful_pixels[2].color);
			i++;
		}
	}
}