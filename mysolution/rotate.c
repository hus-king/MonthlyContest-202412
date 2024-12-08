# include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    char a[110][110];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n;) {
            char c = getchar();
            if (c == '1' || c == '0') {
                a[i][j] = c - '0';
                j++;
            }
        }
    }
    int temp[4]={a[1][1],a[1][n],a[n][1],a[n][n]};
    for(int i=n;i>1;i--){
        a[1][i]=a[1][i-1];
    }
    a[1][1]=a[2][1];
    for(int i=n;i>2;i--){
        a[i][n]=a[i-1][n];
    }
    a[2][n]=temp[1];
    for(int i=1;i<n-1;i++){
        a[n][i]=a[n][i+1];
    }
    a[n][n-1]=temp[3];
    for(int i=2;i<n-1;i++){
        a[i][1]=a[i+1][1];
    }
    a[n-1][1]=temp[2];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            putchar(a[i][j]+'0');
        }
        if(i!=n)
        printf("\n");
    }
}