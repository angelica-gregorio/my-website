#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*Gets an input from the user using the console.
    Arguments:
        arr_numbers(int) = this is where you store the numbers entered by the user    
        size (int) = tells you how many expected number of inputs would we need from the user
    Returns:
        there is no return
*/
void getNumbers(int *arr_numbers, int size)
{
    int i;
    printf("Enter number(s): ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", arr_numbers + i);
    }
}

/*Checks whether the given integer is of type perfect square or not
    Arguments:
        x = the input integer to be checked
    Returns:
        True if x is of type perfect square. Otherwise, returns False
    E.g.:
        x = 4, returns True
        x = 21, returns False
*/
bool isPerfectSquare(int x)
{
    if (x < 0)
        return false;

    int sqrt_x = sqrt(x);
    return (sqrt_x * sqrt_x == x);
}

/*Generates the appropriate tags for each element of the array numbers
    Arguments:
        numbers = the input array of integers to be processed by this function
        tags = result array of this function
        size = indicates the number of elements on both numbers and tags
    Returns:
        None
    Note:
        In this activity, the element will be tagged as true if it is a perfect square
        Otherwise, it will be tagged as false. 
        You need to use isPerfectSquare function.
    E.g.:
        numbers = [4,7,8,10,16, 51, 100]
        size = 7

        Thus, tags should be [true, false, false, false, true, false, true]
*/
void generateTags(int *numbers, bool *tags, int size)
{
    for (int i = 0; i < size; i++)
    {
        tags[i] = isPerfectSquare(numbers[i]);
    }
}

/*Calcuate the sum of the elements of the given array provided that it is tagged to be added
    Arguments:
        arr = the input array
        tags = contains the tags for each arr elements.
        size = the size of the given array
    Returns:
        The sum of the tagged elements from arr
    Note:
        it is assumed that the arr and tags are of the same size (defined by size)
    E.g.:
        arr = [7, 10, 13, 23]
        tags = [true, false, true, false]
        returns: 20
*/
int calculateSum(int *arr, bool *tags, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (tags[i])
        {
            sum += arr[i];
        }
    }
    return sum;
}

/*  Display the elements of the array as long as the element is tagged as true
    Arguments:
        arr = contains the entered numbers from the users
        tags = contains a tag whether the corresponding number should be displayed or not
        size = indicates the size of both arr and tags
        sum = indicates the resulting sum to displayed to the console
    Returns:
        There are no returns
    Note:
        Make sure to follow the format as mentioned on the instructions (README.md)
    E.g.:
        arr = [8, 10, 16, 23]
        tags = [true, false, true, false]
        sum = 24
        Print the ff to the console:

        The perfect squares are: 8 16 
        sum = 24
*/
void displayResult(int *arr, bool *tags, int size, int sum)
{
    printf("The perfect squares are: ");
    for (int i = 0; i < size; i++)
    {
        if (tags[i])
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\nsum = %d\n", sum);
}

int main(void)
{
    int *arr_number;
    bool *tags;
    int N = -1;
    int sum = 0;

    do
    {
        //Gets the number N
        printf("Enter N: ");
        scanf("%d", &N);
    } while (N <= 0);

    //Allocates memory on the said arrays given the value of N
    arr_number = (int *)malloc(N * sizeof(int));
    tags = (bool *)malloc(N * sizeof(bool));

    //Gets the numbers from the user
    getNumbers(arr_number, N);

    //Generates tags for the numbers
    generateTags(arr_number, tags, N);

    //Calculates the sum
    sum = calculateSum(arr_number, tags, N);

    //Display the results
    displayResult(arr_number, tags, N, sum);

    //Free up allocated memory
    free(arr_number);
    free(tags);
    return 0;
}
