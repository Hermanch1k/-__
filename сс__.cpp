#include <iostream>
using namespace std;

/*int main() {
    int n, m, startValue;

    cout << "Enter the number of rows in the array: ";
    cin >> n;
    cout << "Enter the number of array columns: ";
    cin >> m;
    cout << "Enter seed number: ";
    cin >> startValue;

    vector < vector <int>> array(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        int value = startValue; 
        for (int j = 0; j < m; ++j) {
            array[i][j] = value; 
            value *= 2;   
        }
    }

    cout << "Created array:\n";
    for (const auto& row : array) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << std::endl;
    }

    return 0;
}
________________________________________________________________________________________________________________________________________

int main() {
    int n, m, startValue;
    cout << "Enter the number of rows in the array: ";
    cin >> n;
    cout << "Enter the number of array columns: ";
    cin >> m;
    cout << "Enter seed number: ";
    cin >> startValue;

    vector < vector<int>> array(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        int value = startValue; 
        for (int j = 0; j < m; ++j) {
            array[i][j] = value; 
            value += 1;       
        }
    }

    cout << "Created array:\n";
    for (const auto& row : array) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}
_____________________________________________________________________________________________________________________________


void printArray (const vector < vector <int>> & array) {
    for (const auto& row : array) {
        for (int element : row) {
            cout << element << "\t";
        }
        cout << std::endl;
    }
}

void shiftLeft(vector < vector<int>>& array, int shifts)
{
    int rows = array.size();
    int cols = array[0].size();
    shifts %= cols;  
    for (int i = 0; i < rows; ++i) {
        rotate(array[i].begin(), array[i].begin() + shifts, array[i].end());
    }
}

void shiftRight(vector < vector<int>>& array, int shifts) {
    int rows = array.size();
    int cols = array[0].size();
    shifts %= cols;
    for (int i = 0; i < rows; ++i) {
        rotate(array[i].rbegin(), array[i].rbegin() + shifts, array[i].rend());
    }
}

void shiftUp(vector < vector<int>>& array, int shifts) {
    int rows = array.size();
    shifts %= rows;
    rotate(array.begin(), array.begin() + shifts, array.end());
}

void shiftDown(vector < vector<int>>& array, int shifts) {
    int rows = array.size();
    shifts %= rows;
    std::rotate(array.rbegin(), array.rbegin() + shifts, array.rend());
}

int main() {
    int n, m, shifts;
    char direction;

    cout << "Enter the number of rows in the array: ";
    cin >> n;
    cout << "Enter the number of array columns: ";
    cin >> m;

    vector < vector<int>> array(n, vector<int>(m));
    srand(time(0));  
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            array[i][j] = rand() % 100; 
        }
    }

    cout << "Source array:\n";
    printArray(array);

    cout << "Enter the number of shifts: ";
    cin >> shifts;
    cout << "Enter direction (l - left, r - right, u - up, d - down): ";
    cin >> direction;

    switch (direction) {
    case 'l':
        shiftLeft(array, shifts);
        break;
    case 'r':
        shiftRight(array, shifts);
        break;
    case 'u':
        shiftUp(array, shifts);
        break;
    case 'd':
        shiftDown(array, shifts);
        break;
    default:
        cout << "Wrong direction!\n";
        return 1;
    }

    cout << "Array after shift:\n";
    printArray (array);

    return 0;
}*/

/*=============================================================-Дз2-======================================================================*/

/*
double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < abs(exponent); ++i) {
        result *= base;
    }
    if (exponent < 0) {
        return 1.0 / result;
    }
    return result;
}

int main() {
    double base;
    int exponent;

    cout << "Enter degree base: ";
    cin >> base;
    cout << "Enter exponent : ";
    cin >> exponent;

    double result = power(base, exponent);
    cout << " Result: " << result << endl;

    return 0;
}
_______________________________________________________________________________________________________________
int sumInRange(int a, int b) {
    int sum = 0;
    if (a > b) {
        swap(a, b);  
    }
    for (int i = a; i <= b; ++i) {
        sum += i;
    }
    return sum;
}

int main() {
    int num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    int result = sumInRange(num1, num2);
    cout << "Sum of numbers in range: " << result << endl;

    return 0;
}
________________________________________________________________________________________________________________________________________

bool isPerfect(int number) {
    int sum = 0;
    for (int i = 1; i <= number / 2; ++i) {
        if (number % i == 0) {
            sum += i;
        }
    }
    return sum == number;
}

vector<int> findPerfectNumbers(int start, int end) {
    vector<int> perfectNumbers;
    for (int i = start; i <= end; ++i) {
        if (isPerfect(i)) {
            perfectNumbers.push_back(i);
        }
    }
    return perfectNumbers;
}

int main() {
    int start, end;
    cout << "Enter the start of the interval: ";
    cin >> start;
    cout << "Enter the end of the interval: ";
    cin >> end;

    vector<int> perfectNumbers = findPerfectNumbers(start, end);
    if (!perfectNumbers.empty()) {
        cout << "Perfect numbers in the interval [" << start << ", " << end << "]: ";
        for (int num : perfectNumbers) {
            cout << num << " ";
        }
        cout << std::endl;
    }
    else {
        cout << "In the interval [" << start << ", " << end << "] there are no perfect numbers." << endl;
    }

    return 0;
}
______________________________________________________________________________________________________________________________________

enum Suit {
    Hearts,  
    Diamonds, 
    Clubs,    
    Spades    
};

enum Rank {
    Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
    Jack, Queen, King, Ace
};

struct Card {
    Rank rank;
    Suit suit;
};

std::string rankToString(Rank rank) {
    switch (rank) {
    case Two: return "2";
    case Three: return "3";
    case Four: return "4";
    case Five: return "5";
    case Six: return "6";
    case Seven: return "7";
    case Eight: return "8";
    case Nine: return "9";
    case Ten: return "10";
    case Jack: return "jack";
    case Queen: return "Queen";
    case King: return "king";
    case Ace: return "ace";
    default: return "";
    }
}

std::string suitToString(Suit suit) {
    switch (suit) {
    case Hearts: return "Hearts";
    case Diamonds: return "Diamonds";
    case Clubs: return "Clubs";
    case Spades: return "Spades";
    default: return "";
    }
}

void printCard(const Card& card) {
    cout << rankToString(card.rank) << " " << suitToString(card.suit) << endl;
}

int main() {
    Card card1 = { Ace, Spades };      
    Card card2 = { Queen, Hearts };   
    Card card3 = { Ten, Diamonds };   
    cout << "Cards:\n";
    printCard(card1);
    printCard(card2);
    printCard(card3);

    return 0;
}
________________________________________________________________________________________________________________

bool isLucky(int number) {
    if (number < 100000 || number > 999999) {
        cout << "Please enter a six-digit number." << endl;
        return false;
    }

    int firstHalfSum = 0;
    int secondHalfSum = 0;

    firstHalfSum += number / 100000;        
    firstHalfSum += (number / 10000) % 10;   
    firstHalfSum += (number / 1000) % 10;    

    secondHalfSum += (number / 100) % 10;    
    secondHalfSum += (number / 10) % 10;     
    secondHalfSum += number % 10;            

    return firstHalfSum == secondHalfSum;
}

int main() {
    int number;

    cout << "Enter a six-digit number: ";
    cin >> number;

    if (isLucky(number)) {
        cout << "The number " << number << " is lucky!" << endl;
    }
    else {
        cout << "The number " << number << " is not lucky." << endl;
    }

    return 0;
}
_____________________________________________________________________________________________________________________

int linearSearch(const int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {  
            return i;        
        }
    }
    return -1;  
}

int main() {
    int arr[] = { 10, 20, 30, 40, 50, 60 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the key to search for: ";
    cin >> key;

    int result = linearSearch(arr, size, key);

    if (result != -1) {
        std::cout << "Key found at index " << result << "." << endl;
    }
    else {
        cout << "Key not found in the array." << endl;
    }

    return 0;
}
_______________________________________________________________________________________________________________________________

int binarySearch(const int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  

        if (arr[mid] == key) {
            return mid; 
        }

        if (arr[mid] < key) {
            left = mid + 1;
        }

        else {
            right = mid - 1;
        }
    }
    return -1; 
}

int main() {
    int arr[] = { 10, 20, 30, 40, 50, 60 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter the key to search for: ";
    cin >> key;

    int result = binarySearch(arr, size, key);

    if (result != -1) {
        cout << "Key found at index " << result << "." << endl;
    }
    else {
        cout << "Key not found in the array." << endl;
    }

    return 0;
}
_______________________________________________________________________________________________________________________

int binaryToDecimal(const string& binaryStr) {
    int decimalValue = 0;
    int length = binaryStr.size();

    for (int i = 0; i < length; ++i) 
    {
        if (binaryStr[length - i - 1] == '1') 
        {  
            decimalValue += pow(2, i);     
        }
    }

    return decimalValue;
}

int main() {
    string binaryStr;

    cout << "Enter a binary number: ";
    cin >> binaryStr;

    int decimalValue = binaryToDecimal(binaryStr);
    cout << "Decimal value: " << decimalValue << endl;

    return 0;
}
*/
/*==========================================================================-Дз3-==========================================================================*/
/*
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    switch (month) {
    case 4: case 6: case 9: case 11: return 30;
    case 2: return isLeapYear(year) ? 29 : 28;
    default: return 31;
    }
}

int daysFromStart(int day, int month, int year) {
    int totalDays = 0;

    for (int i = 0; i < year; ++i) {
        totalDays += isLeapYear(i) ? 366 : 365;
    }

    for (int i = 1; i < month; ++i) {
        totalDays += daysInMonth(i, year);
    }

    totalDays += day;

    return totalDays;
}

int dateDifference(int day1, int month1, int year1, int day2, int month2, int year2) 
{
    int days1 = daysFromStart(day1, month1, year1);
    int days2 = daysFromStart(day2, month2, year2);

    return abs(days1 - days2);
}

int main() {
    int day1, month1, year1;
    int day2, month2, year2;
    cout << "Enter the first date (day month year): ";
    cin >> day1 >> month1 >> year1;
    cout << "Enter the second date (day month year): ";
    cin >> day2 >> month2 >> year2;

    int difference = dateDifference(day1, month1, year1, day2, month2, year2);
    cout << "Difference in days: " << difference << endl;

    return 0;
}
_________________________________________________________________________________________________________________________________________________

double calculateAverage(const int arr[], int size) {
    if (size == 0) return 0; 

    int sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    return static_cast<double>(sum) / size;
}

int main() {
    int arr[] = { 10, 20, 30, 40, 50 };  
    int size = sizeof(arr) / sizeof(arr[0]);  

    double average = calculateAverage(arr, size);
    cout << "The average is: " << average << endl;

    return 0;
}
_____________________________________________________________________________________________________________________________________________

void countElements(const int arr[], int size, int& positiveCount, int& negativeCount, int& zeroCount) 
{
    positiveCount = 0;
    negativeCount = 0;
    zeroCount = 0;

    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] > 0) 
        {
            ++positiveCount;
        }
        else if (arr[i] < 0) 
        {
            ++negativeCount;
        }
        else 
        {
            ++zeroCount;
        }
    }
}

int main() {
    int arr[] = { 3, -1, 0, 4, -5, 0, 2, -2 };  
    int size = sizeof(arr) / sizeof(arr[0]); 

    int positiveCount, negativeCount, zeroCount;

    countElements(arr, size, positiveCount, negativeCount, zeroCount);

    cout << "Positive elements: " << positiveCount << endl;
    cout << "Negative elements: " << negativeCount << endl;
    cout << "Zero elements: " << zeroCount << endl;

    return 0;
}
______________________________________________________________________________________________________________________________________________________

int gcd(int a, int b) 
{
    if (b == 0) 
    {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int num1, num2;

    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    int result = gcd(num1, num2);
    cout << "The GCD of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}
*/
/*==========================================================================-Дз4-=================================================================================*/
/*
bool isLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) 
{
    switch (month) 
    {
    case 4: case 6: case 9: case 11: return 30;
    case 2: return isLeapYear(year) ? 29 : 28;
    default: return 31;
    }
}

int daysFromEpoch(int day, int month, int year) 
{
    int days = 0;
    for (int y = 1970; y < year; ++y) 
    {
        days += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < month; ++m) 
    {
        days += daysInMonth(m, year);
    }
    days += day - 1;
    return days;
}

int dateDifference(int day1, int month1, int year1, int day2, int month2, int year2) 
{
    int days1 = daysFromEpoch(day1, month1, year1);
    int days2 = daysFromEpoch(day2, month2, year2);
    return abs(days1 - days2);
}

int main() 
{
    int day1, month1, year1;
    int day2, month2, year2;

    cout << "Enter the first date (day month year): ";
    cin >> day1 >> month1 >> year1;

    cout << "Enter the second date (day month year): ";
    cin >> day2 >> month2 >> year2;

    int difference = dateDifference(day1, month1, year1, day2, month2, year2);

    cout << "Difference in days: " << difference << endl;

    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------------------

double calculateAverage(const int* arr, int size) 
{
    if (size == 0) 
    {
        cerr << "Array size must be greater than 0." << endl;
        return 0.0;
    }

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    return static_cast<double>(sum) / size;
}

int main() 
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    double average = calculateAverage(arr, size);
    cout << "The average of the array elements is: " << average << endl;

    delete[] arr;
    return 0;
}
-------------------------------------------------------------------------------------------------------------------------
struct CountResult {
    int positiveCount;
    int negativeCount;
    int zeroCount;
};

    CountResult countElements(const int* arr, int size) {
    CountResult result = { 0, 0, 0 }; 

    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            result.positiveCount++;
        }
        else if (arr[i] < 0) {
            result.negativeCount++;
        }
        else {
            result.zeroCount++;
        }
    }

    return result;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    CountResult result = countElements(arr, size);

    cout << "Number of positive elements: " << result.positiveCount << endl;
    cout << "Number of negative elements: " << result.negativeCount << endl;
    cout << "Number of zero elements: " << result.zeroCount << endl;

    delete[] arr;
    return 0;
}
------------------------------------------------------------------------------------------------------------------------------------------------

template <typename T>
void initializeMatrix(vector<std::vector<T>>&matrix, int size) {
    cout << "Enter elements for a " << size << "x" << size << " matrix:\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> matrix[i][j];
        }
    }
}

template <typename T>
void printMatrix(const std::vector<std::vector<T>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << std::endl;
    }
}

template <typename T>
void findMinMaxDiagonal(const std::vector<std::vector<T>>& matrix, T& min, T& max) {
    min = matrix[0][0];
    max = matrix[0][0];
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }
}

template <typename T>
void sortRows(std::vector<std::vector<T>>& matrix) {
    for (auto& row : matrix) {
        sort(row.begin(), row.end());
    }
}

int main() {
    int size;
    cout << "Enter the size of the square matrix: ";
    cin >> size;

    vector<vector<int>> intMatrix(size, vector<int>(size));
    initializeMatrix(intMatrix, size);
    cout << "Integer Matrix:\n";
    printMatrix(intMatrix);

    int minInt, maxInt;
    findMinMaxDiagonal(intMatrix, minInt, maxInt);
    cout << "Minimum on diagonal: " << minInt << ", Maximum on diagonal: " << maxInt << endl;

    sortRows(intMatrix);
    cout << "Integer Matrix after sorting each row:\n";
    printMatrix(intMatrix);

    vector<vector<double>> doubleMatrix(size, vector<double>(size));
    initializeMatrix(doubleMatrix, size);
    cout << "Double Matrix:\n";
    printMatrix(doubleMatrix);

    double minDouble, maxDouble;
    findMinMaxDiagonal(doubleMatrix, minDouble, maxDouble);
    cout << "Minimum on diagonal: " << minDouble << ", Maximum on diagonal: " << maxDouble << endl;

    sortRows(doubleMatrix);
    cout << "Double Matrix after sorting each row:\n";
    printMatrix(doubleMatrix);

    vector < vector<char>> charMatrix(size, vector<char>(size));
    initializeMatrix(charMatrix, size);
    cout << "Char Matrix:\n";
    printMatrix(charMatrix);

    char minChar, maxChar;
    findMinMaxDiagonal(charMatrix, minChar, maxChar);
    cout << "Minimum on diagonal: " << minChar << ", Maximum on diagonal: " << maxChar << endl;

    sortRows(charMatrix);
    cout << "Char Matrix after sorting each row:\n";
    printMatrix(charMatrix);

    return 0;
}
---------------------------------------------------------------------------------------------------------------------------------------

int gcd(int a, int b) 
{
    if (b == 0) 
    {
        return a; 
    }
    return gcd(b, a % b); 
}

int main() 
{
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    int result = gcd(a, b);
    cout << "The greatest common divisor of " << a << " and " << b << " is: " << result << endl;

    return 0;
}
*/
/*========================================================================-Дз5-==================================================================================*/

