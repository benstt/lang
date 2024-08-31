// Copyright 2024 Benjamín García Roqués <benjamingarciaroques@gmail.com>

// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:

// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#include "base/types.h"
#include "base/libc.h"
#include "base/stringview.h"
#include "base/arena.h"

#include "lex.h"
#include "ast.h"
#include "parse.h"

#include "base/arena.c"
#include "lex.c"
#include "ast.c"
#include "parse.c"

#define STRING_LENGTH 7
const char * example_program = "- + * /";

int main(int argc, char** argv)
{
    stringview_t code;
    code.contents = example_program;
    code.len = STRING_LENGTH;

    lexer_t lexer = lexer_create(code);
    parser_t parser = parser_create(&lexer);
    parser_parse(&parser);

    return 0;
}
