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
               i + 1,
               patterns[i].pin,
               patterns[i].duration);
    }

    /* TODO 5 */
    free(patterns);

    printf("\nプログラム終了\n");
    return 0;
}