/*===========================================================================-Дз6-===============================================================================*/
/*
int main() {
    int M, N;

    cout << "Enter the size of array A: ";
    cin >> M;
    cout << "Enter the size of array B: ";
    cin >> N;

    vector < int > A(M), B(N);
    unordered_set < int > setB, uniqueElements;

    cout << "Enter elements of array A:\n";
    for (int i = 0; i < M; ++i) 
    {
        cin >> A[i];
    }

    cout << "Enter elements of array B:\n";
    for (int i = 0; i < N; ++i) 
    {
        cin >> B[i];
        setB.insert(B[i]);  
    }

    for (int i = 0; i < M; ++i) {
        if (setB.find(A[i]) == setB.end()) 
        {
            uniqueElements.insert(A[i]);
        }
    }

    vector <int> C(uniqueElements.begin(), uniqueElements.end());

    cout << "Array C (elements in A not in B, without repetitions):\n";
    for (int element : C) {
        std::cout << element << " ";
    }
    cout << endl;

    return 0;
}
_____________________________________________________________________________________________________________________________________________________________
int main() 
{
    int M, N;
    
    cout << "Enter the size of array A: ";
    cin >> M;
    cout << "Enter the size of array B: ";
    cin >> N;

    vector<int> A(M), B(N);
    unordered_set <int> setA, setB, resultSet;

    cout << "Enter elements of array A:\n";
    for (int i = 0; i < M; ++i) 
    {
        cin >> A[i];
        setA.insert(A[i]);
    }

    cout << "Enter elements of array B:\n";
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
        setB.insert(B[i]);
    }

    for (int element : setA) 
    {
        if (setB.find(element) == setB.end()) 
        {
            resultSet.insert(element);
        }
    }

    for (int element : setB) 
    {
        if (setA.find(element) == setA.end()) 
        {
            resultSet.insert(element);
        }
    }

    vector <int> C(resultSet.begin(), resultSet.end());

    cout << "Array C (unique elements in A and B, without common elements and repetitions):\n";
    for (int element : C) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
___________________________________________________________________________________________________________________________________________________________

int* allocateArray(int size) 
{
    return new int[size];
}

void initializeArray(int* arr, int size) 
{
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) 
    {
        cin >> arr[i];
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << std::endl;
}

void deleteArray(int*& arr) {
    delete[] arr;
    arr = nullptr;
}

int* appendElement(int* arr, int& size, int value) {
    int* newArr = new int[size + 1];
    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    newArr[size] = value;
    ++size;
    delete[] arr;
    return newArr;
}

int* insertElement(int* arr, int& size, int index, int value) {
    if (index < 0 || index > size) {
        cout << "Invalid index\n";
        return arr;
    }
    int* newArr = new int[size + 1];
    for (int i = 0; i < index; ++i) {
        newArr[i] = arr[i];
    }
    newArr[index] = value;
    for (int i = index; i < size; ++i) {
        newArr[i + 1] = arr[i];
    }
    ++size;
    delete[] arr;
    return newArr;
}

int* deleteElement(int* arr, int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index\n";
        return arr;
    }
    int* newArr = new int[size - 1];
    for (int i = 0; i < index; ++i) {
        newArr[i] = arr[i];
    }
    for (int i = index + 1; i < size; ++i) {
        newArr[i - 1] = arr[i];
    }
    --size;
    delete[] arr;
    return newArr;
}

int main() {
    int size;
    cout << "Enter initial size of array: ";
    cin >> size;

    int* arr = allocateArray(size);
    initializeArray(arr, size);

    cout << "Initial array:\n";
    printArray(arr, size);

    int value;
    cout << "Enter a value to append: ";
    cin >> value;
    arr = appendElement(arr, size, value);
    cout << "Array after appending:\n";
    printArray(arr, size);

    int index;
    cout << "Enter an index to insert a value: ";
    cin >> index;
    cout << "Enter a value to insert: ";
    cin >> value;
    arr = insertElement(arr, size, index, value);
    cout << "Array after insertion:\n";
    printArray(arr, size);

    cout << "Enter an index to delete an element: ";
    cin >> index;
    arr = deleteElement(arr, size, index);
    cout << "Array after deletion:\n";
    printArray(arr, size);

    deleteArray(arr);

    return 0;
}
____________________________________________________________________________________________________________________________________________

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= std::sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int* removePrimes(int* arr, int& size)
{
    int nonPrimeCount = 0;
    for (int i = 0; i < size; ++i) 
    {
        if (!isPrime(arr[i])) 
        {
            ++nonPrimeCount;
        }
    }

    int* newArr = new int[nonPrimeCount];
    int j = 0;  

    for (int i = 0; i < size; ++i) 
    {
        if (!isPrime(arr[i])) 
        {
            newArr[j++] = arr[i];
        }
    }

    size = nonPrimeCount;

    delete[] arr;

    return newArr;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    arr = removePrimes(arr, size);

    cout << "Array after removing primes:\n";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
_________________________________________________________________________________________________________________________________________________________

struct Arrays 
{
    int* positives;
    int* negatives;
    int* zeros;
    int positiveCount;
    int negativeCount;
    int zeroCount;
};

Arrays separateElements(const int* arr, int size) 
{
    Arrays result;
    result.positiveCount = result.negativeCount = result.zeroCount = 0;

    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] > 0) result.positiveCount++;
        else if (arr[i] < 0) result.negativeCount++;
        else result.zeroCount++;
    }

    result.positives = new int[result.positiveCount];
    result.negatives = new int[result.negativeCount];
    result.zeros = new int[result.zeroCount];

    int posIndex = 0, negIndex = 0, zeroIndex = 0;
    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] > 0) result.positives[posIndex++] = arr[i];
        else if (arr[i] < 0) result.negatives[negIndex++] = arr[i];
        else result.zeros[zeroIndex++] = arr[i];
    }

    return result;
}

void printArray(const int* arr, int size, const string& label) 
{
    cout << label << ": ";
    for (int i = 0; i < size; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deleteArrays(Arrays& arrays) 
{
    delete[] arrays.positives;
    delete[] arrays.negatives;
    delete[] arrays.zeros;
}

int main() 
{
    const int size = 10;
    int arr[size] = { 3, -1, 0, 4, -5, 0, 7, -8, 9, 0 };

    Arrays separatedArrays = separateElements(arr, size);

    printArray(separatedArrays.positives, separatedArrays.positiveCount, "Positives");
    printArray(separatedArrays.negatives, separatedArrays.negativeCount, "Negatives");
    printArray(separatedArrays.zeros, separatedArrays.zeroCount, "Zeros");

    deleteArrays(separatedArrays);

    return 0;
}
*/
/*========================================================================-Дз7-==================================================================================*/
/*
const int N = 6; 

int dx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int dy[] = { 1, -1, 1, -1, 2, -2, 2, -2 };

bool isSafe(int x, int y, const vector < vector < int >>& board) 
{
    return x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1;
}

bool solveKnightTour(int x, int y, int movei, vector<vector<int>>& board) 
{
    if (movei == N * N) 
    {
        return true;
    }

    for (int i = 0; i < 8; i++) 
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isSafe(newX, newY, board)) 
        {
            board[newX][newY] = movei;

            if (solveKnightTour(newX, newY, movei + 1, board)) 
            {
                return true;
            }
            board[newX][newY] = -1;
        }
    }

    return false;
}

void printBoard(const vector < vector < int >>& board) 
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cout << board [i][j] << "\t";
        }
        cout << endl;
    }
}

int main() 
{
    int startX, startY;

    vector < vector < int >> board (N, vector < int > (N, -1));

    cout << "Enter the starting position of the knight (0 <= x, y < " << N << "): ";
    cin >> startX >> startY;

    if (startX < 0 || startX >= N || startY < 0 || startY >= N) 
    {
        cout << "Invalid starting position!" << endl;
        return 1;
    }

    board[startX][startY] = 0;

    if (solveKnightTour(startX, startY, 1, board)) 
    {
        cout << "The knight's tour path is:" << endl;
        printBoard(board);
    }
    else {
        cout << "No solution exists!" << endl;
    }

    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------

int main() 
{
    const int SIZE = 5; 
    int arr1[SIZE] = { 1, 2, 3, 4, 5 };  
    int arr2[SIZE];  

    int* ptr1 = arr1;
    int* ptr2 = arr2;

    for (int i = 0; i < SIZE; ++i) 
    {
        *(ptr2 + i) = *(ptr1 + i); 
    }

    cout << "arr1: ";
    for (int i = 0; i < SIZE; ++i) 
    {
        cout << *(ptr1 + i) << " ";
    }
    cout << endl;

    cout << "arr2: ";
    for (int i = 0; i < SIZE; ++i) 
    {
        cout << *(ptr2 + i) << " ";
    }
    cout << endl;

    return 0;
}
--------------------------------------------------------------------------------------------------------------------------------------------

int main() 
{
    const int SIZE = 5; 
    int arr[SIZE] = { 1, 2, 3, 4, 5 };  

    int* start = arr;
    int* end = arr + SIZE - 1;

    cout << "initial array: ";
    for (int i = 0; i < SIZE; ++i) 
    {
        cout << *(start + i) << " ";
    }
    cout << endl;

    while (start < end) 
    {
        int temp = *start;
        *start = *end;
        *end = temp;

        ++start;
        --end;
    }

    cout << "Array after reordering : ";
    for (int i = 0; i < SIZE; ++i) 
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    return 0;
}
---------------------------------------------------------------------------------------------------------------------------------------
int main() {
    const int SIZE = 5;  
    int arr1[SIZE] = { 1, 2, 3, 4, 5 };  
    int arr2[SIZE];  

    int* ptr1 = arr1;
    int* ptr2 = arr2 + SIZE - 1; 

    for (int i = 0; i < SIZE; ++i) 
    {
        *ptr2 = *ptr1;  
        ++ptr1;         
        --ptr2;          
    }
    cout << "arr1: ";
    for (int i = 0; i < SIZE; ++i) 
    {
        cout << *(arr1 + i) << " ";
    }
    cout << endl;

    cout << "arr2: ";
    for (int i = 0; i < SIZE; ++i) 
    {
        cout << *(arr2 + i) << " ";
    }
    cout << endl;

    return 0;
}
*/
/*===========================================================================-Дз8-===============================================================================*/
/*
int main() 
{
    int M, N;

    cout << "Enter the size of array A (M): ";
    cin >> M;
    cout << "Enter the size of array B (N): ";
    cin >> N;

    int A[M], B[N];
    cout << "Enter elements of array A: ";
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }

    cout << "Enter elements of array B: ";
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    vector < int > result;

    for (int i = 0; i < M; ++i) 
    {
        if (find(B, B + N, A[i]) == B + N && find(result.begin(), result.end(), A[i]) == result.end()) 
        {
            result.push_back(A[i]);
        }
    }

    cout << "Elements from A that are not in B (without duplicates): ";
    for (int i = 0; i < result.size(); ++i) 
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------
int main() 
{
    int M, N;
s
    cout << "Enter the size of array A (M): ";
    cin >> M;
    cout << "Enter the size of array B (N): ";
    cin >> N;

    int A[M], B[N];
    cout << "Enter elements of array A: ";
    for (int i = 0; i < M; ++i) 
    {
        cin >> A[i];
    }

    cout << "Enter elements of array B: ";
    for (int i = 0; i < N; ++i) 
    {
        cin >> B[i];
    }

    vector<int> result;

    for (int i = 0; i < M; ++i) 
    {
        if (find(B, B + N, A[i]) == B + N && find(result.begin(), result.end(), A[i]) == result.end()) 
        {
            result.push_back(A[i]);
        }
    }

    for (int i = 0; i < N; ++i) 
    {
        if (find(A, A + M, B[i]) == A + M && find(result.begin(), result.end(), B[i]) == result.end()) 
        {
            result.push_back(B[i]);
        }
    }
    cout << "Elements from A and B that are not common (without duplicates): ";
    for (int i = 0; i < result.size(); ++i) 
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
-----------------------------------------------------------------------------------------------------------------------------------------------

int* allocateMemory(int size) 
{
    return new int[size]; 
}

void initializeArray(int* arr, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        arr[i] = 0; 
    }
}

void printArray(int* arr, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deallocateMemory(int* arr) 
{
    delete[] arr; 
}

int* addElement(int* arr, int& size, int element) 
{
    int* newArr = new int[size + 1];
    for (int i = 0; i < size; ++i) 
    {
        newArr[i] = arr[i]; 
    }
    newArr[size] = element; 
    delete[] arr; 
    size++; 
    return newArr; 
}

int* insertElement(int* arr, int& size, int index, int element) 
{
    if (index < 0 || index > size) 
    {
        cout << "Index out of range!" << endl;
        return arr;
    }

    int* newArr = new int[size + 1];
    for (int i = 0; i < index; ++i) 
    {
        newArr[i] = arr[i]; 
    }
    newArr[index] = element; 
    for (int i = index; i < size; ++i) 
    {
        newArr[i + 1] = arr[i]; 
    }
    delete[] arr; 
    size++; 
    return newArr; 
}

int* deleteElement(int* arr, int& size, int index) 
{
    if (index < 0 || index >= size) 
    {
        cout << "Index out of range!" << endl;
        return arr;
    }

    int* newArr = new int[size - 1]; 
    for (int i = 0; i < index; ++i) 
    {
        newArr[i] = arr[i]; 
    }
    for (int i = index + 1; i < size; ++i) 
    {
        newArr[i - 1] = arr[i]; 
    }
    delete[] arr; 
    size--; 
    return newArr; 
}

int main() 
{
    int size = 5;
    int* arr = allocateMemory(size);
    initializeArray(arr, size);

    cout << "Initial array: ";
    printArray(arr, size);

    arr = addElement(arr, size, 10);
    cout << "After adding 10: ";
    printArray(arr, size);

    arr = insertElement(arr, size, 2, 20);
    cout << "After inserting 20 at index 2: ";
    printArray(arr, size);

    arr = deleteElement(arr, size, 1);
    cout << "After deleting element at index 1: ";
    printArray(arr, size);

    deallocateMemory(arr);

    return 0;
}
-----------------------------------------------------------------------------------------------------------------------------------------------

bool isPrime(int num) 
{
    if (num <= 1) return false; 
    if (num == 2) return true; 
    if (num % 2 == 0) return false; 
    for (int i = 3; i <= sqrt(num); i += 2) 
    {
        if (num % i == 0) 
        {
            return false; 
        }
    }
    return true;
}

int* removePrimes(int* arr, int& size, int& newSize) 
{
    int index = 0; 

    for (int i = 0; i < size; ++i) 
    {
        if (!isPrime(arr[i])) 
        { 
            newArr[index++] = arr[i]; 
        }
    }

    newSize = index; 
    return newArr; 
}

void printArray(int* arr, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deallocateMemory(int* arr) 
{
    delete[] arr; 
}

int main() 
{
    int size = 6;
    int* arr = new int[size] {2, 3, 4, 5, 6, 7}; 
    cout << "Original array: ";
    printArray(arr, size);

    int newSize; 
    int* newArr = removePrimes(arr, size, newSize); 

    cout << "Array after removing primes: ";
    printArray(newArr, newSize);

    deallocateMemory(arr); 
    deallocateMemory(newArr); 

    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------

void distributeElements(int* arr, int size, int*& posArr, int& posSize, int*& negArr, int& negSize, int*& zeroArr, int& zeroSize) 
{
    posSize = 0;
    negSize = 0;
    zeroSize = 0;

    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] > 0) 
        {
            ++posSize;
        }
        else if (arr[i] < 0) 
        {
            ++negSize;
        }
        else {
            ++zeroSize;
        }
    }

    posArr = new int[posSize];
    negArr = new int[negSize];
    zeroArr = new int[zeroSize];

    int posIndex = 0, negIndex = 0, zeroIndex = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            posArr[posIndex++] = arr[i];
        }
        else if (arr[i] < 0) {
            negArr[negIndex++] = arr[i];
        }
        else {
            zeroArr[zeroIndex++] = arr[i];
        }
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deallocateMemory(int* arr) {
    delete[] arr;
}

int main() {
    int arr[] = { 1, -3, 0, 4, -2, 5, 0, -7 }; 
    int size = sizeof(arr) / sizeof(arr[0]); 

    int* posArr, * negArr, * zeroArr;
    int posSize, negSize, zeroSize;

    distributeElements(arr, size, posArr, posSize, negArr, negSize, zeroArr, zeroSize);

    cout << "Positive elements: ";
    printArray(posArr, posSize);

    cout << "Negative elements: ";
    printArray(negArr, negSize);

    cout << "Zero elements: ";
    printArray(zeroArr, zeroSize);

    deallocateMemory(posArr);
    deallocateMemory(negArr);
    deallocateMemory(zeroArr);

    return 0;
}
*/
/*==============================================================================-Дз9-============================================================================================*/
/*
int findMax(int* arr, int size) 
{
    int maxVal = INT_MIN; 
    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] > maxVal) 
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int findMin(int* arr, int size) 
{
    int minVal = INT_MAX; 
    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] < minVal) 
        {
            minVal = arr[i];
        }
    }
    return minVal;
}

double findAvg(int* arr, int size) 
{
    int sum = 0;
    for (int i = 0; i < size; ++i) 
    {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

double Action(int* A, int sizeA, int* B, int sizeB, double(*operation)(int*, int)) 
{
    cout << "Choose an operation:" << endl;
    cout << "1. Max" << endl;
    cout << "2. Min" << endl;
    cout << "3. Average" << endl;
    int choice;
    cin >> choice;

    double result = 0;
    switch (choice) 
    {
    case 1:
        result = operation(A, sizeA); 
        break;
    case 2:
        result = operation(B, sizeB); 
        break;
    case 3:
        result = operation(A, sizeA); 
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }
    return result;
}

int main() 
{
    int A[] = { 3, 5, 7, 2, 8 };
    int B[] = { 1, -3, 4, 0, -2 };
    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);
    double result = 0;
    int choice;

    cout << "Choose an operation:" << endl;
    cout << "1. Max" << endl;
    cout << "2. Min" << endl;
    cout << "3. Average" << endl;
    cin >> choice;

    switch (choice) 
    {
    case 1:
        result = Action(A, sizeA, B, sizeB, findMax);
        cout << "Maximum value: " << result << endl;
        break;
    case 2:
        result = Action(A, sizeA, B, sizeB, findMin);
        cout << "Minimum value: " << result << endl;
        break;
    case 3:
        result = Action(A, sizeA, B, sizeB, findAvg);
        cout << "Average value: " << result << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }

    return 0;
}
---------------------------------------------------------------------------------------------------------------------------------

void removeChar(string& str, int index) 
{
    if (index >= 0 && index < str.length()) 
    {
        str.erase(index, 1); 
    }
    else 
    {
        cout << "Invalid index!" << endl;  
    }
}

int main() 
{
    string str;
    int index;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Enter the index of the character to remove: ";
    cin >> index;

    removeChar(str, index);

    cout << "Updated string: " << str << endl;

    return 0;
}
------------------------------------------------------------------------------------------------------------------------------

void removeAllOccurrences(string& str, char target) 
{
    size_t pos = 0;
    while ((pos = str.find(target, pos)) != string::npos) 
    {
        str.erase(pos, 1); 
    }
}

int main() 
{
    string str;
    char target;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Enter the character to remove: ";
    cin >> target;

    removeAllOccurrences(str, target);

    cout << "Updated string: " << str << endl;

    return 0;
}
--------------------------------------------------------------------------------------------------------------------

void insertCharAtPosition(string& str, int position, char character) 
{
    if (position >= 0 && position <= str.length()) 
    {
        str.insert(position, 1, character);  
    }
    else 
    {
        cout << "Invalid position!" << endl;  
    }
}

int main() 
{
    string str;
    int position;
    char character;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Enter the position to insert the character: ";
    cin >> position;

    cout << "Enter the character to insert: ";
    cin >> character;

    insertCharAtPosition(str, position, character);

    cout << "Updated string: " << str << endl;

    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------

void replaceDotsWithExclamation(string& str) 
{
    for (int i = 0; i < str.length(); i++) 
    {
        if (str[i] == '.')
        {
            str[i] = '!';  
        }
    }
}

int main() 
{
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    replaceDotsWithExclamation(str);

    cout << "Updated string: " << str << endl;

    return 0;
}
-----------------------------------------------------------------------------------------------------------------------------

int countCharacterOccurrences(const string& str, char target) 
{
    int count = 0;
    for (int i = 0; i < str.length(); i++) 
    {
        if (str[i] == target) 
        {
            count++; 
        }
    }
    return count;
}

int main() 
{
    string str;
    char target;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Enter the character to count: ";
    cin >> target;

    int occurrences = countCharacterOccurrences(str, target);

    cout << "The character '" << target << "' appears " << occurrences << " times in the string." << endl;

    return 0;
}
---------------------------------------------------------------------------------------------------------------------------

void countCharacterTypes(const string& str, int& letterCount, int& digitCount, int& otherCount) 
{
    for (int i = 0; i < str.length(); i++) 
    {
        if (isalpha(str[i])) 
        {  
            letterCount++;
        }
        else if (isdigit(str[i])) 
        {  
            digitCount++;
        }
        else 
        { 
            otherCount++;
        }
    }
}

int main() 
{
    string str;
    int letterCount = 0, digitCount = 0, otherCount = 0;

    cout << "Enter a string: ";
    getline(cin, str);

    countCharacterTypes(str, letterCount, digitCount, otherCount);

    cout << "Letters: " << letterCount << endl;
    cout << "Digits: " << digitCount << endl;
    cout << "Other characters: " << otherCount << endl;

    return 0;
}
*/
/*============================================================================-Дз10-===========================================================================================*/
/*
void addColumn(int**& arr, int& rows, int& cols, int position, int* newColumn) 
{
    if (position < 0 || position > cols) 
    {
        cout << "Invalid position!" << endl;
        return;
    }
    int** newArr = new int* [rows];
    for (int i = 0; i < rows; i++) 
    {
        newArr[i] = new int[cols + 1];
    }

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0, k = 0; j < cols + 1; j++) 
        {
            if (j == position) 
            {
                newArr[i][j] = newColumn[i]; 
            }
            else {
                newArr[i][j] = arr[i][k++];  
            }
        }
    }

    for (int i = 0; i < rows; i++) 
    {
        delete[] arr[i];
    }
    delete[] arr;

    arr = newArr; 
    cols++;       
}

void displayArray(int** arr, int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows = 3, cols = 3;

    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }

    cout << "Enter elements of the 3x3 array:" << endl;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cin >> arr[i][j];
        }
    }

    cout << "Original Array:" << endl;
    displayArray(arr, rows, cols);

    int newColumn[] = { 10, 20, 30 };
1
    addColumn(arr, rows, cols, 1, newColumn);

    cout << "Array after adding a new column at position 1:" << endl;
    displayArray(arr, rows, cols);

    for (int i = 0; i < rows; i++) 
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void deleteColumn(int**& arr, int& rows, int& cols, int position) 
{
    if (position < 0 || position >= cols) 
    {
        cout << "Invalid position!" << endl;
        return;
    }

    int** newArr = new int* [rows];
    for (int i = 0; i < rows; i++) 
    {
        newArr[i] = new int[cols - 1];
    }

    for (int i = 0; i < rows; i++) 
    {
        int k = 0;
        for (int j = 0; j < cols; j++) 
        
        {
            if (j != position) {
                newArr[i][k++] = arr[i][j]; 
            }
        }
    }

    for (int i = 0; i < rows; i++) 
    {
        delete[] arr[i];
    }
    delete[] arr;

    arr = newArr;
    cols--;  
}

void displayArray(int** arr, int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int rows = 3, cols = 4;

    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) 
    {
        arr[i] = new int[cols];
    }

    cout << "Enter elements of the 3x4 array:" << endl;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cin >> arr[i][j];
        }
    }

    cout << "Original Array:" << endl;
    displayArray(arr, rows, cols);

    deleteColumn(arr, rows, cols, 2);

    cout << "Array after deleting column at position 2:" << endl;
    displayArray(arr, rows, cols);

    for (int i = 0; i < rows; i++) 
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void shiftRows(int** matrix, int M, int N, int shift, bool direction) 
{
    for (int i = 0; i < M; i++) 
    {
        int* temp = new int[N]; 
        for (int j = 0; j < N; j++) 
        {
            temp[j] = matrix[i][j];
        }
        for (int j = 0; j < N; j++)
        {
            if (direction) {
                matrix[i][(j + shift) % N] = temp[j];  
            }
            else 
            {
                matrix[i][(j - shift + N) % N] = temp[j]; 
            }
        }
        delete[] temp; 
    }
}

void shiftCols(int** matrix, int M, int N, int shift, bool direction) 
{
    for (int j = 0; j < N; j++) 
    {
        int* temp = new int[M]; 
        for (int i = 0; i < M; i++) 
        {
            temp[i] = matrix[i][j];
        }
        for (int i = 0; i < M; i++)
        {
            if (direction) 
            {
                matrix[(i + shift) % M][j] = temp[i];  
            }
            else 
            {
                matrix[(i - shift + M) % M][j] = temp[i]; 
            }
        }
        delete[] temp; 
    }
}

void printMatrix(int** matrix, int M, int N) 
{
    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int M, N;
    cout << "Enter number of rows (M): ";
    cin >> M;
    cout << "Enter number of columns (N): ";
    cin >> N;

    int** matrix = new int* [M];
    for (int i = 0; i < M; i++) 
    {
        matrix[i] = new int[N];
    }

    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cin >> matrix[i][j];
        }
    }

    int choice, shift, direction;
    cout << "Choose the operation (1 - Shift rows, 2 - Shift columns): ";
    cin >> choice;

    cout << "Enter the number of positions to shift: ";
    cin >> shift;

    cout << "Enter the direction (1 - Right/Down, 0 - Left/Up): ";
    cin >> direction;

    if (choice == 1) 
    {
        shiftRows(matrix, M, N, shift, direction);
    }
    else if (choice == 2) 
    {
        shiftCols(matrix, M, N, shift, direction);
    }

    cout << "Matrix after shifting:" << endl;
    printMatrix(matrix, M, N);

    for (int i = 0; i < M; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void transposeMatrix(int** matrix, int M, int N) 
{
    int** transposed = new int* [N];
    for (int i = 0; i < N; i++) 
    {
        transposed[i] = new int[M];
    }

    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            transposed[j][i] = matrix[i][j];  
        }
    }

    cout << "Transposed Matrix:" << endl;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) 
    {
        delete[] transposed[i];
    }
    delete[] transposed;
}

void printMatrix(int** matrix, int M, int N) 
{
    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int M, N;
    cout << "Enter number of rows (M): ";
    cin >> M;
    cout << "Enter number of columns (N): ";
    cin >> N;

    int** matrix = new int* [M];
    for (int i = 0; i < M; i++) 
    {
        matrix[i] = new int[N];
    }

    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Original Matrix:" << endl;
    printMatrix(matrix, M, N);

    transposeMatrix(matrix, M, N);

    for (int i = 0; i < M; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void inputData(char** arr, int row, int col) 
{
    cout << "Enter " << (row == 0 ? "Name: " : "Phone: ");
    cin.ignore(); 
    cin.getline(arr[row], col); 
}

void searchByName(char** arr, int rows, const char* name) 
{
    bool found = false;
    for (int i = 0; i < rows; i++) 
    {
        if (strcmp(arr[i], name) == 0) 
        { 
            cout << "Found: " << arr[i] << " - " << arr[i + 1] << endl;
            found = true;
            break;
        }
    }
    if (!found) 
    {
        cout << "Name not found." << endl;
    }
}

void searchByPhone(char** arr, int rows, const char* phone) 
{
    bool found = false;
    for (int i = 1; i < rows; i += 2) 
    {
        if (strcmp(arr[i], phone) == 0) 
        { 
            cout << "Found: " << arr[i - 1] << " - " << arr[i] << endl;
            found = true;
            break;
        }
    }
    if (!found) 
    {
        cout << "Phone not found." << endl;
    }
}

void updateData(char** arr, int row, int col) 
{
    cout << "Enter new " << (row == 0 ? "Name: " : "Phone: ");
    cin.ignore(); 
    cin.getline(arr[row], col); 
}

int main() 
{
    int rows = 2;  
    int nameSize = 50; 
    int phoneSize = 20;  

    char** data = new char* [rows];
    for (int i = 0; i < rows; i++) 
    {
        data[i] = new char[(i == 0 ? nameSize : phoneSize)]; 
    }

    int choice;
    do 
    {
        cout << "Menu:\n";
        cout << "1. Enter Name and Phone\n";
        cout << "2. Search by Name\n";
        cout << "3. Search by Phone\n";
        cout << "4. Update Name\n";
        cout << "5. Update Phone\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            inputData(data, 0, nameSize);  
            inputData(data, 1, phoneSize); 
            break;

        case 2: 
            {
            char searchName[50];
            cout << "Enter Name to search: ";
            cin.ignore(); 
            cin.getline(searchName, 50);
            searchByName(data, rows, searchName); 
            break;
        }

        case 3: 
            {
            char searchPhone[20];
            cout << "Enter Phone to search: ";
            cin.ignore();  
            cin.getline(searchPhone, 20);
            searchByPhone(data, rows, searchPhone);  
            break;
        }

        case 4:
            updateData(data, 0, nameSize);  
            break;

        case 5:
            updateData(data, 1, phoneSize); 
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid option! Please try again.\n";
        }
    } while (choice != 0);

    for (int i = 0; i < rows; i++) 
    {
        delete[] data[i];
    }
    delete[] data;

    return 0;
}
*/
/*============================================================================-Дз11-==============================================================================================*/

