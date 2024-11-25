
/*

Stack :

- L'expression RPN est lue de gauche à droite.
- Pour chaque élément :
    - Si c'est un nombre (un chiffre de 0 à 9), il est **empilé** dans la pile.
    - Si c'est un opérateur (+ - / *)
			1) les deux premiers éléments sont **dépilés**
			2) l'opération est effectuée
			3) le résultat est **réempilé** dans la pile

2. **À la fin du traitement** :
    - Il doit rester un seul élément dans la pile, qui sera le résultat de l'expression.
    - Si la pile contient plus ou moins d'éléments, cela signifie qu'il y a eu une erreur dans l'expression.
*/

#include <iostream>
#include "includes/RPN.hpp"

int	main(int argc, char* argv[])
{
	if (argc != 2) {
		std::cerr << "Error\nUsage: ./RPN \"Expression\"" << std::endl;
		return (EXIT_FAILURE);
	}
    else
    {
        try {
            RPN rpn(argv[1]);
        }
        catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
			return (EXIT_FAILURE);
        }
    }
	return 0;
}
