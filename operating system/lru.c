#include <stdio.h>
#include <stdbool.h>

#define MAX_PAGES 100
#define MAX_FRAMES 100

void print_frames(int frames[], int frame_count) {
    printf("Frames: ");
    for (int i = 0; i < frame_count; i++) {
        if (frames[i] == -1)
            printf("- ");
        else
            printf("%d ", frames[i]);
    }
    printf("\n");
}

// Find index of page in frames, or -1 if not found
int find_page(int frames[], int frame_count, int page) {
    for (int i = 0; i < frame_count; i++) {
        if (frames[i] == page) return i;
    }
    return -1;
}

// Find the index of the least recently used page
int find_lru_index(int time[], int frame_count) {
    int min_time = time[0], min_index = 0;
    for (int i = 1; i < frame_count; i++) {
        if (time[i] < min_time) {
            min_time = time[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int n, frames_count;
    int pages[MAX_PAGES];
    int frames[MAX_FRAMES];
    int time[MAX_FRAMES];  // To track last use time of each frame
    int page_faults = 0;

    printf("Enter number of pages in reference string: ");
    scanf("%d", &n);

    printf("Enter reference string (pages):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames_count);

    // Initialize frames and time arrays
    for (int i = 0; i < frames_count; i++) {
        frames[i] = -1; // empty
        time[i] = 0;
    }

    int current_time = 0;

    printf("\nSimulating LRU Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        current_time++;

        int page_index = find_page(frames, frames_count, page);
        if (page_index != -1) {
            // Page hit - update last used time
            time[page_index] = current_time;
            printf("Page %d accessed - No page fault.\n", page);
        } else {
            // Page fault
            page_faults++;

            // Check if there is an empty frame
            int empty_index = -1;
            for (int j = 0; j < frames_count; j++) {
                if (frames[j] == -1) {
                    empty_index = j;
                    break;
                }
            }

            if (empty_index != -1) {
                // Place page in empty frame
                frames[empty_index] = page;
                time[empty_index] = current_time;
                printf("Page %d loaded into free frame %d - Page fault #%d\n", page, empty_index, page_faults);
            } else {
                // Replace least recently used page
                int lru_index = find_lru_index(time, frames_count);
                printf("Page %d replaced page %d in frame %d - Page fault #%d\n", page, frames[lru_index], lru_index, page_faults);
                frames[lru_index] = page;
                time[lru_index] = current_time;
            }
        }

        print_frames(frames, frames_count);
    }

    printf("\nTotal page faults: %d\n", page_faults);

    return 0;
}