/*============================================================================-Дз12-==============================================================================================*/
/*
struct Complex 
{
    double real; 
    double imag; 

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator + (const Complex& other) 
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator - (const Complex& other) 
    {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator * (const Complex& other) 
    {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real 
        );
    }

    Complex operator / (const Complex& other) 
    {
        double denom = other.real * other.real + other.imag * other.imag; 
        if (denom == 0) 
        {
            cout << "Error: Division by zero." << endl;
            return Complex();
        }
        double realPart = (real * other.real + imag * other.imag) / denom;
        double imagPart = (imag * other.real - real * other.imag) / denom;
        return Complex(realPart, imagPart);
    }

    void print() const 
    {
        if (imag < 0)
            cout << real << " - " << fabs(imag) << "i" << endl;
        else
            cout << real << " + " << imag << "i" << endl;
    }
};

int main() 
{
    Complex num1(3, 4); 
    Complex num2(1, 2); 

    cout << "Complex number 1: ";
    num1.print();

    cout << "Complex number 2: ";
    num2.print();

    Complex sum = num1 + num2;
    cout << "Sum: ";
    sum.print();

    Complex diff = num1 - num2;
    cout << "Difference: ";
    diff.print();

    Complex product = num1 * num2;
    cout << "Product: ";
    product.print();

    Complex quotient = num1 / num2;
    cout << "Quotient: ";
    quotient.print();

    return 0;
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------

struct Car 
{
    double length;        
    double clearance;     
    double engineVolume;  
    double enginePower;   
    double wheelDiameter;
    string color;        
    string transmission;  

    Car(double len = 0, double clear = 0, double vol = 0, double power = 0, double wheel = 0, string col = "Unknown", string trans = "Unknown")
        : length(len), clearance(clear), engineVolume(vol), enginePower(power), wheelDiameter(wheel), color(col), transmission(trans) {}

    void setValues(double len, double clear, double vol, double power, double wheel, string col, string trans) 
    {
        length = len;
        clearance = clear;
        engineVolume = vol;
        enginePower = power;
        wheelDiameter = wheel;
        color = col;
        transmission = trans;
    }

    void display() const 
    {
        cout << "Car Specifications:" << endl;
        cout << "Length: " << length << " meters" << endl;
        cout << "Clearance: " << clearance << " cm" << endl;
        cout << "Engine Volume: " << engineVolume << " L" << endl;
        cout << "Engine Power: " << enginePower << " HP" << endl;
        cout << "Wheel Diameter: " << wheelDiameter << " inches" << endl;
        cout << "Color: " << color << endl;
        cout << "Transmission Type: " << transmission << endl;
    }

    void searchValue(const string& param) const 
    {
        if (param == "length") 
        {
            cout << "Length: " << length << " meters" << endl;
        }
        else if (param == "clearance") 
        {
            cout << "Clearance: " << clearance << " cm" << endl;
        }
        else if (param == "engineVolume") 
        {
            cout << "Engine Volume: " << engineVolume << " L" << endl;
        }
        else if (param == "enginePower") 
        {
            cout << "Engine Power: " << enginePower << " HP" << endl;
        }
        else if (param == "wheelDiameter") 
        {
            cout << "Wheel Diameter: " << wheelDiameter << " inches" << endl;
        }
        else if (param == "color") 
        {
            cout << "Color: " << color << endl;
        }
        else if (param == "transmission") 
        {
            cout << "Transmission Type: " << transmission << endl;
        }
        else 
        {
            cout << "Parameter not found!" << endl;
        }
    }
};

int main() 
{
    Car car1;

    double len, clear, vol, power, wheel;
    string col, trans, param;

    cout << "Enter car details:" << endl;

    cout << "Length (in meters): ";
    cin >> len;

    cout << "Clearance (in cm): ";
    cin >> clear;

    cout << "Engine volume (in liters): ";
    cin >> vol;

    cout << "Engine power (in HP): ";
    cin >> power;

    cout << "Wheel diameter (in inches): ";
    cin >> wheel;

    cout << "Color: ";
    cin >> col;

    cout << "Transmission type: ";
    cin >> trans;

    car1.setValues(len, clear, vol, power, wheel, col, trans);

    car1.display();

    cout << "Enter the parameter to search (length, clearance, engineVolume, enginePower, wheelDiameter, color, transmission): ";
    cin >> param;
    car1.searchValue(param);

    return 0;
}
*/
/*=============================================================================-Дз13-=========================================================================================*/
/*
struct Book 
{
    string title;     
    string author;     
    string publisher;  
    string genre;      

    void input() 
    {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);
        cout << "Enter publisher: ";
        getline(cin, publisher);
        cout << "Enter genre: ";
        getline(cin, genre);
    }

    void display() const 
    {
        cout << "Title: " << title << ", Author: " << author
            << ", Publisher: " << publisher << ", Genre: " << genre << endl;
    }
};

void editBook(Book& book) 
{
    cout << "Editing book:" << endl;
    book.input();
}

void printAllBooks(const Book books[], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        cout << i + 1 << ". ";
        books[i].display();
    }
}

void searchByAuthor(const Book books[], int size, const string& author) 
{
    cout << "Books by " << author << ":" << endl;
    bool found = false;
    for (int i = 0; i < size; ++i) 
    {
        if (books[i].author == author) 
        {
            books[i].display();
            found = true;
        }
    }
    if (!found) cout << "No books found by this author." << endl;
}

void searchByTitle(const Book books[], int size, const string& title) 
{
    cout << "Searching for book with title \"" << title << "\":" << endl;
    for (int i = 0; i < size; ++i) 
    {
        if (books[i].title == title) 
        {
            books[i].display();
            return;
        }
    }
    cout << "Book not found." << endl;
}

void sortByTitle(Book books[], int size) 
{
    sort(books, books + size, [](const Book& a, const Book& b) 
        {
        return a.title < b.title;
        });
    cout << "Books sorted by title." << endl;
}

void sortByAuthor(Book books[], int size) 
{
    sort(books, books + size, [](const Book& a, const Book& b) 
        {
        return a.author < b.author;
        });
    cout << "Books sorted by author." << endl;
}

void sortByPublisher(Book books[], int size) 
{
    sort(books, books + size, [](const Book& a, const Book& b) 
        {
        return a.publisher < b.publisher;
        });
    cout << "Books sorted by publisher." << endl;
}

int main() 
{
    const int size = 10;
    Book books[size] = 
    {
        {"The Great Gatsby", "F. Scott Fitzgerald", "Scribner", "Novel"},
        {"To Kill a Mockingbird", "Harper Lee", "J.B. Lippincott & Co.", "Novel"},
        {"1984", "George Orwell", "Secker & Warburg", "Dystopian"},
        {"Pride and Prejudice", "Jane Austen", "T. Egerton", "Romance"},
        {"The Catcher in the Rye", "J.D. Salinger", "Little, Brown and Company", "Novel"},
        {"The Hobbit", "J.R.R. Tolkien", "George Allen & Unwin", "Fantasy"},
        {"Moby-Dick", "Herman Melville", "Richard Bentley", "Adventure"},
        {"War and Peace", "Leo Tolstoy", "The Russian Messenger", "Historical"},
        {"Crime and Punishment", "Fyodor Dostoevsky", "The Russian Messenger", "Psychological"},
        {"The Odyssey", "Homer", "Penguin Books", "Epic"}
    };

    int choice;
    do 
    {
        cout << "\nLibrary Menu:\n";
        cout << "1. Edit a book\n";
        cout << "2. Print all books\n";
        cout << "3. Search by author\n";
        cout << "4. Search by title\n";
        cout << "5. Sort by title\n";
        cout << "6. Sort by author\n";
        cout << "7. Sort by publisher\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) 
        {
        case 1: 
        {
            int index;
            cout << "Enter book number to edit (1-" << size << "): ";
            cin >> index;
            cin.ignore();
            if (index > 0 && index <= size) 
            {
                editBook(books[index - 1]);
            }
            else 
            {
                cout << "Invalid book number." << endl;
            }
            break;
        }
        case 2:
            printAllBooks(books, size);
            break;
        case 3: 
            {
            string author;
            cout << "Enter author to search: ";
            getline(cin, author);
            searchByAuthor(books, size, author);
            break;
        }
        case 4: 
            {
            string title;
            cout << "Enter title to search: ";
            getline(cin, title);
            searchByTitle(books, size, title);
            break;
        }
        case 5:
            sortByTitle(books, size);
            break;
        case 6:
            sortByAuthor(books, size);
            break;
        case 7:
            sortByPublisher(books, size);
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}
------------------------------------------------------------------------------------------------------------------------------------

struct Car 
{
    string color;  
    string model;  

    union 
    {
        int numericNumber;          
        char textNumber[9];        
    };
    bool isNumeric; 

    void fill() 
    {
        cout << "Enter car color: ";
        cin >> color;
        cout << "Enter car model: ";
        cin >> model;
        cout << "Enter car number (numeric or text): ";

        string input;
        cin >> input;
        if (isdigit(input[0])) 
        {  
            numericNumber = stoi(input);
            isNumeric = true;
        }
        else {
            strncpy(textNumber, input.c_str(), sizeof(textNumber) - 1);
            textNumber[sizeof(textNumber) - 1] = '\0';  
            isNumeric = false;
        }
    }

    void print() const 
    {
        cout << "Color: " << color << ", Model: " << model << ", Number: ";
        if (isNumeric) 
        {
            cout << numericNumber;
        }
        else {
            cout << textNumber;
        }
        cout << endl;
    }
};

void editCar(Car& car) 
{
    cout << "Editing car information:" << endl;
    car.fill();
}

void printAllCars(const Car cars[], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        cout << i + 1 << ". ";
        cars[i].print();
    }
}

void searchCarByNumber(const Car cars[], int size, const string& number) 
{
    bool found = false;
    for (int i = 0; i < size; ++i) 
    {
        if ((cars[i].isNumeric && to_string(cars[i].numericNumber) == number) 
            (!cars[i].isNumeric && cars[i].textNumber == number)) 
        {
            cars[i].print();
            found = true;
        }
    }
    if (!found) 
    {
        cout << "Car with number " << number << " not found." << endl;
    }
}

int main() 
{
    const int size = 10;
    Car cars[size];

    for (int i = 0; i < size; ++i) 
    {
        cout << "Enter details for car " << i + 1 << ":" << endl;
        cars[i].fill();
    }

    int choice;
    do {
        cout << "\nCar Menu:\n";
        cout << "1. Edit a car\n";
        cout << "2. Print all cars\n";
        cout << "3. Search car by number\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1: 
        {
            int index;
            cout << "Enter car number to edit (1-" << size << "): ";
            cin >> index;
            if (index > 0 && index <= size) 
            {
                editCar(cars[index - 1]);
            }
            else 
            {
                cout << "Invalid car number." << endl;
            }
            break;
        }
        case 2:
            printAllCars(cars, size);
            break;
        case 3: 
            {
            cout << "Enter number to search: ";
            string searchNumber;
            cin >> searchNumber;
            searchCarByNumber(cars, size, searchNumber);
            break;
        }
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}
----------------------------------------------------------------------------------------------------------------------------------------------------------

enum EntityType 
{
    Bird,
    Livestock,
    Human
};

struct LivingEntity 
{
    float speed;             
    EntityType type;         
    string color;            

    union 
    {
        float flightSpeed;   
        bool isEvenToed;     
        int iqLevel;        
    };

    void input() 
    {
        cout << "Enter movement speed: ";
        cin >> speed;
        cout << "Enter color: ";
        cin >> color;

        int entityType;
        cout << "Enter type (0 - Bird, 1 - Livestock, 2 - Human): ";
        cin >> entityType;
        type = static_cast<EntityType>(entityType);

        switch (type) 
        {
        case Bird:
            cout << "Enter flight speed: ";
            cin >> flightSpeed;
            break;
        case Livestock:
            cout << "Is even-toed (1 for true, 0 for false): ";
            cin >> isEvenToed;
            break;
        case Human:
            cout << "Enter IQ level: ";
            cin >> iqLevel;
            break;
        }
    }

    void print() const 
    {
        cout << "Speed: " << speed << ", Color: " << color << ", Type: ";
        switch (type) 
        {
        case Bird:
            cout << "Bird, Flight Speed: " << flightSpeed;
            break;
        case Livestock:
            cout << "Livestock, Even-Toed: " << (isEvenToed ? "Yes" : "No");
            break;
        case Human:
            cout << "Human, IQ Level: " << iqLevel;
            break;
        }
        cout << endl;
    }
};

void editEntity(LivingEntity& entity) 
{
    cout << "Editing entity:\n";
    entity.input();
}

void printAllEntities(const LivingEntity entities[], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        cout << i + 1 << ". ";
        entities[i].print();
    }
}

void searchByCharacteristic(const LivingEntity entities[], int size, EntityType type, float flightSpeed = 0, bool isEvenToed = false, int iqLevel = 0) 
{
    bool found = false;
    for (int i = 0; i < size; ++i) 
    {
        if ((entities[i].type == Bird && type == Bird && entities[i].flightSpeed == flightSpeed) 
            (entities[i].type == Livestock && type == Livestock && entities[i].isEvenToed == isEvenToed) 
            (entities[i].type == Human && type == Human && entities[i].iqLevel == iqLevel)) 
        {
            entities[i].print();
            found = true;
        }
    }
    if (!found) 
    {
        cout << "No matching entities found.\n";
    }
}

int main() 
{
    const int size = 10;
    LivingEntity entities[size];

    for (int i = 0; i < size; ++i) 
{
        cout << "Enter details for entity " << i + 1 << ":\n";
        entities[i].input();
    }

    int choice;
    do 
    {
        cout << "\nMenu:\n";
        cout << "1. Edit an entity\n";
        cout << "2. Print all entities\n";
        cout << "3. Search by characteristic\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1: 
        {
            int index;
            cout << "Enter entity number to edit (1-" << size << "): ";
            cin >> index;
            if (index > 0 && index <= size) 
            {
                editEntity(entities[index - 1]);
            }
            else 
            {
                cout << "Invalid entity number.\n";
            }
            break;
        }
        case 2:
            printAllEntities(entities, size);
            break;
        case 3: 
            {
            int searchType;
            cout << "Enter type to search (0 - Bird, 1 - Livestock, 2 - Human): ";
            cin >> searchType;

            switch (searchType) 
            {
            case 0: 
            {
                float searchFlightSpeed;
                cout << "Enter flight speed: ";
                cin >> searchFlightSpeed;
                searchByCharacteristic(entities, size, Bird, searchFlightSpeed);
                break;
            }
            case 1: 
            {
                bool searchIsEvenToed;
                cout << "Is even-toed (1 for true, 0 for false): ";
                cin >> searchIsEvenToed;
                searchByCharacteristic(entities, size, Livestock, 0, searchIsEvenToed);
                break;
            }
            case 2: 
            {
                int searchIqLevel;
                cout << "Enter IQ level: ";
                cin >> searchIqLevel;
                searchByCharacteristic(entities, size, Human, 0, false, searchIqLevel);
                break;
            }
            default:
                cout << "Invalid type.\n";
            }
            break;
        }
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
*/
/*================================================================================-Дз14-===========================================================================================*/
/*
void addColumn(int**& matrix, int& rows, int& cols, int position, int value) 
{
    if (position < 0 || position > cols) 
    {
        cout << "Неправильна позиція." << endl;
        return;
    }

    int** newMatrix = new int* [rows];
    for (int i = 0; i < rows; i++) 
    {
        newMatrix[i] = new int[cols + 1];
        int newColIndex = 0;

        for (int j = 0; j < cols + 1; j++) 
        {
            if (j == position) {
                newMatrix[i][j] = value; 
            }
            else 
            {
                newMatrix[i][j] = matrix[i][newColIndex];
                newColIndex++;
            }
        }
    }

    for (int i = 0; i < rows; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    matrix = newMatrix;
    cols++;  
}

void printMatrix(int** matrix, int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int rows = 3, cols = 3;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) 
    {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) 
        {
            matrix[i][j] = i * cols + j + 1;
        }
    }

    cout << "Вихідна матриця:\n";
    printMatrix(matrix, rows, cols);

    int position = 1;
    int value = 99;
    addColumn(matrix, rows, cols, position, value);

    cout << "\nМатриця після додавання стовпця:\n";
    printMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

void deleteColumn(int**& matrix, int rows, int& cols, int position) 
{
    if (position < 0 || position >= cols) 
    {
        cout << "Неправильна позиція." << endl;
        return;
    }

    int** newMatrix = new int* [rows];
    for (int i = 0; i < rows; i++) 
    {
        newMatrix[i] = new int[cols - 1];
        int newColIndex = 0;

        for (int j = 0; j < cols; j++) 
        {
            if (j != position) 
            {
                newMatrix[i][newColIndex] = matrix[i][j];
                newColIndex++;
            }
        }
    }

    for (int i = 0; i < rows; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    matrix = newMatrix;
    cols--; 
}

void printMatrix(int** matrix, int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int rows = 3, cols = 4;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) 
    {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) 
        {
            matrix[i][j] = i * cols + j + 1; 
        }
    }

    cout << "output matrix :\n";
    printMatrix(matrix, rows, cols);

    int position = 2;
    deleteColumn(matrix, rows, cols, position);

    cout << "\nThe matrix after removing the column :\n";
    printMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------

void shiftRow(vector<vector<int>>& matrix, int row, int shiftCount, bool toRight) 
{
    int cols = matrix[0].size();
    vector<int> temp(cols);

    for (int i = 0; i < cols; ++i) 
    {
        int newIndex = toRight ? (i + shiftCount) % cols : (i - shiftCount + cols) % cols;
        temp[newIndex] = matrix[row][i];
    }
    matrix[row] = temp;
}

void shiftColumn(vector<vector<int>>& matrix, int col, int shiftCount, bool toDown) 
{
    int rows = matrix.size();
    vector<int> temp(rows);

    for (int i = 0; i < rows; ++i) 
    {
        int newIndex = toDown ? (i + shiftCount) % rows : (i - shiftCount + rows) % rows;
        temp[newIndex] = matrix[i][col];
    }
    for (int i = 0; i < rows; ++i) 
    {
        matrix[i][col] = temp[i];
    }
}

void printMatrix(const vector<vector<int>>& matrix) 
{
    for (const auto& row : matrix) 
    {
        for (int val : row) 
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int M, N, shiftCount;
    char direction;
    bool isRowShift;

    cout << "Enter number of rows (M): ";
    cin >> M;
    cout << "Enter number of columns (N): ";
    cin >> N;

    vector<vector<int>> matrix(M, vector<int>(N));
    cout << "Enter matrix values:\n";
    for (int i = 0; i < M; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter shift type ('R' for row, 'C' for column): ";
    cin >> direction;
    isRowShift = (direction == 'R' || direction == 'r');

    cout << "Enter shift count: ";
    cin >> shiftCount;

    cout << "Enter shift direction ('L' for left, 'R' for right, 'U' for up, 'D' for down): ";
    cin >> direction;

    if (isRowShift) 
    {
        bool toRight = (direction == 'R' || direction == 'r');
        for (int i = 0; i < M; ++i) 
        {
            shiftRow(matrix, i, shiftCount, toRight);
        }
    }
    else {
        bool toDown = (direction == 'D' || direction == 'd');
        for (int j = 0; j < N; ++j) 
        {
            shiftColumn(matrix, j, shiftCount, toDown);
        }
    }

    cout << "Matrix after shift:\n";
    printMatrix(matrix);

    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------------------

vector<vector<int>> transposeMatrix(const vector<vector<int>>&matrix) 
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> transposed(cols, vector<int>(rows));

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}

void printMatrix(const vector<vector<int>>& matrix) 
{
    for (const auto& row : matrix) 
    {
        for (int val : row) 
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int M, N;
    cout << "Enter the number of rows (M): ";
    cin >> M;
    cout << "Enter the number of columns (N): ";
    cin >> N;

    vector<vector<int>> matrix(M, vector<int>(N));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < M; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    vector<vector<int>> transposedMatrix = transposeMatrix(matrix);

    cout << "Transposed Matrix:\n";
    printMatrix(transposedMatrix);

    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------------------

struct Contact 
{
    string name;
    string phone;
};

void addContact(vector<Contact>& contacts) 
{
    Contact newContact;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newContact.name);
    cout << "Enter phone number: ";
    getline(cin, newContact.phone);
    contacts.push_back(newContact);
    cout << "Contact added successfully.\n";
}

void displayContacts(const vector<Contact>& contacts) 
{
    cout << "\nContacts List:\n";
    for (const auto& contact : contacts) 
    {
        cout << "Name: " << contact.name << ", Phone: " << contact.phone << endl;
    }
}

void searchByName(const vector<Contact>& contacts, const string& name) 
{
    bool found = false;
    for (const auto& contact : contacts) 
    {
        if (contact.name == name) 
        {
            cout << "Found: Name: " << contact.name << ", Phone: " << contact.phone << endl;
            found = true;
        }
    }
    if (!found) 
    {
        cout << "Contact with name '" << name << "' not found.\n";
    }
}

void searchByPhone(const vector<Contact>& contacts, const string& phone) 
{
    bool found = false;
    for (const auto& contact : contacts) 
    {
        if (contact.phone == phone) 
        {
            cout << "Found: Name: " << contact.name << ", Phone: " << contact.phone << endl;
            found = true;
        }
    }
    if (!found) 
    {
        cout << "Contact with phone number '" << phone << "' not found.\n";
    }
}

void editContact(vector<Contact>& contacts, const string& name) 
{
    bool found = false;
    for (auto& contact : contacts) 
    {
        if (contact.name == name) 
        {
            cout << "Enter new phone number for " << contact.name << ": ";
            getline(cin, contact.phone);
            cout << "Contact updated successfully.\n";
            found = true;
        }
    }
    if (!found) 
    {
        cout << "Contact with name '" << name << "' not found.\n";
    }
}

int main() 
{
    vector<Contact> contacts;
    int choice;
    string input;

    do 
    {
        cout << "\nMenu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Display All Contacts\n";
        cout << "3. Search by Name\n";
        cout << "4. Search by Phone\n";
        cout << "5. Edit Contact by Name\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            addContact(contacts);
            break;
        case 2:
            displayContacts(contacts);
            break;
        case 3:
            cout << "Enter name to search: ";
            cin.ignore();
            getline(cin, input);
            searchByName(contacts, input);
            break;
        case 4:
            cout << "Enter phone to search: ";
            cin.ignore();
            getline(cin, input);
            searchByPhone(contacts, input);
            break;
        case 5:
            cout << "Enter name to edit: ";
            cin.ignore();
            getline(cin, input);
            editContact(contacts, input);
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 6);

    return 0;
}
*/
/*===========================================================================-Дз15-==============================================================================================*/
/*
struct Complex 
{
    double real;
    double imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
};

Complex add(const Complex& a, const Complex& b) 
{
    return Complex(a.real + b.real, a.imag + b.imag);
}

Complex subtract(const Complex& a, const Complex& b) 
{
    return Complex(a.real - b.real, a.imag - b.imag);
}

Complex multiply(const Complex& a, const Complex& b) 
{
    return Complex(a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real);
}

Complex divide(const Complex& a, const Complex& b) 
{
    double denominator = b.real * b.real + b.imag * b.imag;
    return Complex((a.real * b.real + a.imag * b.imag) / denominator,
        (a.imag * b.real - a.real * b.imag) / denominator);
}

void printComplex(const Complex& c) 
{
    cout << c.real;
    if (c.imag >= 0)
        cout << " + " << c.imag << "i";
    else
        cout << " - " << -c.imag << "i";
    cout << endl;
}

int main() 
{
    Complex num1(4, 5);
    Complex num2(2, -3);

    cout << "First complex number: ";
    printComplex(num1);

    cout << "Second complex number: ";
    printComplex(num2);

    Complex result;

    result = add(num1, num2);
    cout << "Addition: ";
    printComplex(result);

    result = subtract(num1, num2);
    cout << "Subtraction: ";
    printComplex(result);

    result = multiply(num1, num2);
    cout << "Multiplication: ";
    printComplex(result);

    result = divide(num1, num2);
    cout << "Division: ";
    printComplex(result);

    return 0;
}
--------------------------------------------------------------------------------------------------------------------------------------------------

struct Car 
{
    double length;
    double clearance;
    double engineVolume;
    int enginePower;
    int wheelDiameter;
    string color;
    string transmissionType;
};

void setCarDetails(Car& car, double length, double clearance, double engineVolume, int enginePower, int wheelDiameter, const string& color, const string& transmissionType) 
{
    car.length = length;
    car.clearance = clearance;
    car.engineVolume = engineVolume;
    car.enginePower = enginePower;
    car.wheelDiameter = wheelDiameter;
    car.color = color;
    car.transmissionType = transmissionType;
}

void displayCarDetails(const Car& car) 
{
    cout << "Car Details:" << endl;
    cout << "Length: " << car.length << " m" << endl;
    cout << "Clearance: " << car.clearance << " m" << endl;
    cout << "Engine Volume: " << car.engineVolume << " L" << endl;
    cout << "Engine Power: " << car.enginePower << " HP" << endl;
    cout << "Wheel Diameter: " << car.wheelDiameter << " inches" << endl;
    cout << "Color: " << car.color << endl;
    cout << "Transmission Type: " << car.transmissionType << endl;
    cout << endl;
}

void searchCarsByAttribute(const vector<Car>& cars, const string& attribute, const string& value) 
{
    bool found = false;
    for (const auto& car : cars) 
    {
        if ((attribute == "color" && car.color == value) 
            (attribute == "transmission" && car.transmissionType == value) 
            (attribute == "enginePower" && to_string(car.enginePower) == value)) 
        {
            displayCarDetails(car);
            found = true;
        }
    }
    if (!found) 
    {
        cout << "No cars found with " << attribute << " matching \"" << value << "\"." << endl;
    }
}

int main() 
{
    vector<Car> cars(2);

    setCarDetails(cars[0], 4.5, 0.15, 2.0, 150, 18, "Red", "Automatic");
    setCarDetails(cars[1], 4.3, 0.14, 1.8, 140, 17, "Blue", "Manual");

    cout << "All cars:" << endl;
    for (const auto& car : cars) 
    {
        displayCarDetails(car);
    }

    cout << "Search results by color \"Red\":" << endl;
    searchCarsByAttribute(cars, "color", "Red");

    cout << "Search results by transmission \"Manual\":" << endl;
    searchCarsByAttribute(cars, "transmission", "Manual");

    cout << "Search results by engine power \"150\":" << endl;
    searchCarsByAttribute(cars, "enginePower", "150");

    return 0;
}
*/
/*=============================================================================-Дз16-===========================================================================================*/

