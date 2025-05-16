#include <stdio.h>
#include <stdbool.h>

#define MAX_PAGES 100
#define MAX_FRAMES 100
#define INF 999999

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

// Find the index of the least frequently used page
// If multiple have the same frequency, choose the one with smallest index (FIFO tie breaker)
int find_lfu_index(int freq[], int frame_count) {
    int min_freq = INF;
    int min_index = -1;
    for (int i = 0; i < frame_count; i++) {
        if (freq[i] < min_freq) {
            min_freq = freq[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int n, frames_count;
    int pages[MAX_PAGES];
    int frames[MAX_FRAMES];
    int freq[MAX_FRAMES];  // Frequency of pages in frames
    int page_faults = 0;

    printf("Enter number of pages in reference string: ");
    scanf("%d", &n);

    printf("Enter reference string (pages):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames_count);

    // Initialize frames and frequencies
    for (int i = 0; i < frames_count; i++) {
        frames[i] = -1;
        freq[i] = 0;
    }

    printf("\nSimulating LFU Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        int page_index = find_page(frames, frames_count, page);

        if (page_index != -1) {
            // Page hit: increment frequency
            freq[page_index]++;
            printf("Page %d accessed - Frequency updated to %d.\n", page, freq[page_index]);
        } else {
            // Page fault
            page_faults++;

            // Check for empty frame
            int empty_index = -1;
            for (int j = 0; j < frames_count; j++) {
                if (frames[j] == -1) {
                    empty_index = j;
                    break;
                }
            }

            if (empty_index != -1) {
                // Load page in empty frame
                frames[empty_index] = page;
                freq[empty_index] = 1;
                printf("Page %d loaded into free frame %d - Page fault #%d\n", page, empty_index, page_faults);
            } else {
                // Evict least frequently used page
                int lfu_index = find_lfu_index(freq, frames_count);
                printf("Page %d replaced page %d in frame %d (freq=%d) - Page fault #%d\n", page, frames[lfu_index], lfu_index, freq[lfu_index], page_faults);
                frames[lfu_index] = page;
                freq[lfu_index] = 1;
            }
        }

        print_frames(frames, frames_count);
    }

    printf("\nTotal page faults: %d\n", page_faults);

    return 0;
}
