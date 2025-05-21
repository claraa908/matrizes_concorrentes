#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
    HANDLE t1, t2;
    char* message = "t1";
    char* message2 = "t2";

    DWORD it1, it2;
    printf("alo pai");

    t1 = (NULL, 0, print_message, &message, 0, it1);
    t2 = (NULL, 0, print_message, &message2, 0, it2);

    if (t1 == NULL) {
        printf("Erro ao criar thread 1.\n");
        return 1;
    }
    if (t2 == NULL) {
        printf("Erro ao criar thread 2.\n");
        return 1;
    }

    WaitForSingleObject(t1, INFINITE);
    WaitForSingleObject(t2, INFINITE);

    CloseHandle(t1);
    CloseHandle(t2);

    printf("thead1 return %d: ", it1);
    printf("thead2 return %d: ", it2);
}

DWORD WINAPI print_message(LPVOID *ptr){
char* m = (char *)ptr;
printf("%s", m);
}