struct Book 
{
    string title;
    string author;
    string publisher;
    string genre;
};

void editBook(Book& book, const string& title, const string& author, const string& publisher, const string& genre) 
{
    book.title = title;
    book.author = author;
    book.publisher = publisher;
    book.genre = genre;
}

void printBooks(const vector<Book>& books) 
{
    for (const auto& book : books) 
    {
        cout << "Title: " << book.title << ", Author: " << book.author
            << ", Publisher: " << book.publisher << ", Genre: " << book.genre << endl;
    }
}

void searchBooksByAuthor(const vector<Book>& books, const string& author) 
{
    bool found = false;
    for (const auto& book : books) 
    {
        if (book.author == author) 
        {
            cout << "Found Book - Title: " << book.title << ", Publisher: " << book.publisher
                << ", Genre: " << book.genre << endl;
            found = true;
        }
    }
    if (!found) cout << "No books found by author: " << author << endl;
}

void searchBookByTitle(const vector<Book>& books, const string& title) 
{
    bool found = false;
    for (const auto& book : books) 
    {
        if (book.title == title) 
        {
            cout << "Found Book - Author: " << book.author << ", Publisher: " << book.publisher
                << ", Genre: " << book.genre << endl;
            found = true;
        }
    }
    if (!found) cout << "No book found with title: " << title << endl;
}

