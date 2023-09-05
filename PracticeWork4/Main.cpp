# include <iostream>
#include<ctime>
#include<cstdlib>

void fill_Array(short arr[], const short length);
void print_Array(short arr[], const short length);
void clear_arr(short arr[], const short length, short key);
int index_sum(short arrq[], short arr2[], const short length1, const short length2, short index);
template <typename T>
double mean_Arr(T arr[], const short length);
void prime_Range(int num1, int num2);
void prime_Range(int num1);
void permute_Arr(short arr[], const short length);
short compare_pare(short arr[], const short length, short num1, short num2);

int main() {
	setlocale(LC_ALL, "Russian");
	
	// Задача 1.
	std::cout << "\033[91mTask 1.\033[0m\n\n";
	const short size1 = 10;
	short array1[size1];
	short key;
	fill_Array(array1, size1);
	std::cout << "\nSource array is: ";
	print_Array(array1, size1);
	std::cout << "\nEnter the number to be reset in array = ";
	std::cin >> key;
	clear_arr(array1, size1, key);
	std::cout << "\n\n\033[92mFinal array is: \033[0m";
	print_Array(array1, size1);
	std::cout << "\n\n";

	// Задача 2.
	std::cout << "\033[91mTask 2.\033[0m\n\n";
	const short size2_1 = 5;
	const short size2_2 = 10;
	short array2_1[size2_1];
	short array2_2[size2_2];
	short index;	
	std::cout << "Filling array N 1\n\n";
	fill_Array(array2_1, size2_1);
	std::cout << "\nFilling array N 1\n\n";
	fill_Array(array2_2, size2_2);
	std::cout << "\nSource array N 1 is: ";
	print_Array(array2_1, size2_1);
	std::cout << "\nSource array N 2 is: ";
	print_Array(array2_2, size2_2);
	std::cout << "Enter the index = ";
	std::cin >> index;
	index_sum(array2_1, array2_2, size2_1, size2_2, index);
	
	// Задача 3.
	std::cout << "\033[91mTask 3.\033[0m\n\n";
	const short size3 = 10;
	short array3[size3];
	short number1, number2;
	fill_Array(array3, size3);
	std::cout << "\nSource array is: ";
	print_Array(array3, size3);		
	std::cout << "Enter two numbers -> ";
	std::cin >> number1 >> number2;
	std::cout << "\n\033[92mIndex is " << compare_pare(array3, size3, number1, number2) << "\033[0m\n\n";

	// Задача 4.
	std::cout << "\033[91mTask 4.\033[0m\n\n";
	int left, right;
	std::cout << "Set range:\nEnter the start of the range = ";
	std::cin >> left;
	std::cout << "Enter the end of the range = ";
	std::cin >> right;
	while (right < left) {
		std::cout << "Inpet error! The end of the range cannot be less than the start!\nEnter the start of the range = ";
		std::cin >> left;
		std::cout << "Enter the end of range = ";
		std::cin >> right;
	}
	if (left < 0 || right < 0)
		std::cout << "\n\033[92mInput error! A prime number cannot be negative\033[0m\n\n";
	prime_Range(left, right);
	prime_Range(right);

	// Задача 5.
	std::cout << "\033[91mTask 5.\033[0m\n\n";
	const short size5 = 5;
	short array5[size5];
	fill_Array(array5, size5);
	std::cout << "\nSource array is: ";
	print_Array(array5, size5);
	permute_Arr(array5, size5);
	std::cout << "\n\033[92mFinal array is: \033[0m";
	print_Array(array5, size5);
	std::cout << "\n\n";

	return 0;
}

void fill_Array(short arr[], const short length) {
	std::cout << "Choose how to populate the array:\npress '1' to manual input \033[4m\033[92mor\033[0m press any other key to random input\n Your choise -> ";
	char my_Choise;
	short start, end;
	std::cin >> my_Choise;
	if (my_Choise == '1')
		for (short i = 0; i < length; i++) {
			std::cout << "Enter array element N " << i + 1 << " -> ";
			std::cin >> arr[i];
		}
	else {
		std::cout << "Set the array filling range:\nEnter the start of the range = ";
		std::cin >> start;
		std::cout << "Enter the end of range = ";
		std::cin >> end;
		while (end < start) {
			std::cout << "Input error! The end of the range cannot be less than the start!\nEnter the start of the range = ";
			std::cin >> start;
			std::cout << "Enter the end of range = ";
			std::cin >> end;
		}
		srand(time(NULL));
		for (short i = 0; i < length; i++)
			arr[i] = rand() % (end - start) + start;
	}
}

void print_Array(short arr[], const short length) {
	for (short i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b \n\n";
}

void clear_arr(short arr[], const short length, short key) {
	for (short i = 0; i < length; i++)
		if (arr[i] == key)
			arr[i] = 0;
}

int index_sum(short arr1[], short arr2[], const short length1, const short length2, short index) {
	short min = length1 < length2 ? length1 : length2;
	if (index > min) {
		std::cout << "ERROR";
		return 0;
	}
	else
		return arr1[index] + arr2[index];
}

template<typename T> // TODO
double mean_Arr(T arr[], const short length) {
	short min, max;
	min = max = arr[0];
	for (short i = 0; i < length; i++) {
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];	
	}
	return (min + max) / double (2);
}

short compare_pare(short arr[], const short length, short num1, short num2) {
	for (short i = 0; i < length; i++)
		if (arr[i] == num1)
			if (arr[i + 1] == num2)
				return i;
	return -1;
}

void prime_Range(int num1, int num2) {	
	short counter = 0;
	std::cout << "\n\033[92mPrime numbers in the range: \033[0m";
	for (int i = num1; i <= num2; i++) {
		for (short j = 2; j < i; j++) {
			if (i % j == 0) 
				break;			
			counter++;
			std::cout << i << ", ";
			break;
		}		
	}		
	if (counter)
		std::cout << "\b\b \n\n";
	else
		std::cout << "There are no prime numbers in the range [" << num1 << "; " << num2 << "]\n\n";
}
void prime_Range(int num1) {
	std::cout<< "\n\033[92mPrime numbers in the range from '1' to " << num1 << ": \033[0m";
	for (short i = 2; i <= num1; i++)
		for (short j = 2; j < i; j++) {
			if (i % j == 0)
				break;
			std::cout << i << ", ";
			break;
		}
	std::cout << "\b\b \n\n";
}

void permute_Arr(short arr[], const short length) { // TODO
	for (short i = 0; i < length / 2; i++)
		std::swap(arr[i], arr[length / 2 + (length % 2 == 0 ? 0 : 1)]);
		/*if (length % 2 == 0)
			std::swap(arr[i], arr[length / 2 + i]);
		else
			std::swap(arr[i], arr[length / 2 + i + 1]);*/
}