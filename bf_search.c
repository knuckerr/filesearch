#include "bf_search.h"
#include "kmp.h"
#include "queue.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SearchResult createSearchResult() {
  SearchResult results;
  results.paths = NULL;
  results.num_paths = 0;
  return results;
}

void addPathToResult(SearchResult *results, const char *path) {
  results->num_paths++;
  results->paths = (char **)realloc(results->paths, (size_t)results->num_paths *
                                                        sizeof(char *));
  if (results->paths == NULL) {
    fprintf(stderr, "Error: Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }
  results->paths[results->num_paths - 1] = strdup(path);
}

void freeSearchResult(SearchResult *results) {
  for (int i = 0; i < results->num_paths; ++i) {
    if (results->paths[i] != NULL) {
      free(results->paths[i]);
    }
  }
  if (results->paths != NULL) {
    free(results->paths);
  }
  results->paths = NULL;
  results->num_paths = 0;
}

SearchResult BFSearch(const char *start_path, const char *target_file) {
  DIR *dir;
  struct dirent *entry;
  SearchResult result = createSearchResult();

  dir = opendir(start_path);
  if (dir == NULL) {
    printf("Starting directory %s don't exist.\n", start_path);
    return result;
  }
  closedir(dir);

  Queue queue;
  initializeQueue(&queue);

  enqueue(&queue, start_path);

  while (queue.front != NULL) {
    char *current_path = dequeue(&queue);
    dir = opendir(current_path);

    if (dir != NULL) {
      while ((entry = readdir(dir)) != NULL) {
        char *sub_path = (char *)malloc(PATH_MAX);
        if (sub_path == NULL) {
          fprintf(stderr, "Error: Memory allocation failed.\n");
          exit(EXIT_FAILURE);
        }
        snprintf(sub_path, PATH_MAX, "%s/%s", current_path, entry->d_name);
        if (entry->d_type == DT_DIR) {
          if (strcmp(entry->d_name, ".") != 0 &&
              strcmp(entry->d_name, "..") != 0) {
            enqueue(&queue, sub_path);
          }
        } else {
          if (kmpSearch(entry->d_name, target_file) > 0) {
            addPathToResult(&result, sub_path);
          }
        }
        free(sub_path);
      }

      closedir(dir);
    }
    free(current_path);
  }
  freeQueue(&queue);
  return result;
}
