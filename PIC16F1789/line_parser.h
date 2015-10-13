#ifndef _LINE_PARSER
    #define _LINE_PARSER

    #include <stdint.h>

    uint8_t line_parser(char *line, char delim);
    uint8_t get_field(char *field, uint8_t N);
    uint8_t is_line_field_num(uint8_t N);

#endif
