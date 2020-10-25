// Created by mrsb75 on 12/10/2020.
#include "segmentation.h"

static int get_space_before_char(struct LineAnalysis *line, size_t char_number)
{
    if (char_number == 0)
        return 0;
    return line->chars[char_number].col_start - line->chars[char_number - 1].col_end;
}

bool has_space_before_char(struct LineAnalysis *line, size_t char_number)
{
    if (char_number == 0)
        return false;

    double sum = 0.;
    for (size_t i = 0; i < line->nb_chars; i++)
        sum += get_space_before_char(line, i);
    double average = sum / line->nb_chars;

    int space = get_space_before_char(line, char_number);
    return (space > 1.5 * average);
}

static int get_space_before_line(struct PageAnalysis *page, size_t line_id)
{
    if (line_id == 0)
        return 0;
    return page->lines[line_id].line_start - page->lines[line_id - 1].line_end;
}

bool has_newline_before_line(struct PageAnalysis *page, size_t line_id)
{
    if (line_id == 0)
        return false;

    double sum = 0.;
    for (size_t i = 0; i < page->nb_lines; i++)
        sum += get_space_before_line(page, i);
    double average = sum / page->nb_lines;

    int space = get_space_before_line(page, line_id);
    return (space > 1.5 * average);
}

