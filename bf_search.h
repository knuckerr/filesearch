#ifndef BF_SEARCH_H

#define BF_SEARCH_H

typedef struct {
	char** paths;
	int num_paths;
} SearchResult;

SearchResult createSearchResult();

void addPathToResult(SearchResult* result, const char* path);

void freeSearchResult(SearchResult* result);

SearchResult BFSearch(const char* start_path, const char* target_file);

#endif
