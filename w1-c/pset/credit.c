#include <cs50.h>
#include <stdio.h>

int calculate_checksum(long n);
int calculate_length(long n);
int calculate_starting_digits(long n);

int main(void)
{
    // Prompt user for credit card number
    long number = get_long("Number: ");

    // Calculate checksum
    int checksum = calculate_checksum(number);
    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
        return 1;
    }

    // Check for credit card length and starting digits
    int length = calculate_length(number);
    int starting_digits = calculate_starting_digits(number);

    // Print results
    if (length == 15 && (starting_digits == 34 || starting_digits == 37))
    {
        printf("AMEX\n");
    }
    else if (
        length == 16 &&
        (
            starting_digits == 51 ||
            starting_digits == 52 ||
            starting_digits == 53 ||
            starting_digits == 54 ||
            starting_digits == 55
        )
    )
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16))
    {
        int starting_digit = starting_digits / 10;
        if (starting_digit == 4)
        {
            printf("VISA\n");
            return 0;
        }

        printf("INVALID\n");
        return 1;
    }
    else
    {
        printf("INVALID\n");
        return 1;
    }

    return 0;
}

// Returns checksum value of credit card number using Luhn’s algorithm
int calculate_checksum(long n)
{
    int checksum = 0;
    int products_digits = 0;

    while (n > 0)
    {
        int last_digit = n % 10;
        checksum += last_digit;
        n /= 10;

        last_digit = n % 10;
        last_digit *= 2;
        products_digits = (products_digits * 10) + last_digit;
        n /= 10;
    }

    while (products_digits > 0)
    {
        int last_digit = products_digits % 10;
        checksum += last_digit;
        products_digits /= 10;
    }

    return checksum;
}

// Returns lengh of given credit card number
int calculate_length(long n)
{
    int length = 0;
    while (n > 0)
    {
        n /= 10;
        length++;
    }
    return length;
}

// Returns starting two digits of credit card number
int calculate_starting_digits(long n)
{
    // Reverse the credit card number
    long rev_n = 0;
    while (n > 0)
    {
        int last_digit = n % 10;
        rev_n = (rev_n * 10) + last_digit;
        n /= 10;
    }

    int starting_digits = 0;
    for (int i = 0; i < 2; i++)
    {
        int last_digit = rev_n % 10;
        starting_digits = (starting_digits * 10) + last_digit;
        rev_n /= 10;
    }

    return starting_digits;
}
