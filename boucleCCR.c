
#include <stdio.h>
int main(int argc, const char*argv[]) {
    float d,p,sp,fo2dil,fhedil,fn2dil,fo2loop,finert,fn2loop,fheloop,pnarc,profne;
    char encore;
    encore='o';
    while (encore=='o') {      
        printf("Calcul de la composition de la boucle d'un recycleur en circuit ferme\n");
        printf("Profondeur max. (m):\n");
        scanf("%f",&d);
        p=d/10+1;
        printf("Setpoint:\n");
        scanf("%f",&sp);
        printf("Fraction O2 dans le diluent:\n");
        scanf("%f",&fo2dil);
        printf("Fraction He dans le diluent:\n");
        scanf("%f",&fhedil);
        fn2dil=1-fo2dil-fhedil;
        fo2loop=sp/p;
        printf("Fraction d'O2 dans la boucle a Prof. max.: %1.2f\n",fo2loop);
        finert=1-fo2loop;
        if (fhedil==0) {
            printf("Diluent Nitrox\n");
            fn2loop=finert;
            fheloop=0;
        }
        else if (fn2dil==0) {
            printf("Diluent Heliox\n");
            fheloop=finert;
            fn2loop=0;
        }
        else {
            printf("Diluent Trimix\n");
            fn2loop=finert*(fn2dil/(fn2dil+fhedil));
            fheloop=finert*(fhedil/(fn2dil+fhedil));
        }
        printf("fN2 max= %1.2f\n",fn2loop);
        printf("fHe max= %1.2f\n",fheloop);
        pnarc=(1-fheloop)*p;
        profne=(pnarc-1)*10;
        printf("pne (m)= %3.1f\n",profne);
        printf("Un autre calcul (o/n)? ");
        scnf(" %c",&encore);
    }
    return 0
}

