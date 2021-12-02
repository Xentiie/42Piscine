#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int rules[];
	int game[][];
	int size;

	if (argc == 2)
	{
		size = parse_arg(argv[1], rules);
		init_game(game, 4);
	}
	else
		write();
		
}

void	init_board(int board[][], int size)
{
	int	x;
	int	y;

	game = malloc(size*size);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			board[x][y] = 0;
			x++;
		}
		y++;
	}
}

void	parse_arg(char *str, int rules[], int *size)			// Lit les regles envoyes en arg et calcule la taille
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
		{
			rules[i] = str[i] - '0';
		}
		else if (str[i] != ' ')
		{
			*size = -100;
		}
	}
}
