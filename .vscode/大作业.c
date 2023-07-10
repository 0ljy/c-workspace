#include<stdio.h>
struct pair{int first, second;}p[52];
int a[52][52], flag[52], n;
void init(){for(int i = 1; i <= n; ++ i)a[i][0] = i, flag[i] = 0, p[i].first = i;}//初始化
#define heap(x) p[x].first//x所在的堆
#define pos(x) p[x].second//x所在堆中的位置
void move(int x, int y, int f){//Move block x onto heap y
    a[y][++ flag[y]] = x;
    if(f == 1)flag[heap(x)] --;//是否需要改变原标记
    //更改记录块x的存储位置
    heap(x) = y;
    pos(x) = flag[y];
}
#define regression(x) move(x, x, 1);//将x放回x堆
int main(){
    scanf("%d", &n);
    init();//初始化
    char op1[5], op2[2];
    int x, y;
    while(1){
        scanf("%s", op1);
        if(op1[0] == 'm'){
            scanf("%d %s %d", &x, op2, &y);
            if(heap(x) == heap(y))continue;//无效操作
            if(op2[0] == 'o'){//move x on y
                for(int i = flag[heap(x)]; i > pos(x); -- i)regression(a[heap(x)][flag[heap(x)]]); //遍历x以上的木块
                move(a[heap(x)][flag[heap(x)]], heap(y), 1);//把x放到包含y的木块堆上
            }else{//move x to y
                for(int i = flag[heap(x)]; i > pos(x); -- i)regression(a[heap(x)][flag[heap(x)]]);//遍历x以上的木块
                for(int i = flag[heap(y)]; i > pos(y); -- i)regression(a[heap(y)][flag[heap(y)]]);//遍历y以上的木块
                move(a[heap(x)][flag[heap(x)]], heap(y), 1);//把木块x放到木块y上
            }
        }else if(op1[0] == 's'){
            scanf("%d %s %d", &x, op2, &y);
            if(heap(x) == heap(y))continue;
            if(op2[0] == 't'){//shift x to y
                for(int i = flag[heap(y)]; i > pos(y); -- i)regression(a[heap(y)][flag[heap(y)]]);//遍历y以上的木块
                int re_flag = pos(x), re_heap = heap(x);//记录块x对应的位置
                for(int i = pos(x); i <= re_heap; ++ i)move(a[re_heap][i], heap(y), 0);
                flag[heap(x)] = re_flag - 1;//更改原数组标记
            }else{//shift x on y
                int re_flag = pos(x), re_heap = heap(x);//记录块x对应的位置
                for(int i = pos(x); i <= flag[re_heap]; ++ i)move(a[re_heap][i], heap(y), 0);
                flag[re_heap] = re_flag - 1;//更改原数组标记
            }
        }else break;
    }
    //输出
    for(int i = 1; i <= n; ++i){
        printf("%d:",i);
        for(int j = 0; j <= flag[i]; ++ j)printf(" %d", a[i][j]);
        printf("\n");
    }
    return 0;
}
