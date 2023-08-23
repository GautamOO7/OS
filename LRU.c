#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10

int main() {
    int page_refs[MAX_FRAMES];
    int page_frames[MAX_FRAMES];
    int page_faults = 0;
    int num_refs, num_frames;
    int i, j, k, min_time, min_page, found;

    printf("Enter the number of page references: ");
    scanf("%d", &num_refs);

    printf("Enter the page reference string: ");
    for (i = 0; i < num_refs; i++) {
        scanf("%d", &page_refs[i]);
    }

    printf("Enter the number of page frames: ");
    scanf("%d", &num_frames);

    for (i = 0; i < num_frames; i++) {
        page_frames[i] = -1;
    }

    for (i = 0; i < num_refs; i++) {
        found = 0;
        for (j = 0; j < num_frames; j++) {
            if (page_frames[j] == page_refs[i]) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            page_faults++;
            if (i < num_frames) {
                page_frames[i] = page_refs[i];
            } else {
                min_time = i;
                min_page = page_frames[0];
                for (j = 0; j < num_frames; j++) {
                    for (k = i-1; k >= 0; k--) {
                        if (page_refs[k] == page_frames[j]) {
                            if (k < min_time) {
                                min_time = k;
                                min_page = page_frames[j];
                                break;
                            }
                        }
                    }
                }
                for (j = 0; j < num_frames; j++) {
                    if (page_frames[j] == min_page) {
                        page_frames[j] = page_refs[i];
                        break;
                    }
                }
            }
        }
        printf("Page frames after %d: ", page_refs[i]);
        for (j = 0; j < num_frames; j++) {
            if (page_frames[j] == -1) {
                printf("-");
            } else {
                printf("%d\t", page_frames[j]);
            }
        }
        printf("\n");
    }

    printf("Total page faults: %d\n", page_faults);

    return 0;
}
