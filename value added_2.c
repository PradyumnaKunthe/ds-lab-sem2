#include <stdio.h>
#include <string.h>

#define SIZE 100000

char arr[SIZE];
int top = -1;

void push(char ch) {
    arr[++top] = ch;
}

char pop() {
    return arr[top--];
}

int empty() {
    return top == -1;
}

int checkBalance(char str[]) {
    for(int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if(ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else {
            if(empty())
                return 0;

            char t = pop();

            if((ch == ')' && t != '(') ||
               (ch == '}' && t != '{') ||
               (ch == ']' && t != '[')) {
                return 0;
            }
        }
    }

    return empty();
}

int main() {
    char str[SIZE];

    printf("PRN: 25070521341\n");
    printf("Pradyumna kunthe\n");

    printf("Enter expression:\n");
    scanf("%s", str);

    if(checkBalance(str))
        printf("match Expression\n");
    else
        printf("unmatched expression\n");

    return 0
}
