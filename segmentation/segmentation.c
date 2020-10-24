// Created by mrsb75 on 29/09/2020.
#include "cstnts.h"
#include "image.h"
#include "SDL.h"
#include "segmentation.h"

static void draw_segmentation_on_image(SDL_Surface *image, struct PageAnalysis *page_analysis)
{
    const Uint32 blue_pixel = SDL_MapRGB(image->format, 0, 0, 255);

    for (size_t line_id = 0; line_id < page_analysis->nb_lines; line_id++)
    {
        struct LineAnalysis *line = &page_analysis->lines[line_id];

        draw_line(image, blue_pixel,
            line->line_start - 1, 0, image->w);
        draw_line(image, blue_pixel,
            line->line_end + 1, 0, image->w);

        for (size_t char_id = 0; char_id < line->nb_chars; char_id++)
        {
            struct CharAnalysis *c = &line->chars[char_id];
            draw_column(image, blue_pixel,
                c->col_start - 1, line->line_start, line->line_end);
            draw_column(image, blue_pixel,
                c->col_end + 1, line->line_start, line->line_end);
        }
    }
}

struct PageAnalysis *segmentation(const char *input)
{
    struct PageAnalysis *page_analysis = malloc(sizeof(struct PageAnalysis));

    SDL_Surface *image = image_load(input);
    detect_lines(image, page_analysis);

    draw_segmentation_on_image(image, page_analysis);
    SDL_SaveBMP(image, g_path_img_segmentation);
    SDL_FreeSurface(image);

    return page_analysis;
}

