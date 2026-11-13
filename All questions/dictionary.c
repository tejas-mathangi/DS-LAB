#include <stdio.h>
#include <string.h>
#define MAX 50

char keys[MAX][20];
char vals[MAX][20];
int count = 0;

void insert(char key[],char val[]){
    for(int i =0;i<count;i++){
        if(strcmp(keys[i],key)==0){
            printf("key already exits");
            return;
        }
    }
    strcpy(keys[count],key);
    strcpy(vals[count],val);
    count++;
}
void search(char key[]){
    for(int i =0; i<count ;i++){
        if(strcmp(keys[i],key)==0){
            printf("%s->%s",keys[i],vals[i]);
            return;
        }
    }
    printf("key not found");
}
void delete(char key[]){
    for(int i =0 ; i <count;i++){
        if(strcmp(keys[i],key)==0){
            for(int j=0;j<count-1;j++){
                strcpy(keys[j],keys[j+1]);
                strcpy(vals[j],vals[j+1]);
            }
            count--;
            return;
        }
    }
    printf("key not found");
}
void display(){
    for(int i =0;i<count;i++){
        printf("%s->%s\n",keys[i],vals[i]);
    }
}
int main(){
    insert("name", "Alice");
    insert("city", "Hyderabad");
    insert("age", "21");

    display();

    search("age");
    delete("city");

    display();

    return 0;
}