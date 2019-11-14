#include <stdio.h>
#include "f.h"
#include <png.h>

void print_png_wh(FILE *f_img)
{
    /// инициализация png, считывание структуры и информации файла
    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if(!png_ptr)
    {
        printf("Wrong with creating the read struct..\n");
    }
    png_infop info_ptr = png_create_info_struct(png_ptr);
    if(!info_ptr)
    {
        printf("Wrong with creating the info struct..\n");
    }
    png_set_palette_to_rgb(png_ptr);
	png_init_io(png_ptr, f_img);

    /// получения информации о файле
    png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
    int width = png_get_image_width(png_ptr, info_ptr);
    int height = png_get_image_height(png_ptr, info_ptr);
    printf("width = %d\n", width );
    printf("height = %d\n", height );
}

void print_png_rgb(FILE *f_img)
{
    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if(!png_ptr)
    {
        printf("Wrong with creating the read struct..\n");
    }
    png_infop info_ptr = png_create_info_struct(png_ptr);
    if(!info_ptr)
    {
        printf("Wrong with creating the info struct..\n");
    }
    png_set_palette_to_rgb(png_ptr);
	png_init_io(png_ptr, f_img);

    /// получения информации о файле
    png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
    int width = png_get_image_width(png_ptr, info_ptr);
    int height = png_get_image_height(png_ptr, info_ptr);
    png_bytepp rows = png_get_rows(png_ptr, info_ptr);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width * 3; j += 3)
        {
            printf("|R:%d G:%d B:%d| ", rows[i][j], rows[i][j + 1], rows[i][j + 2]);
        }
        printf("\n");
    }

    fclose(f_img);
}