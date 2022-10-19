#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int numerator;
	int denominator;
} rational;

rational create_rational(int a, int b);
void print_rational(rational number);
void input_rational(rational* number);
void print_result(char* operation, rational num1, rational num2, rational result);
double rational_to_double(rational number);
int compare_rationals(rational* num1, rational* num2);
int NWD(int a, int b);
rational add_rationals(rational* num1, rational* num2);
rational substract_rationals(rational* num1, rational* num2);
rational multiply_rationals(rational* num1, rational* num2);
rational divide_rationals(rational* num1, rational* num2);

int main(void)
{
	rational num1;
	rational num2 = create_rational(3, 64);
	input_rational(&num1);

	rational sum = add_rationals(&num1, &num2);
	rational difference = substract_rationals(&num1, &num2);
	rational product = multiply_rationals(&num1, &num2);
	rational quotient = divide_rationals(&num1, &num2);

	print_result("Sum", num1, num2, sum);
	if (difference.numerator == 0)
		printf("Difference of % d / % d and %d / % d is : %d\n", num1.numerator, num1.denominator, num2.numerator, num2.denominator, 0);
	else
		print_result("Difference", num1, num2, difference);
	print_result("Product", num1, num2, product);
	print_result("Quotient", num1, num2, quotient);
	printf("Double value of your rational number: %lf\n", rational_to_double(num1));

	if (compare_rationals(&num1, &num2) == 1)
		printf("Your rational number is bigger than %d/%d", num2.numerator, num2.denominator);
	else if (compare_rationals(&num1, &num2) == -1)
		printf("Your rational number is smaller than %d/%d", num2.numerator, num2.denominator);
	else
		printf("Your rational number is equal to %d/%d", num2.numerator, num2.denominator);

	return 0;
}

rational create_rational(int a, int b)
{
	rational number = { a, b };
	return number;
}

void print_rational(rational number)
{
	printf("Rational number: %d/%d", number.numerator, number.denominator);
}

void input_rational(rational* number)
{
	printf("Enter numerator and denominator: ");
	if (scanf("%d %d", &number->numerator, &number->denominator) != 2)
	{
		printf("Invalid input!");
		exit(EXIT_FAILURE);
	}
}

void print_result(char* operation, rational num1, rational num2, rational result)
{
	printf("%s of %d/%d and %d/%d is: %d/%d\n", operation, num1.numerator, num1.denominator, num2.numerator, num2.denominator, result.numerator, result.denominator);
}

double rational_to_double(rational number)
{
	double x = (double)number.numerator;
	double y = (double)number.denominator;
	double result = x / y;
	return result;
}

int compare_rationals(rational* num1, rational* num2)
{
	int a, b;
	a = num1->numerator * num2->denominator;
	b = num2->numerator * num1->denominator;
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
}

int NWD(int a, int b)
{
	return b==0 ? a : NWD(b,a%b);
}

rational add_rationals(rational* num1, rational* num2)
{
	rational sum;
	sum.denominator = num1->denominator * num2->denominator / NWD(num1->denominator, num2->denominator);
	sum.numerator = num1->numerator * num2->denominator / NWD(num1->denominator, num2->denominator) + num2->numerator * num1->denominator / NWD(num1->denominator, num2->denominator);
	return sum;
}

rational substract_rationals(rational* num1, rational* num2)
{
	rational difference;
	difference.denominator = num1->denominator * num2->denominator / NWD(num1->denominator, num2->denominator);
	difference.numerator = num1->numerator * num2->denominator / NWD(num1->denominator, num2->denominator) - num2->numerator * num1->denominator / NWD(num1->denominator, num2->denominator);
	return difference;
}

rational multiply_rationals(rational* num1, rational* num2)
{
	rational product;
	if (num2->numerator == 0 || num1->numerator == 0)
	{
		printf("Do NOT divide by zero!");
		exit(EXIT_FAILURE);
	}
	product.denominator = num1->denominator * num2->denominator / NWD(num1->denominator * num2->denominator, num1->numerator * num2->numerator);
	product.numerator = num1->numerator * num2->numerator / NWD(num1->denominator * num2->denominator, num1->numerator * num2->numerator);
	return product;
}

rational divide_rationals(rational* num1, rational* num2)
{
	rational quotient;
	if (num2->numerator == 0)
	{
		printf("Do NOT divide by zero!");
		exit(EXIT_FAILURE);
	}
	quotient.denominator = num1->denominator * num2->numerator / NWD(num1->denominator * num2->numerator, num1->numerator * num2->denominator);
	quotient.numerator = num1->numerator * num2->denominator / NWD(num1->denominator * num2->numerator, num1->numerator * num2->denominator);
	return quotient;
}
