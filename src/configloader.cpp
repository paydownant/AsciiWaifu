#include "configloader.h"

bool load_aw_config(const char *config_file_path) {
  if (!config_file_path) return false;

  FILE *ifp = fopen(config_file_path, "r");
  if (!ifp) return false;


  return true;
}