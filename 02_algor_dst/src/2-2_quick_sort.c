/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-2_quick_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:03:43 by jihhan            #+#    #+#             */
/*   Updated: 2021/01/29 15:44:35 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int     argv_validate(char *ch)
{
    int     len;
    int     v_digit;

    len     = (int)(strlen((const char *)ch));
    v_digit = isdigit((int)(*ch));

    printf("argv_validate::\tkey:%c\n", *ch);

    return (len && v_digit);
}

int main(int argc, char *argv[])
{
    int     i;

    i = 0;

    if (argc < 3)
    {
        printf("argc must more or equ to 3\n");
        return (EXIT_FAILURE);
    }

    while (++i < argc)
        if (!argv_validate((argv[i])))
        {
            printf("argv error on %d: %s!\n", i, (argv[i]));
            return (EXIT_FAILURE);
        }

    return (EXIT_SUCCESS);
}

