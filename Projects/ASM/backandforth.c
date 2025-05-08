#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int addstr(char*,char*);
extern int is_palindromeasm(char*);
extern int factstr(char*);
extern void palindrome_check();

int main(){
    int choice, num;
    char str1[100];
    char str2[100];

    printf("1) Add two numbers together\n 2) Test if a string is a palindrome (C->ASM)\n 3) Print the factorial of a number\n 4) Test if a string is a palindrome (ASM->C)\n Choose the following: ");
    scanf("%d", &choice);

    switch (choice){
        case 1:
            printf("input a number: ");
            scanf("%s", &str1);
            printf("input a second number: ");
            scanf("%s", &str2);
            num = addstr(str1,str2);
            printf("%d\n", num);
            break;

        case 2:
            printf("input a potentinal palindrome: ");
            scanf("%s", &str1);
            num = is_palindromeasm(str1);
            if (num == 1){
                printf("is a palindrome.");
            } else{
                printf("is not a palindrome.");
            }
            break;

        case 3:
            printf("input a number: ");
            scanf("%s", &str1);
            num = factstr(str1);
            printf("%d\n", num);
            break;

        case 4:
            palindrome_check();
            break;
            
    }   
    return 0;
}

int fact(int n){
    if (n <= 1) return 1;
    return n * fact(n-1);    
}

int is_palindrome(char *s){
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        if (s[left] != s[right]){
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}