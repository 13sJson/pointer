#include <stdio.h>
#include <string.h>
    
void pt_int(int *, int *);
void pt_print(int *, int *, char *, char *);

int main() {
    // 各変数及び型の初期化
    int i = 0;        // intは0代入することで初期化↓と同等の初期化が可能
    int *p_i = NULL;  // ゴミが入ってる可能性を含めポインタ変数は初期化
    
    char c[10];       // メモリ要素数[10]の領域を確保、アドレス参照は適当だから危険
    char *p_c = NULL; // ↑と同じく
    char test[] = "test";

    // int型ポインタ変数は主にint型変数のポインタを格納するため
    p_i = &i;

    pt_int(&i, p_i);
    *p_i = 2;
    printf("main: i=%d p_i=%d\n", i, p_i);
    // main: i=2 p_i=2

    // 文字列はmemsetで初期化することで、参照したアドレスをリセット
    memset(&c, '\0', sizeof(c));
    // 文字列代入（というか文字列をコピー）
    strcpy(c, "HelloWorld");

    /* ポインタで渡すときの状態
    * int i     = アドレスを渡すため &i
    * int *p_i  = ポインタ変数宣言しているためポインタ変数のポインタを渡すときは p_i
    * char c    = アドレスを渡す際はcharはcharの配列のため先頭のc[0]を渡すという意味で c
    * char *p_c = *p_iと同様
    */ 
    pt_print(&i, p_i, c, *p_c);
    printf("main: i = %d, p_i = %d, c = %s, p_c = %s\n", i, *p_i, c, p_c);
    printf("%s", test);
}

void pt_int(int *i, int *p_i) {
    *i = 1;
    printf("i_pt: i=%d, p_i=%d\n", *i, *p_i);
    // i_pt: i=1, p_i=1
}

void pt_print(int *i, int *p_i, char *c, char *p_c) {
    // 誤
    printf("pt_print: i = %d, p_i = %d, c = %s, p_c = %s\n", i, p_i, c, p_c);
    // i = 1111142364, p_i = 1111142364, c = HelloWorld, p_c = (null)
    
    // 正
    printf("pt_print: i = %d, p_i = %d, c = %s, p_c = %s\n", *i, *p_i, c, p_c);
    // i = 2, p_i = 2, c = HelloWorld, p_c = (null)

    /*** 代入する際 ***/
    *i = 3;
    *p_i = 4;
    c = "こんにちわ";
    p_c = "こんばんわ";

    // 検証
    printf("pt_print: i = %d, p_i = %d, c = %s, p_c = %s\n", *i, *p_i, c, p_c);
    // i = 4, p_i = 4, c = こんにちわ, p_c = こんばんわ

}