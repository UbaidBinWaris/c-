#include <stdio.h>

#define MAX_PAGES 100
#define MAX_FRAMES 100

int main() {
    int num_pages, num_frames;
    int pages[MAX_PAGES];
    int frame_for_page[MAX_PAGES];  // Stores which frame a page is loaded into; -1 if not loaded
    int frames_used[MAX_FRAMES];    // 0 if free, 1 if occupied

    printf("Enter number of pages in reference string: ");
    scanf("%d", &num_pages);

    printf("Enter pages (logical addresses):\n");
    for (int i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
        frame_for_page[i] = -1;
    }

    printf("Enter number of frames: ");
    scanf("%d", &num_frames);

    for (int i = 0; i < num_frames; i++) {
        frames_used[i] = 0;
    }

    printf("\nMapping pages to frames:\n");
    for (int i = 0; i < num_pages; i++) {
        // Find free frame
        int frame_index = -1;
        for (int f = 0; f < num_frames; f++) {
            if (frames_used[f] == 0) {
                frame_index = f;
                break;
            }
        }

        if (frame_index != -1) {
            // Assign this page to the free frame
            frame_for_page[i] = frame_index;
            frames_used[frame_index] = 1;
            printf("Page %d loaded into frame %d\n", pages[i], frame_index);
        } else {
            printf("No free frame available for page %d. Page cannot be loaded.\n", pages[i]);
        }
    }

    printf("\nFinal page-to-frame mapping:\n");
    for (int i = 0; i < num_pages; i++) {
        if (frame_for_page[i] != -1)
            printf("Page %d -> Frame %d\n", pages[i], frame_for_page[i]);
        else
            printf("Page %d -> Not loaded\n", pages[i]);
    }

    return 0;
}
