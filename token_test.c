#include <stdio.h>
#include <stdlib.h>
#include "inc/ms_token.h"

/* Helper to convert enum kinds to printable strings */
static const char	*get_token_name(int kind)
{
	if (kind == 0)
		return ("PIPE");
	if (kind == 1)
		return ("IN");
	if (kind == 2)
		return ("OUT");
	if (kind == 3)
		return ("OUT_APPEND");
	if (kind == 4)
		return ("HERE_DOC");
	if (kind == 5)
		return ("WORD");
	return ("UNKNOWN");
}

/* Iterates through the list and prints the contents */
static void	print_token_list(t_token *list)
{
	t_token	*curr;
	int		i;

	curr = list;
	i = 0;
	printf("\n================= TOKENIZER DEBUG =================");
	if (!curr)
	{
		printf("\n(Empty list or Parsing Error)\n");
		printf("===================================================\n\n");
		return ;
	}
	while (curr)
	{
		printf("\nToken [%d]:\n", i);
		printf("  -> Kind:  %s\n", get_token_name(curr->kind));
		printf("  -> Value: [%s]\n", curr->value);
		curr = curr->next;
		i++;
	}
	printf("===================================================\n\n");
}

int	main(int argc, char **argv)
{
	t_token	*token_list;

	if (argc != 2)
	{
		printf("Usage: %s \"your test string string here\"\n", argv[0]);
		return (1);
	}
	token_list = ms_tokenize(argv[1]);
	print_token_list(token_list);
	free_token_list(token_list);
	return (0);
}
