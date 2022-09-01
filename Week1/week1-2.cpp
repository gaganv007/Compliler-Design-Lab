#include <iostream>
using namespace std;

int main(){
    
    int state,i=0;
    char token,str[50];
    cout<<"Enter input string :";
    cin>>str;
    while((token=str[i++])!='\0'){
        switch(state){
            case 0: if(token=='a')
                        state=0;
                    else if(token=='b')
                        state=1;
                    else{
                        cout<<"Invalid token!";
                        exit(0);
                    }
                    break;
            case 1: if(token=='a')
                        state=0;
                    else if(token=='b')
                        state=2;
                    else{
                        cout<<"Invalid token!";
                        exit(0);
                    }

                    break;
            case 2: if(token=='a')
                        state=1;
                    else if(token=='b')
                        state=2;
                    else{
                        cout<<"Invalid token!";
                        exit(0);
                    }
                    break;
        }
    }
    if(state==0 || state==2){
        cout<<"String is accepted!\n";
    }
    else{
        cout<<"String is not accepted!\n";
    }
    return 0;
}
