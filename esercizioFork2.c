#include <stdio.h>
#include <stdlib.h>

int main(){
    int P, F1, F2, G1, H1, G2, H2, status;
    F1 = fork();
    if (F1 == 0)
    {
        printf("Sono F1 figlio di P");
        G1 = fork();
        if (G1 == 0)
        {
            printf("Sono G1 figlio di F1");
            exit(0);
        }
        else
        {
            H1 = fork();
            if (H1 == 0)
            {
                printf("Sono H1 figlio di F1");
                exit(0);
            }
        }
        waitpid(G1, &status, 0);
        waitpid(H1, &status, 0);
        exit(0);
    }
    else
    {
        printf("Sono F2 figlio di P");
        F2 = fork();
        if (F2 == 0)
        {
            G2 = fork();
            if (G2 == 0)
            {
                printf("Sono G2 figlio di F2");
                exit(0);
            }
            else
            {
                H2 = fork();
                if (H2 == 0)
                {
                    printf("Sono H2 figlio di F2");
                    exit(0);
                }
            }
            waitpid(G2, &status, 0);
            waitpid(H2, &status, 0);
            exit(0);
        }
        else
        {
            printf("Sono P padre di F1 e F2");
            waitpid(F2, &status, 0);
            waitpid(F1, &status, 0);
            return 0;
        }
    }
}