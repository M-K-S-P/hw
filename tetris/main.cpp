#include<iostream>
#include<cstring>
#include<cstdlib> 
#include<time.h>
#ifdef _WIN32
#include<windows.h>
#else
#include<unistd.h>
#endif
//types are T L J O I S Z
//прога писалась под линуксом, для винды не проверялась (по факту вся разница во внешних библиотеках для sleep, т.е. unistd.h и windows.h)
//если не будет собираться под виндой, то уберите часть с ifdef и надо добавить #include<windows.h>

void clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H";
#elif defined (__APPLE__)
    system("clear");
#endif
}

class field{

    public:
        int** init(int x, int y){
            int** f1 = (int**)malloc(y * sizeof(*f1));
            for(int i = 0; i < y; i++){
                f1[i] = (int*)malloc(x * sizeof(int));
                for(int j = 0; j < x; j++){
                    f1[i][j] = 48;
                }
            }
            f = f1;
            return f1;
        }
        int check(int c, int x, int y){
            if(c == f[y][x]){
                return 1;
            } else{
                return 0;
            }
        }
        void fill(int x, int y, int c){
            f[y][x] = c;
        }
        void remove_row(int c){
            for(int i = 0; i < 8; i++){
                f[c][i] = 48;
            } 
            for(int i = c; i > 0; i--){ 
                for(int j = 0; j < 8; j++){
                    f[i][j] = f[i - 1][j];
                }
            }           
        }
        int draw(int c){
            clear();
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 8; j++){
                    printf("%c ", f[i][j]);
                }
                printf("\n");
            }
            int a;
            if(c){
                printf("Want to start the game?\n1)Yes\n2)No\n");
            }
            else{
                printf("What do you want to do?\n1)continue\n2)rotate figure clockwise\n3)rotate figure counterclockwise\n4)move right\n5)move left\n6)surrender\n");
            }
            scanf("%d", &a);
            return a;
        }
    private:
        int** f;
        int dx;
        int dy;

};
class figure{

    public:
        int poss[4][2]; //x, y coords for all points         
        void init(int t){
            type = t;
            int st[2] = {3, 0}; //x, y of starting point
            poss[0][0] = st[0];
            poss[0][1] = st[1];
            poss[1][0] = st[0] - 1;
            poss[1][1] = st[1];
            switch(t){
                case 'I':
                    poss[2][1] = st[1];
                    poss[2][0] = st[0] + 1;
                    poss[3][1] = st[1];
                    poss[3][0] = st[0] + 2;
                    dim = 4;
                    break;
                case 'O':
                    poss[2][1] = st[1] + 1;
                    poss[2][0] = st[0] - 1;
                    poss[3][1] = st[1] + 1;
                    poss[3][0] = st[0];
                    dim = 2;
                    break;
                case 'T':  
                    poss[2][1] = st[1];
                    poss[2][0] = st[0] + 1;
                    poss[3][1] = st[1] + 1;
                    poss[3][0] = st[0];
                    dim = 3;
                    break;
                case 'L':
                    poss[2][1] = st[1];
                    poss[2][0] = st[0] + 1;
                    poss[3][1] = st[1] + 1;
                    poss[3][0] = st[0] - 1;
                    dim = 3;
                    break;
                case 'J':
                    poss[2][1] = st[1];
                    poss[2][0] = st[0] + 1;
                    poss[3][1] = st[1] + 1;
                    poss[3][0] = st[0] + 1;
                    dim = 3;
                    break;
                case 'S':
                    poss[2][1] = st[1] + 1;
                    poss[2][0] = st[0] - 1;
                    poss[3][1] = st[1] + 1;
                    poss[3][0] = st[0] - 2;
                    dim = 3;
                    break;
                case 'Z':
                    poss[2][1] = st[1] + 1;
                    poss[2][0] = st[0];
                    poss[3][1] = st[1] + 1;
                    poss[3][0] = st[0] + 1;
                    dim = 3;
                    break;     
            }

        }
        int rotate(int d, field fi){ //d positive - clockwise
            int pn[4][2];
            int q;
            for(int i = 0; i < 4; i++){
                pn[i][0] = poss[0][0] - d * (poss[i][1] - poss[0][1]);
                pn[i][1] = poss[0][1] + d * (poss[i][0] - poss[0][0]);
            }
            for(int i = 0; i < 4; i++){
                q = 1;
                for(int j = 0; j < 4; j++){
                    if(pn[i][0] == poss[j][0] && pn[i][1] == poss[j][1]){    
                        q = 0;
                        break;
                    }
                }
                if(q){
                    if(fi.check(35, pn[i][0], pn[i][1]) || pn[i][1] < 0 || pn[i][1] > 9 || pn[i][0] > 7 || pn[i][0] < 0){
                        return -2;
                    }                    
                }
            }
            for(int i = 0; i < 4; i++){
                fi.fill(poss[i][0], poss[i][1], 48);
            }  
            for(int i = 0; i < 4; i++){
                poss[i][0] = pn[i][0];
                poss[i][1] = pn[i][1];
            }
            for(int i = 0; i < 4; i++){
                fi.fill(poss[i][0], poss[i][1], 35);
            }
            return 0;
        }
        int move(int h, int d, field fi){//h stands for vertical movement, d for horizontal (positive number - right direction)
            int c = 1;
            int pn[4][2];
            if(h){
                for(int i = 0; i < 4; i++){
                    if(poss[i][1] == 9){
                        return -1;
                    }
                    pn[i][0] = poss[i][0];
                    pn[i][1] = poss[i][1] + h;
                }
                int q;
                for(int i = 0; i < 4; i++){
                    q = 1;
                    for(int j = 0; j < 4; j++){
                        if(pn[i][0] == poss[j][0] && pn[i][1] == poss[j][1]){    
                            q = 0;
                            break;
                        }
                    }
                    if(q){
                        if(fi.check(35, pn[i][0], pn[i][1])){
                            if(poss[i][1] == 0){ //game over
                                return -3;
                            } else{
                                return -1;
                            }
                        }                    
                    }
                }
                for(int i = 0; i < 4; i++){
                    fi.fill(poss[i][0], poss[i][1], 48);
                }  
                for(int i = 0; i < 4; i++){
                    poss[i][0] = pn[i][0];
                    poss[i][1] = pn[i][1];
                }
                for(int i = 0; i < 4; i++){
                    fi.fill(poss[i][0], poss[i][1], 35);
                }
            } else{
                for(int i = 0; i < 4; i++){
                    if(poss[i][1] == 9){
                        return -1;
                    }
                    pn[i][0] = poss[i][0] + d;
                    pn[i][1] = poss[i][1];
                }
                int q;
                for(int i = 0; i < 4; i++){
                    q = 1;
                    for(int j = 0; j < 4; j++){
                        if(pn[i][0] == poss[j][0] && pn[i][1] == poss[j][1]){    
                            q = 0;
                            break;
                        }
                    }
                    if(q){
                        if(fi.check(35, pn[i][0], pn[i][1])){
                            return -2;
                        }                    
                    }
                }
                for(int i = 0; i < 4; i++){
                    fi.fill(poss[i][0], poss[i][1], 48);
                }  
                for(int i = 0; i < 4; i++){
                    poss[i][0] = pn[i][0];
                    poss[i][1] = pn[i][1];
                }
                for(int i = 0; i < 4; i++){
                    fi.fill(poss[i][0], poss[i][1], 35);
                }
            }
            return 0; 
        }

