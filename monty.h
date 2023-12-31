#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
* struct cont_s - variables -args, file, line content
* @arg: value
* @file: pointer to monty file
* @temp_buff: line content
* @is_stack: flag change stack <-> queue
* Description: carries values through the program
*/
typedef struct cont_s
{
    char *arg;       /*Holds the argument passed to a function (e.g., push).*/
    FILE *file;       /* Pointer to the monty file being processed.*/
    char *temp_buff;  /* Holds the content of a line from the file.*/
    int is_stack;     /* Flag to change between stack and queue behavior.*/
} cont_t;

extern cont_t cont;

void i_push(stack_t **head, unsigned int line_num);
void p_pall(stack_t **head, unsigned int line_num);
void free_stack(stack_t *head);
void add_stack(stack_t **head, int n);
void add_queue(stack_t **head, int n);
int execute(char *temp_buff, stack_t **head, unsigned int line_num,
		FILE *file);
ssize_t getstdin(char **lineptr, int file);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void m_stack(stack_t **head, unsigned int line_num);
void m_queue(stack_t **head, unsigned int line_num);
void opc_instruct_exec(char *opcode, char *arg, stack_t **head, unsigned int
		line_num, FILE * file);
int execute(char *temp_buff, stack_t **head, unsigned int line_num, 
		FILE *file);
#endif
