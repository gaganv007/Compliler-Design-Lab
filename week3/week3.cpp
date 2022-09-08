
//Implementation of Lexical Analyser
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char st[50][10];
char kw[30][30]={"int","while","break","for","do","if","float","char","switch","double","short","long",
"unsigned","sizeof","else","register","extern","static",
"auto","case","break","volatile","enum","typedef"};
 int kw_check(char id[]){
    int i;
    for(i=0;i<24;i++)
        if(strcmp(id,kw[i])==0)
            return 1;
    return 0;
}
void sbl_tab(char id[],int n){
    int f=0;
    char c1[10];
    strcpy(c1,id);
    for(int j=0;j<n;j++){
        if(strcmp(c1,st[j])==0){
            f=1;
        }
    }
    char *p[50];
    if(f==0){
    for(int i=0;i<=10;i++){
        st[n][i]=id[i];
    }

    printf("%s\t%p\n",st[n],&st[n]);
}
}
int main(){

    char id[20], number[10],rop[10],spcf[12];
    int st =1;


    FILE *f1,*f2;

    f1=fopen("cd week3.txt","r");
    f2=fopen("file_cd.txt","w");
    char c;
    int j=0;
    int i,l;
    int n=0;
    int k=0;
    printf("Identifiers\t Address\n");
    while((c=fgetc(f1))!=EOF){

        switch(st){
            case 1:
                i=0;
                if(isalpha(c)){
                    st=2;
                    id[i]=c;
                    i++;
                }
                else if(isdigit(c)){
                    st=3;
                    number[j++]=c;
                }
                else if(c=='!'||c=='='||c=='<'||c=='>'){
                    st=4;
                    rop[k++]=c;
                }

                else if(c=='/'){
                    st=5;

                }
                else if(c==' ' || c=='\t'|| c=='\n'){
                    st=1;
                }
                else if(c=='('||c==')'||c==','||c=='{'||c=='}'||c==';'||c=='"'){
                    st=1;
                    fprintf(f2,"delimiter:\t%c\n",c);

                }
                else if(c=='%'||c=='+'||c=='-'|| c=='*'||c=='&'){
                    st=8;
                    spcf[l++]=c;
                }
                else{
                    fprintf(f2,"%c\t\n",c);
                }
                break;
            case 2:
                if(isalnum(c)){
                    st=2;
                    id[i++]=c;
                }
                else{
                    id[i]='\0';
                    if(kw_check(id))
                        fprintf(f2,"keyword:\t%s\n",id);
                    else{

                        fprintf(f2,"identifier:\t%s\n",id);
                        n++;
                        sbl_tab(id,n);
                    }
                st=1;
                i=0;
                ungetc(c,f1);

                }
                break;
            case 3:
                if(isdigit(c)||c=='.'){
                    st=3;
                    number[j++]=c;
                }
                else{
                    number[j]='\0';
                    fprintf(f2,"number:\t%s\n",number);
                    st=1;
                    j=0;
                    ungetc(c,f1);

                }
                break;
            case 4:
                if(c=='='){
                    rop[k++]=c;
                    rop[k]='\0';
                    fprintf(f2,"relational_operator:\t%s\n",rop);
                    st=1;
                    k=0;
                    ungetc(c,f1);

                }
                else{
                    rop[k]='\0';

                    fprintf(f2,"relational_operator:\t%s\n",rop);
                    k=0;
                    st=1;
                    ungetc(c,f1);
                }
                break;
                    case 5:
                        if(c=='*')
                            st=6;
                        else
                            fprintf(f2,"\n invalid lexeme");
                        break;
                    case 6:
                        if(c=='*')
                            st=7;
                        else
                            st=6;
                        break;

                    case 7:
                        if(c=='*')
                        st=7;
                        else if(c=='/')
                             st=1;
                        else
                            st=6;
                        break;

                    case 8:
                        if(c=='d'||c=='f'){
                            spcf[l++]=c;
                            fprintf(f2,"format specifier:\t%s\n",spcf);
    // ungetc(c,f1);
                            l=0;
                            st=1;
                        }
                        else{
                            spcf[l]='\0';
                            fprintf(f2,"operator:\t%s\n",spcf);
                            ungetc(c,f1);
                            st=1;
                            l=0;
                        }

 }
 }
 if(st==6)
 fprintf(f2,"comment did not close");
 fclose(f1);
 fclose(f2);
 return 0;
}
