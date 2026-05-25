/*
 * 基礎プログラミングII — 第7回 演習
 * テーマ: malloc を使ってスクーミーの LED シーケンスを動的管理する
 *
 * 【課題】
 * スクーミーの LED（ピン: 10, 5, 15, 19）を「何番ピンを何ms光らせるか」
 * というシーケンスとして記録するプログラムを完成させよ。
 *
 * 【ルール】
 * - malloc でメモリを確保すること
 * - malloc 後は必ず NULL チェックをすること
 * - 最後に free でメモリを解放すること
 */

 #include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pin;
    int duration;
} LedPattern;

int main(void) {
    int n;

    printf("LED パターンを何個登録しますか？: ");
    scanf("%d", &n);

    /* TODO 1 */
    LedPattern *patterns = malloc(n * sizeof(LedPattern));

    /* TODO 2 */
    if (patterns == NULL) {
        fprintf(stderr, "メモリ確保に失敗しました\n");
        return 1;
    }

    /* TODO 3 */
    for (int i = 0; i < n; i++) {
        printf("パターン%d — ピン番号: ", i + 1);
        scanf("%d", &patterns[i].pin);

        printf("パターン%d — 点灯時間(ms): ", i + 1);
        scanf("%d", &patterns[i].duration);
    }

    /* TODO 4 */
    printf("\n--- 登録した LED シーケンス ---\n");
    for (int i = 0; i < n; i++) {
        printf("パターン%d: ピン%dを%dms点灯\n",
               i + 1,ああああああ
               patterns[i].pin,
               patterns[i].duration);
    }

    /* TODO 5 */
    free(patterns);

    printf("\nプログラム終了\n");
    return 0;
}