void sortBooksByTitle(vector<Book>& books) 
{
    sort(books.begin(), books.end(), [](const Book& a, const Book& b) 
        {
        return a.title < b.title;
        });
}

void sortBooksByAuthor(vector<Book>& books) 
{
    sort(books.begin(), books.end(), [](const Book& a, const Book& b) 
        {
        return a.author < b.author;
        });
}

void sortBooksByPublisher(vector<Book>& books) 
{
    sort(books.begin(), books.end(), [](const Book& a, const Book& b) 
        {
        return a.publisher < b.publisher;
        });
}

int main() {
    vector<Book> library = 
    {
        {"The Great Gatsby", "F. Scott Fitzgerald", "Scribner", "Novel"},
        {"To Kill a Mockingbird", "Harper Lee", "J.B. Lippincott & Co.", "Novel"},
        {"1984", "George Orwell", "Secker & Warburg", "Dystopian"},
        {"Moby-Dick", "Herman Melville", "Harper & Brothers", "Adventure"},
        {"Pride and Prejudice", "Jane Austen", "T. Egerton", "Romance"},
        {"The Catcher in the Rye", "J.D. Salinger", "Little, Brown and Company", "Novel"},
        {"The Lord of the Rings", "J.R.R. Tolkien", "Allen & Unwin", "Fantasy"},
        {"Harry Potter", "J.K. Rowling", "Bloomsbury", "Fantasy"},
        {"The Hobbit", "J.R.R. Tolkien", "Allen & Unwin", "Fantasy"},
        {"War and Peace", "Leo Tolstoy", "The Russian Messenger", "Historical"}
    };

    int choice;
    while (true) 
    {
        cout << "\nLibrary Menu:\n"
            << "1. Print all books\n"
            << "2. Edit a book\n"
            << "3. Search books by author\n"
            << "4. Search book by title\n"
            << "5. Sort books by title\n"
            << "6. Sort books by author\n"
            << "7. Sort books by publisher\n"
            << "8. Exit\n"
            << "Choose an option: ";
        cin >> choice;

        if (choice == 1) 
        {
            printBooks(library);
        }
        else if (choice == 2) 
        {
            int index;
            cout << "Enter book index to edit (0-9): ";
            cin >> index;
            if (index >= 0 && index < library.size()) 
            {
                string title, author, publisher, genre;
                cout << "Enter new title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter new author: ";
                getline(cin, author);
                cout << "Enter new publisher: ";
                getline(cin, publisher);
                cout << "Enter new genre: ";
                getline(cin, genre);
                editBook(library[index], title, author, publisher, genre);
            }
            else {
                cout << "Invalid index.\n";
            }
        }
        else if (choice == 3) 
        {
            string author;
            cout << "Enter author name: ";
            cin.ignore();
            getline(cin, author);
            searchBooksByAuthor(library, author);
        }
        else if (choice == 4) 
        {
            string title;
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            searchBookByTitle(library, title);
        }
        else if (choice == 5) 
        {
            sortBooksByTitle(library);
            cout << "Books sorted by title.\n";
        }
        else if (choice == 6) 
        {
            sortBooksByAuthor(library);
            cout << "Books sorted by author.\n";
        }
        else if (choice == 7) 
        {
            sortBooksByPublisher(library);
            cout << "Books sorted by publisher.\n";
        }
        else if (choice == 8) 
        {
            break;
        }
        else 
        {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------

struct Car 
{
    string color;
    string model;

    union Number 
    {
        int numericNumber;
        char stringNumber[9]; 
        Number() { numericNumber = 0; } 
    } number;

    bool isNumericNumber; 
};

void fillCar(Car& car) 
{
    cout << "Enter color: ";
    cin >> car.color;
    cout << "Enter model: ";
    cin >> car.model;

    cout << "Enter type of number (1 for numeric, 2 for alphanumeric): ";
    int choice;
    cin >> choice;

    if (choice == 1) 
    {
        cout << "Enter 5-digit number: ";
        cin >> car.number.numericNumber;
        car.isNumericNumber = true;
    }
    else 
    {
        cout << "Enter alphanumeric number (up to 8 characters): ";
        cin >> car.number.stringNumber;
        car.isNumericNumber = false;
    }
}

void printCar(const Car& car)
{
    cout << "Color: " << car.color << ", Model: " << car.model << ", Number: ";
    if (car.isNumericNumber) 
    {
        cout << car.number.numericNumber;
    }
    else {
        cout << car.number.stringNumber;
    }
    cout << endl;
}

void editCar(Car& car) 
{
    cout << "Editing Car:\n";
    fillCar(car);
}

void printAllCars(const vector<Car>& cars) 
{
    for (const auto& car : cars) 
    {
        printCar(car);
    }
}

void searchCarByNumber(const vector<Car>& cars) 
{
    cout << "Enter number to search for (numeric or alphanumeric): ";
    string searchNumber;
    cin >> searchNumber;

    bool found = false;
    for (const auto& car : cars) 
    {
        if ((car.isNumericNumber && to_string(car.number.numericNumber) == searchNumber) 
            (!car.isNumericNumber && searchNumber == car.number.stringNumber)) 
        {
            cout << "Car found:\n";
            printCar(car);
            found = true;
            break;
        }
    }
    if (!found) 
    {
        cout << "Car with number " << searchNumber << " not found.\n";
    }
}

int main() 
{
    vector<Car> cars(10); 
    int choice;

    while (true) 
    {
        cout << "\nMenu:\n"
            << "1. Add/Edit Car\n"
            << "2. Print All Cars\n"
            << "3. Search Car by Number\n"
            << "4. Exit\n"
            << "Choose an option: ";
        cin >> choice;

        if (choice == 1) 
        {
            int index;
            cout << "Enter car index to edit (0-9): ";
            cin >> index;
            if (index >= 0 && index < cars.size()) 
            {
                fillCar(cars[index]);
            }
            else {
                cout << "Invalid index.\n";
            }
        }
        else if (choice == 2) 
        {
            printAllCars(cars);
        }
        else if (choice == 3) 
        {
            searchCarByNumber(cars);
        }
        else if (choice == 4) 
        {
            break;
        }
        else 
        {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------



