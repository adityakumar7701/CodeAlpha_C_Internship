#include <stdio.h>

void add(int a[10][10], int b[10][10], int r, int c);
void multiply(int a[10][10], int b[10][10], int r1, int c1, int c2);
void transpose(int a[10][10], int r, int c);

int main() {
    int ch, r1, c1, r2, c2;
    int a[10][10], b[10][10];

    printf("1.Addition  2.Multiplication  3.Transpose\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    if(ch == 1) {
        printf("Enter rows & cols: ");
        scanf("%d %d", &r1, &c1);
        for(int i=0;i<r1;i++)
            for(int j=0;j<c1;j++)
                scanf("%d",&a[i][j]);
        for(int i=0;i<r1;i++)
            for(int j=0;j<c1;j++)
                scanf("%d",&b[i][j]);
        add(a,b,r1,c1);
    }

    else if(ch == 2) {
        printf("Enter r1 c1 r2 c2: ");
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        if(c1!=r2){ printf("Not possible"); return 0; }
        for(int i=0;i<r1;i++)
            for(int j=0;j<c1;j++)
                scanf("%d",&a[i][j]);
        for(int i=0;i<r2;i++)
            for(int j=0;j<c2;j++)
                scanf("%d",&b[i][j]);
        multiply(a,b,r1,c1,c2);
    }

    else if(ch == 3) {
        printf("Enter rows & cols: ");
        scanf("%d %d",&r1,&c1);
        for(int i=0;i<r1;i++)
            for(int j=0;j<c1;j++)
                scanf("%d",&a[i][j]);
        transpose(a,r1,c1);
    }

    return 0;
}

void add(int a[10][10], int b[10][10], int r, int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            printf("%d ",a[i][j]+b[i][j]);
        printf("\n");
    }
}

void multiply(int a[10][10], int b[10][10], int r1, int c1, int c2){
    int r[10][10]={0};
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            for(int k=0;k<c1;k++)
                r[i][j]+=a[i][k]*b[k][j];
            printf("%d ",r[i][j]);
        }
        printf("\n");
    }
}

void transpose(int a[10][10], int r, int c){
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++)
            printf("%d ",a[j][i]);
        printf("\n");
    }
}