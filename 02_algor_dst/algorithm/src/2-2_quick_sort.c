/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-2_quick_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:03:43 by jihhan            #+#    #+#             */

/*   Updated: 2021/02/02 05:49:19 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> // rand()
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int     argv_validate(char *ch);
void    quicksort(int v[], int n);
void    swap(int v[], int i, int j);

int     main(int argc, char *argv[])
{
    int     i;
    int     arr[argc - 1];

    i = 0;

    if (argc < 3)
    {
        printf("argc must more or equ to 3\n");
        return (EXIT_FAILURE);
    }

    while (++i < argc)
    {
        if (!argv_validate((argv[i])))
        {
            printf("argv error on %d: %s!\n", i, (argv[i]));
            return (EXIT_FAILURE);
        } else {
            arr[i-1] = atoi(argv[i]);
            printf("value %d: sets to int_arr[%d]\n", arr[i-1], i-1);
        }
    }

    i = 0;
    while (i < argc - 1)
    {
        printf("arr[%d]: %d\t", i, arr[i]);
        i++;
    }

    quicksort(arr, argc - 1);
    printf("\nsorted\n");
 
    i = 0;
    while (i < argc - 1)
    {
        printf("arr[%d]: %d\t", i, arr[i]);
        i++;
    }   

    return (EXIT_SUCCESS);
}

int     argv_validate(char *ch)
{
    int     v_digit;

    v_digit = isdigit((int)(*ch));
    printf("argv_validate::\tkey:%c\n", *ch);
    return (v_digit);
}


void    quicksort(int arr[], int len)
{
    int     last;
    int     i;
    int     pivot;
    int     rand_val;
    
    if (len < 2)                    // base condition
        return;
    printf("len: %d\n", len);
    rand_val = rand();
    pivot = (rand_val % len);
    last    = 0;
    swap(arr, 0, pivot);            // 1. make random index to set at 0 index.

    for (i = 1; i < len; i++)
        if (arr[i] < arr[0])        // 2. i < 0?
           swap(arr, ++last, i);    // 3. -> move i next to base(last)
    swap(arr, 0, last);             // 4. base to proper position.
    quicksort(arr, last);           // recursive sort 0 -> last small
    quicksort(arr + (last + 1), len - last - 1);
}

void    swap(int v[], int i, int j)
{
    int     temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
