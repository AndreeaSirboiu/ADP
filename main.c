# include <stdio.h>
# include <pthread.h>

#define Pthread 4

int MAT1[10][10];
int MAT2[10][10];
int MAT3[10][10];

int l1,c1,l2,c2;

void *Inmultire_Matrici_th(void *parametru)
{
    int i,j,k;
    for(i=1;i<l1;i=i+2)
        {
            for(j=0;j<c2;j++)
            {
                for(k=0;k<c1;k++)
                {
                    MAT3[i][j]+=MAT1[i][k] * MAT2[k][j];
                }
            }
        }

    printf("thread terminat\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t tid;
    int i,j,k,x;

    printf(" Introdu numarul de linii matrice 1 :");
    scanf("%d",&l1);

    printf("Introdu numarul de coloane matrice 1:");
    scanf("%d",&c1);

    for(i=0;i<l1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("Introdu Mat1[%d][%d] :",i,j);
            scanf("%d",&MAT1[i][j]);
        }
    }

    printf("\n");

    printf("Introdu numarul de linii matrice 2 :");
    scanf("%d",&l2);

    printf("Introdu numarul de coloane matrice 2 :");
    scanf("%d",&c2);

    for(i=0;i<l2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("Introdu  Mat2[%d][%d] :",i,j);
            scanf("%d",&MAT2[i][j]);
        }
    }

    if(c1!=l2)
    {
        printf("Inmultirea matricilor nu e posibila !!!");
    }
    else
    {
        for(i=0;i<l1;i=i+2)
        {
            for(j=0;j<c2;j=j+2)
            {
                MAT3[i][j]=0;
            }
        }
 for(i=0; i<Pthread ; i++){
        x=pthread_create(&tid,NULL,Inmultire_Matrici_th,NULL); //se creeaza threaduri ce sunt folosite la inmultire
        if(x==0)
            printf("Threadul %d a inceput\n",i);
        else
            printf("Threadul %d nu a inceput\n",i);
 }

        for(i=0;i<l1;i=i+2)
        {
            for(j=0;j<c2;j++)
            {
                for(k=0;k<c1;k++)
                {
                    MAT3[i][j]+=MAT1[i][k] * MAT2[k][j];
                }
            }
        }

        pthread_join(tid,NULL); //asteapta pana se termina de executat toate threadurile
    }

    printf("\n Matrix 1 \n");

    for(i=0;i<l1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d \t",MAT1[i][j]);
        }
        printf("\n");
    }

    printf("\n Matrix 2 \n");

    for(i=0;i<l2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d \t",MAT2[i][j]);
        }
        printf("\n");
    }

    printf("\n Multipication of Matrix ...\n");

    for(i=0;i<l1;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d \t",MAT3[i][j]);
        }
        printf("\n");
    }
    return 0;
}


