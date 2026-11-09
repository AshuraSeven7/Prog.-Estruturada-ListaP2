#include <stdio.h>
#include <math.h>

    void ConverterParaNotacao(double num, double *mantissa, int *expoente){
        if(num == 0.0){
            *mantissa = 0.0;
            *expoente = 0;
            return;
        }
        int exp = (int)floor(log10(fabs(num)));

        double man = num / pow (10.0, exp);

        if(fabs(man)>=10.0){
            man/=10.0;
            exp++;
        }
        else if(fabs(man)<1.0){
            man *= 10.0;
            exp--;
        }
        *mantissa = man;
        *expoente = exp;
    }
    int main(){
        double numero;
        if(scanf("%lf", &numero)!=EOF){
            double mantissa;
            int expoente;
        
        ConverterParaNotacao(numero, &mantissa, &expoente);
        printf("%+.4fE%+02d\n", mantissa, expoente);
        }
    return 0;
}