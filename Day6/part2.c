#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int max = 30,qno = 26;

int newgroup(FILE *in){
    char s[max];
    int questions[qno], persons = 0;

    for (int i = 0; i < qno; i++) questions[i] = 0;
    fgets(s,max,in);

    while (strcmp(s,"\n") && !feof(in)){
        persons++;
        int n = strlen(s);
        for (int i = 0; i < n; i++)
            questions[(s[i]-'a')]++;
        
        fgets(s,200,in);
    }
    int ANS = 0;
    for (int i = 0; i < qno; i++) ANS += (questions[i] == persons);
    return ANS;
}

int solve(){
    FILE *in = fopen("in.in", "r");

    int ANS = 0;
    while(! feof(in))
    ANS += newgroup(in);
    fclose(in);
    
    return ANS;
}

int main(){
    int ANS = solve();
    printf("%d\n", ANS);
    return 0;
}
