//#include "stackqueue.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
typedef struct info{
    //int key;
    char value[20];
} Info;

int main(void){
    Info a;
    Info b;

    printf("a = %s a = %p\n", a.value, a.value);
    printf("b = %s b = %p\n", b.value, b.value);

    strcpy(a.value, "Hola");
    //a.value = "Hola";
    b = a;
    //b.value = a.value;
    strcpy(a.value, "Chao");

    printf("a = %s a = %p\n", a.value, a.value);
    printf("b = %s b = %p\n", b.value, b.value);
    return 0;
}
*/


int main(void){
    char a[20];
    char b[20];

    printf("a = %s a = %p\n", a, a);
    printf("b = %s b = %p\n", b, b);

    strcpy(a, "Hola");
    strcpy(b, a);
    //strcpy(a, "Chao");
    //b = a;

    printf("a = %s a = %p\n", a, a);
    printf("b = %s b = %p\n", b, b);
    return 0;
}


/*
int main()
{
    List A;
    Info element;
    list_initialize(&A);
    element.key = 1; strcpy(element.value, "Hola");
    stack_push (&A, element);
    element.key = 2; strcpy(element.value, "Mundo");
    stack_push (&A, element);
    //element.key = 1; element.value = 'a';
    //queue_enqueue (&A, element);
    //element.key = 2; element.value = 'b';
    //queue_enqueue (&A, element);
    //element.key = 3; element.value = 'c';
    //queue_enqueue (&A, element);
    //element.key = 4; element.value = 'd';
    //queue_enqueue (&A, element);

    while (!stack_isEmpty(&A)) {
        element = stack_pop(&A);
        info_print(element);
    }
    printf ("\n");
    list_finalize(&A);
    return 0;
}
*/

/*
void read_message(char *x){
    List s;
    int l, i;
    char c;
    Info y;
    list_initialize(&s);
    l = strlen(x);
    for (i=0; i<l; i++){
        c = x[i];
        if (c=='*'){
            y = stack_pop(&s);
            printf("%c", y.value);
        }
        else{
            y.value = c;
            stack_push(&s, y);
        }
    }
    list_finalize(&s);
}
*/

/*
bool check(char *x){
    List s;
    int l, i;
    char c;
    Info y;
    list_initialize(&s);
    l = strlen(x);
    for (i=0; i<l; i++){
        c = x[i];
        if (c=='{' || c=='[' || c=='('){
            y.value = c;
            stack_push(&s, y);
        }
        if (c=='}' || c==']' || c==')'){
            if (stack_isEmpty(&s)) return false;
            y = stack_pop(&s);
            switch(c){
            case '}':
                if (y.value!='{') return false;
                break;
            case ']':
                if (y.value!='[') return false;
                break;
            case ')':
                if (y.value!='(') return false;
                break;
            }
        }
    }
    if (!stack_isEmpty(&s)) return false;
    list_finalize(&s);
    return true;
}
*/


/*
int main(void){
    char x[250];
    printf("Ingrese la cadena: ");
    scanf("%s", x);
    //read_message(x);
    if (check(x)){
        printf("Todo Bien");
    }
    else{
        printf("Error");
    }
    return 0;
}
*/
/*
// print all the values in console
void print_message(List *Q){
    Info element;
    while (!stack_isEmpty(Q)){
        element = queue_dequeue(Q);
        printf("%s", element.value);
    }
}

int main(void){
    int n, m, i, id, sec;
    char x[20];
    List Q1[20];
    Info y;
    scanf("%d %d", &n, &m);
    for (i=0; i<m; i++){
        list_initialize(&Q1[i]);
    }
    for(i=0; i<n; i++){
        scanf("%d %d %s", &id, &sec, x);
        strcpy(y.value, x);
        queue_enqueue(&Q1[id-1], y);
    }
    printf("Messages: \n");
    for (i=0; i<m; i++){
        printf("\n%d: ", i+1); print_message(&Q1[i]);
        list_finalize(&Q1[i]);
    }
    return 0;
}
*/
