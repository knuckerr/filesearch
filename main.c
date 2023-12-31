#include "bf_search.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <start_path> <target_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  float startTime, endTime, timeElapsed;

  const char *start_path = argv[1];
  const char *target_file = argv[2];

  startTime = (float)clock() / CLOCKS_PER_SEC;

  SearchResult result = BFSearch(start_path, target_file);

  endTime = (float)clock() / CLOCKS_PER_SEC;

  if (result.num_paths > 0) {
    printf("Found %d file(s):\n", result.num_paths);
    for (int i = 0; i < result.num_paths; ++i) {
      printf("%s\n", result.paths[i]);
    }
    // Free the memory allocated for the result
    freeSearchResult(&result);
  } else {
    printf("File %s not found.\n", target_file);
  }
  timeElapsed = endTime - startTime;

  printf("Time Elapsed %f\n", timeElapsed);

  return 0;
}
