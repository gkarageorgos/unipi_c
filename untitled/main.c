#include <stdio.h>

void array_initialization();
int maxArray();
int minArray();
void secondmaxArray();
void secondminArray();
int Rate();
void search();
void maxFromTwoArrays();
void minFromTwoArrays();
void HowManyAndWhatElementsExistInSecondArray();

int main() {
    /*int array_size;
    printf("Please enter the size of the array:");
    scanf("%d", &array_size);
    int myArray[array_size];
    array_initialization(myArray, array_size);*/
    int myArray[8] = {109, 16, 50, -67, 109, 109, 7, 9}, max, min;
    max = maxArray(myArray, 8);
    int count1 = Rate(myArray, 8, max);
    search(myArray, 8, max, count1);
    secondmaxArray(myArray, 8, max);
    min = minArray(myArray, 8);
    int count2 = Rate(myArray,8 ,min);
    search(myArray, 8, min, count2);
    secondminArray(myArray, 8, min);
    int userinput;
    printf("Please enter an integer number:");
    scanf("%d",&userinput);
    int count = Rate(myArray, 8, userinput);
    if (count){
        search(myArray, 8, userinput, count);
    }
    int myOtherArray[6] = {2, 5, 3, -100, 7, 109};
    maxFromTwoArrays(max, myOtherArray, 6);
    minFromTwoArrays(min, myOtherArray, 6);
    HowManyAndWhatElementsExistInSecondArray(myArray, 8, myOtherArray, 6);
    return 0;
}

int maxArray(int Array[], int size){
    int max = Array[0];
    for(int i = 1; i < size; i++){
        if (Array[i] > max){
            max = Array[i];
        }
    }
    printf("The max number of the array is: %d\n",max);
    return max;
}

int minArray(int Array[],int size){
    int min = Array[0];
    for (int i = 1; i < size; i++){
        if (Array[i] < min ){
            min = Array[i];
        }
    }
    printf("The min number of the array is: %d\n",min);
    return min;
}

void secondmaxArray(int Array[],int size,int max1){
    int max2 = max1;
    for (int i = 0; i < size; i++){
        if (Array[i] != max1){
            max2 = Array[i];
            break;
        }
    }
    if (max2 == max1){
        printf("all elements of array are the same. The second max number of the array does not exist");
    }
    else{
        for (int j = 0; j < size; j++){
            if (Array[j] != max1){
                if (Array[j] > max2){
                    max2 = Array[j];
                }
            }
        }
        printf("The second max number of the array is: %d \n",max2);
    }
}

void secondminArray(int Array[],int size,int min1){
    int min2;
    for (int i = 0; i < size; i++){
        if (Array[i] != min1){
            min2 = Array[i];
            break;
        }
    }
    for (int j = 0; j < size; j++){
        if (Array[j] != min1){
            if (Array[j] < min2){
                min2 = Array[j];
            }
        }
    }
    printf("The second min number of the array is: %d \n",min2);
}

int Rate(int Array[], int size, int number) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (Array[i] == number) {
            count++;
        }
    }
    if (count == 0) {
        printf("The number %d does not exist in the given array\n", number);
    }
    return count;
}

void search(int Array[],int size, int number, int existed_number){
    if (existed_number == 1){
        printf("The number %d exist %d time in the given array at the position:",number,existed_number);
    }
    else{
        printf("The number %d exists %d times in the given array at the positions:",number,existed_number);
    }
    int N = 0;
    for (int i = 0; (i < size) && (existed_number > 1); i++){
        if (Array[i] == number) {
            printf(" %d,", i + 1);
            --existed_number;
        }
        N++;
    }
    for (int j = N; (j < size) && (existed_number > 0); j++){
        if (Array[j] == number) {
            printf(" %d.\n", j + 1);
            --existed_number;
        }
    }
}

void array_initialization(int A[],int size ){
    for (int i = 0; i < size; i++){
        printf("Please enter a integer number for the element myArray[%d]:", i);
        scanf("%d", &A[i]);
    }
}

void maxFromTwoArrays(int max1, int arr2[], int size2){
    int maximum = max1, n = 0;
    for (int i = 0; i < size2; i++){
        if (arr2[i] >= maximum){
            maximum = arr2[i];
            n++;
        }
    }
    if (n){
        if (maximum == max1){
            printf("The max number is %d and its located in both arrays\n", maximum);
        }
        else{
            printf("The max number is %d and has been found in the second array\n", maximum);
        }
    }
    else{
        printf("The max number is %d and has been found in the first array\n", maximum);
    }
}

void minFromTwoArrays(int min1, int arr2[], int size2){
    int minimum = min1, n = 0; //
    for (int i = 0; i < size2; i++){
        if (arr2[i] <= minimum){
            minimum = arr2[i];
            n++;
        }
    }
    if (n){
        if (minimum == min1){
            printf("The min number is %d and its located in both arrays\n", minimum);
        }
        else{
            printf("The min number is %d and has been found in the second array\n", minimum);
        }
    }
    else{
        printf("The min number is %d and has been found in the first array\n", minimum);
    }
}

void HowManyAndWhatElementsExistInSecondArray(int FirstArray[], int size1, int SecondArray[], int size2){
    int n = 0;
    for (int i = 0; i < size1; i++){
        for (int j = 0; j <size2; j++){
            if (FirstArray[i] == SecondArray[j]){
                printf("The element FirstArray[%d] exist in the second Array\n",i);
                n++;
                break;
            }
        }
    }
    if (n == 0) {
        printf("There are not elements of the first Array in the second Array\n");
    }
    else if (n == 1){
        printf("One element of the first Array exist in the second Array");
    }
    else{
        printf("There are %d elements of the first Array in the second Array\n", n);
    }
}