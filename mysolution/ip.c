# include<stdio.h>
void PrintBinary(int num) {
    unsigned int mask = 1 << 7;
    for (int i = 0; i < 8; ++i) {
        printf("%d", (num & mask) ? 1 : 0); 
        mask >>= 1; 
    }
}

int main(){
    for(int i=0;i<4;i++){
    int num;
    scanf("%d", &num);
    PrintBinary(num);
    getchar();
    }
}