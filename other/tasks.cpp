#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <setjmp.h>

#define try do { jmp_buf buf_state; switch(setjmp (buf_state)) { case 0:
#define catch(x) break; case x:
#define ENDTRY }} while(0);
#define THROW(x) longjmp(buf_state, x);
*/
#define BUFFER_SIZE 1024

int mini(int a, int b){

    if(a > b){
        return a;
    } else if(b > a){
        return b;
    } else{
        return a;
    }
    return 0;

}

void try_the_thing(vector<vector<char>> de, int x, int y){


    try{

        de[y][x] = '*';

    } catch(...){

        int q = 0;

    }

}

int strcm(char st1[], char st2[]){

    if(strlen(st1) != strlen(st2)){

        return 1;

    }
    for(int i = 0; i < (int)strlen(st1); ++i){

        if(st1[i] != st2[i]){

            return 1;

        }

    }
    return 0;

}

int isword(char st[]){

    for(int i = 0; i < (int)strlen(st); ++i){

        if(st[i] >= 0 && st[i] <= 9){

            return 0;

        }

    }

    return 1;

}

int main(){

    int task_num;
    printf("Task number. From 1 to 10 ");
    scanf("%d", &task_num);
    if(task_num == 1){

        char ch;
        scanf("%c", &ch);
        if(0 <= (int)ch && 9 >= (int)ch){

            printf("yes");

        } else{

            printf("no");

        }
        

    } else if(task_num == 2){

        char ch;
        scanf("%c", &ch);
        if(ch >= 'a'){

            putchar((char)(ch - ("a" - "A")));

        } else{

            putchar((char)(ch + ("a" - "A")));

        }

    } else if(task_num == 3){

        char *t = NULL;
        char *buf = (char*)realloc(t, BUFFER_SIZE*sizeof(char));
        scanf("%s", buf);
        char check[strlen(buf)];
        scanf("%s", check);
        if(!strcm(buf, check)){

            printf("yes");

        } else{

            printf("no");

        }    

    } else if(task_num == 4){

        char *z = NULL;
        char *buf = (char*) realloc(z, BUFFER_SIZE*sizeof(char));
        char *word = (char*) realloc(z, BUFFER_SIZE*sizeof(char));
        scanf("%s", buf);
        char t = 1;
        int co = 0;
        int co2 = 0;
        int word_counter;
        while(t != '\0'){

            t = buf[co];
            if(t != ' '){

                word[co2] = t;
                co2++;

            } else{
                
                if(isword(word)){

                    word_counter++;
                    for(int i = t; i < BUFFER_SIZE; ++i){

                        word[i] = ' ';

                    }

                }

            }
            co++;

        }
        printf("%d", word_counter);

    } else if(task_num == 5){

        char *t = NULL;
        char *buf = (char*) realloc (t, BUFFER_SIZE*sizeof(char));
        scanf("%s", buf);
        char revd[strlen(buf)];
        for(int i = 0; i < (int)strlen(buf); ++i){

            revd[i] = buf[strlen(buf) - i];

        }
        if(!strcm(buf, revd)){

            printf("yes");
        
        } else{

            printf("no");

        }

    } else if(task_num == 6){

        char *t = NULL;
        char *buf = (char*) realloc(t, BUFFER_SIZE*sizeof(char));
        scanf("%s", buf);
        //char keys[128];
        char vals[128];
        for(int i = 0; i < (int)strlen(buf); ++i){

            vals[(int)buf[i]]++;
            if(vals[(int)buf[i]] == 2){

                printf("%c", i);
                return 0;

            }

        }

    } else if(task_num == 7){

        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int dx = (x2 - x1);
        int dy = (y2 - y1);
        if(dx <= 1 && dx >= -1 && dy <= 1 && dy >= -1){

            printf("yes");

        } else{

            printf("no");

        }

    } else if(task_num == 8){

        char pl[2];
        scanf("%s", pl);
        int x = (int)pl[0] - 97 + 1;
        int y = (int)pl[1];
        vector<vector<char>> de;
         for(int q = 0; q < 8; ++q){

            for(int w = 0; w < 8; ++w){

                if(q == y and w == x){

                    de[q][w] = 'Q';

                } else{

                    de[q][w] = '.';

                }

            }

        }

        for(int i = 1; i < 8; ++i){

            try_the_thing(de, x + i, y);
            try_the_thing(de, x, y + i);
            try_the_thing(de, x - i, y);
            try_the_thing(de, x, y - i);
            try_the_thing(de, x + i, y + i);
            try_the_thing(de, x - i, y - i);
            try_the_thing(de, x + i, y - i);
            try_the_thing(de, x - i, y + i);
/*
            try_the_thing(de[y][x + i]);
            try_the_thing(de[y + i][x]);
            try_the_thing(de[y][x - i]);
            try_the_thing(de[y - i][x]);
            try_the_thing(de[y + i][x + i]);
            try_the_thing(de[y - i][x - i]);
*/
        }

        for(int q = 0; q < 8; ++q){

            for(int w = 0; w < 8; ++w){

                printf("%c", de[q][w]);

            }

            printf("\n");

        }

    } else if(task_num == 9){

        int n, m, x, y;
        scanf("%d %d %d %d", &n, &m, &x, &y);
        printf("%d", mini(mini(n - x, x), mini(m - y, y)));

    } else if(task_num == 10){

        //я сдавал это задание уже на informatics'e
        return 0;

    } else{

        int ch, mi, se;
        scanf("%d", &ch);
        scanf("%d", &mi);
        scanf("%d", &se);
        double de = 1/12 * ch + 1 / 12 / 60 * mi + 1 / 12 / 3600 + se;
        printf("%7f", de);

    }

}