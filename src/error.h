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

#ifndef ERROR_H
#define ERROR_H

#define MAX_ERROR_SIZE_FOR_SCOPE 64 * sizeof(scoped_error_node_t)

enum error_kind
{
    ERRORK_NO_ERROR,
    ERRORK_UNEXPECTED_TOKEN,
};
typedef enum error_kind error_kind_t;

struct scoped_error_node
{
    error_kind_t error_kind;
    token_t* token;

    struct scoped_error_node* previous_error;
    struct scoped_error_node* next_error;
};
typedef struct scoped_error_node scoped_error_node_t;

struct scoped_error
{
    arena_t arena;
    byte* buffer[MAX_ERROR_SIZE_FOR_SCOPE];
    scoped_error_node_t* root;
};
typedef struct scoped_error scoped_error_t;

scoped_error_t ERROR_MakeScoped();
void ERROR_PushScope(scoped_error_t* error, error_kind_t kind, token_t* token);
void ERROR_ReportScope(scoped_error_t* error);
void ERROR_Report(scoped_error_node_t* error);

#endif // ERROR_H
