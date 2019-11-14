#include "f.h"
#include <stdio.h>

void main(int argc, char const *argv[])
{
	FILE *f_img = fopen("1.png", "rb");
	print_png_wh(f_img);
	FILE *f_img2 = fopen("1.png", "rb");
	print_png_rgb(f_img2);
}
