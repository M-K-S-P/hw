#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//file for further usage

struct mat{
    int** matri;
    int si;
};

int stoi(char* exp, int i, int pred){
  char* el = (char*)malloc(sizeof(char) * (i - pred));
  memcpy(el, &exp[pred], (i - pred));
  int intt = (int)strtol(el, (char **)NULL, 10);
  free(el);
  return intt;
}

int logt(int a, int co){
    if(a < 10){
        return co + 1;
    } else{
        logt(a / 10, co++);
    }
}

struct mat* matread(FILE* f1){

    char* l = (char*)malloc(sizeof(char) * 10);
    size_t s = 10;
    getline(&l, &s, f1);
    int k = 0;
    int pred = 0;
    int num = stoi(l, strlen(l), 0);
    int** matr = (int**)malloc(sizeof(*matr) * num);
    for(int i = 0; i < num; i++){
        matr[i] = (int*)malloc(sizeof(int) * num);
        char* fir = (char*)malloc(sizeof(char) * num * num);
        s = num * num;
        getline(&fir, &s, f1);
        k = 0;
        pred = 0;
        for(int j = 0; j < strlen(fir); j++){
            if(fir[j] == ' '){
                matr[i][k++] = stoi(fir, j, pred);
                printf("%d ", stoi(fir, j, pred));
                pred = j + 1;
            }
        }
        if(i == num - 1){
            matr[i][k] = stoi(fir, strlen(fir), pred);
            printf("%d\n", stoi(fir, strlen(fir), pred));
        } else{
            printf("\n");
        }
    }  
    struct mat* m = (struct mat*)calloc(1 + num * num, sizeof(int));
    m->matri = matr;
    m->si = num;
    //looks like im french lol
    return m;

}

void parsestring(char* exp, int* vals){
    for(int i = 0; i < strlen(exp); i++){
        if(exp[i] == ' '){
            vals[0] = stoi(exp, i, 0);
            vals[1] = stoi(exp, strlen(exp), i++);
            break;
        }
    }
}

int main(int argc, char** argv){
    
    if(!strcmp(argv[1], "1")){ //checks if graph is NOT oriented
        FILE* f1 = fopen("graf_1_1.txt", "r");
        struct mat* m1 = matread(f1);
        for(int i = 0; i < m1->si; i++){

            for(int j = i + 1; j < m1->si; j++){
                if(m1->matri[i][j] != m1->matri[j][i]){
                    printf("%d %d NO\n", i, j);
                    return 0;
                }
            }

        }
        printf("YES\n");
        return 0;

    } else if(!strcmp(argv[1], "2")){ //edge count
        FILE* f2 = fopen("graf_1_2.txt", "r");
        struct mat* m2 = matread(f2);
        int co = 0;
        for(int i = 0; i < m2->si; i++){
            for(int j = i + 1; j < m2->si; j++){
                if(m2->matri[i][j]){
                    co++;
                }
            }
        }
        printf("%d\n", co);
        return 0;

    } else if(!strcmp(argv[1], "3")){ //adjacency matrix to adjacency list
        FILE* f3 = fopen("graf_1_3.txt", "r");
        struct mat* m3 = matread(f3);
        int k = 0;
        int** adjl = (int**)malloc(sizeof(*adjl) * m3->si * m3->si / 2);
        for(int i = 0; i < m3->si; i++){
            for(int j = 0; j < m3->si; j++){
                if(m3->matri[i][j]){
                    adjl[k] = (int*)malloc(sizeof(int) * 2);
                    adjl[k][0] = i;
                    adjl[k][1] = j;
                    k++;
                    printf("%d %d\n", i, j);
                }
            }
        }
        return 0;

    } else if(!strcmp(argv[1], "4")){ //vice versa
        FILE* f4 = fopen("graf_1_4.txt", "r");
        int x, y, n, m;
        size_t s = 100;
        char* inp = (char*)malloc(sizeof(char) * s);
        getline(&inp, &s, f4);
        int returned[2];
        parsestring(inp, returned);
        n = returned[0];
        m = returned[1];
        int** matr = (int**)calloc(n, sizeof(*matr));
        for(int i = 0; i < n; i++){
            matr[i] = (int*)calloc(n, sizeof(int));
        }
        for(int i = 0; i < m; i++){
            char* st = (char*)malloc(sizeof(char) * s);
            getline(&st, &s, f4);
            parsestring(st, returned);
            x = returned[0];
            y = returned[1];
            matr[x - 1][y - 1] = 1;
            matr[y - 1][x - 1] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%d ", matr[i][j]);
            }
            printf("\n");
        }
        return 0;

    } else if(!strcmp(argv[1], "5")){
        FILE* f5 = fopen("graf_1_5.txt", "r");
        int x, y, n, i, j, pred = 0, k;
        size_t s = 100;
        char* fir = (char*)malloc(sizeof(char) * 100);
        getline(&fir, &s, f5);
        n = stoi(fir, strlen(fir), 0);
        int** matr = (int**)calloc(n, sizeof(*matr));
        int** inv = (int**)calloc(n, sizeof(*inv));
        for(int i = 0; i < n; i++){
            matr[i] = (int*)malloc(n * sizeof(int));
            inv[i] = (int*)malloc(n * sizeof(int));
        }
        for(int i = 0; i < n; i++){
            getline(&fir, &s, f5);
            // printf("%d\n", strlen(fir));
            if(strlen(fir) - 2){
                pred = 0;
                for(j = 0; j < strlen(fir); j++){
                    if(fir[j] == ' '){
                        y = stoi(fir, j, pred);
                        matr[i][y - 1] = 1;
                        inv[y - 1][i] = 1;
                        pred = j + 1;
                    }
                }
                y = stoi(fir, strlen(fir), pred);
                matr[i][y - 1] = 1;
                inv[y - 1][i] = 1;
            }
        }
        printf("%d\n", n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(inv[i][j])
                    printf("%d ", j + 1);
            }
            printf("\n");
        }                
        return 0;

    } else{
        printf("no more\n");
        return 0;
    }

}