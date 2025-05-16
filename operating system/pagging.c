#include <stdio.h>
#include <stdbool.h>

#define MAX_PAGES 100
#define MAX_FRAMES 100

int main() {
    int num_pages, num_frames;
    int page_references[MAX_PAGES];
    int page_frame_map[MAX_PAGES];  // Stores frame number assigned to each page (-1 if none)
    bool frame_occupied[MAX_FRAMES]; // Keeps track of which frames are occupied

    printf("Enter number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter number of frames: ");
    scanf("%d", &num_frames);

    printf("Enter page references (%d pages):\n", num_pages);
    for (int i = 0; i < num_pages; i++) {
        scanf("%d", &page_references[i]);
    }

    // Initialize mapping to -1 (no frame assigned)
    for (int i = 0; i < num_pages; i++) {
        page_frame_map[i] = -1;
    }

    // Initialize all frames as free
    for (int i = 0; i < num_frames; i++) {
        frame_occupied[i] = false;
    }

    int next_free_frame = 0;

    for (int i = 0; i < num_pages; i++) {
        int page = page_references[i];

        if (page_frame_map[page] != -1) {
            // Page already mapped, just continue
            printf("Page %d is already mapped to Frame %d\n", page, page_frame_map[page]);
            continue;
        }

        if (next_free_frame < num_frames) {
            // Assign next free frame to this page
            page_frame_map[page] = next_free_frame;
            frame_occupied[next_free_frame] = true;
            printf("Mapping Page %d to Frame %d\n", page, next_free_frame);
            next_free_frame++;
        } else {
            // No free frame available
            printf("No free frame available for Page %d, cannot load this page\n", page);
        }
    }

    printf("\nFinal page to frame mapping:\n");
    printf("Page\tFrame\n");
    for (int i = 0; i < num_pages; i++) {
        if (page_frame_map[i] != -1) {
            printf("%d\t%d\n", i, page_frame_map[i]);
        } else {
            printf("%d\tNot loaded\n", i);
        }
    }

    return 0;
}
