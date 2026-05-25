/*
 * 基礎プログラミングII — 第7回 演習
 * テーマ: malloc を使ってスクーミーの LED シーケンスを動的管理する
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pin;
    int duration;
} LedPattern;

int isValidPin(int pin) {
    return pin == 10 || pin == 5 || pin == 15 || pin == 19;
}

int main(void) {
    int n;

    printf("LED パターンを何個登録しますか？: ");
    scanf("%d", &n);

    if (n <= 0) {
        fprintf(stderr, "1個以上のパターン数を入力してください\n");
        return 1;
    }

    LedPattern *patterns = malloc(n * sizeof(LedPattern));

    if (patterns == NULL) {
        fprintf(stderr, "メモリ確保に失敗しました\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        do {
            printf("パターン%d — ピン番号（10 / 5 / 15 / 19）: ", i + 1);
            scanf("%d", &patterns[i].pin);

            if (!isValidPin(patterns[i].pin)) {
                printf("使えるピン番号は 10, 5, 15, 19 のみです\n");
            }
        } while (!isValidPin(patterns[i].pin));

        do {
            printf("パターン%d — 点灯時間(ms): ", i + 1);
            scanf("%d", &patterns[i].duration);

            if (patterns[i].duration <= 0) {
                printf("点灯時間は1ms以上で入力してください\n");
            }
        } while (patterns[i].duration <= 0);
    }

    printf("\n--- 登録した LED シーケンス ---\n");

    int totalDuration = 0;

    for (int i = 0; i < n; i++) {
        printf("パターン%d: ピン%dを%dms点灯\n",
               i + 1,
               patterns[i].pin,
               patterns[i].duration);

        totalDuration += patterns[i].duration;
    }

    printf("\n合計点灯時間: %dms\n", totalDuration);

    free(patterns);

    printf("\nプログラム終了\n");
    return 0;
}
