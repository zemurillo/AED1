#include <stdio.h>

int main() {
    long long a;
    long long b;
    long long c;
    
    // Use o formato sem o '\n'
    scanf("%lld", &a);
    scanf("%lld", &b);
    scanf("%lld", &c);
    
    printf("%lld\n", a);
    printf("%lld\n", b);
    printf("%lld\n", c);

    return 0;
}