    private:
        int type;
        int dim;

};


int main(){
    srand(time(NULL));
    int cases[7] = {'I', 'O', 'T', 'S', 'Z', 'L', 'J'};
    int r, n, k, c1;
    int dx = 8, dy = 10;
    int c = 1;
    field fi;
    int f1[10][8];
    int** fp = fi.init(8, 10);
    memcpy(&f1, fp, sizeof(int) * 8 * 10); 
    // int field[10][8];
    // memset(&field[0][0], 48, sizeof(field));
    r = fi.draw(1);
    if(r == 2){
        printf("goodbye\n");
        return 0;
    } else{
        for(;;){
            for(int i = 0; i < 10; i++){
                c1 = 1;
                for(int j = 0; j < 8; j++){
                    if(fi.check('0', j, i)){
                        c1 = 0;
                        break;
                    }
                }
                if(c1 == 1){
                    printf("here\n");
                    sleep(1);
                    fi.remove_row(i);
                }
            }
            n = rand() % 7;
            figure f;
            f.init(cases[0]);
            for(int i = 0; i < 4; i++){
                //f1[f.poss[i][1]][f.poss[i][0]] = 35;
                fi.fill(f.poss[i][0], f.poss[i][1], 35);
            }
            c = 1;
            while(c){
                k = 1;
                r = fi.draw(0);
                if(r == 6){
                    printf("goodbye\n");
                    return 0;
                } else if(r == 5){
                    f.move(0, -1, fi);
                } else if(r == 4){
                    f.move(0, 1, fi);
                } else if(r == 3){
                    f.rotate(1, fi);
                } else if(r == 2){
                    f.rotate(-1, fi);
                } else if(r == 1){
                    k = f.move(1, 0, fi);
                } else{
                    printf("wrong move\n");
                    sleep(2);
                }
                if(k == -1){
                    c = 0;
                } else if(k == -2){
                    printf("can not do that\n");
                    sleep(2);
                } else if(k == -3){
                    printf("game over\n");
                    sleep(1);
                    return 0;
                }
            }
        }
    }
}
