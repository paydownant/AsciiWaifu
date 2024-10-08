#include "aui.h"

#include <math.h>

AUI :: AUI() {
}

AUI :: ~AUI() {
  free(vertices);
}

void AUI :: run(std::string file_path, FILE *output_ptr, auint target_px) {
  if (!createVertexBuffer(file_path, target_px, 0.4)) {
    error_callback(1, "Failed to create vertex buffer");
    exit(1);
  }

  if (output_ptr == nullptr) {
    error_callback(1, "Failed create output file");
    exit(1);
  }

  drawAUI(output_ptr);

}

void AUI :: drawAUI(FILE *output_ptr) {
  for (auint i = 0; i < height; ++i) {
    for (auint j = 0; j < width; ++j) {
      u_int points_index = (u_int)(pow(vertices[i * width + j].level, 1.2) * 8);
      fprintf(output_ptr, "%c", points[points_index]);
    }
    fprintf(output_ptr, "\n");
  }
}

bool AUI :: createVertexBuffer(std::string file_path, u_int target_width_px, float aspect_ratio) {
  // Load Image
  Image img(file_path);
  printf("Loaded %d x %d Image\n", img.w, img.h);

  float ratio_width = (float)target_width_px / img.w;
  float ratio_height = ratio_width * aspect_ratio;

  u_int target_width = (u_int)(ratio_width * img.w);
  u_int target_height = (u_int)(ratio_height * img.h);

  vertices = (vertex_t*)malloc(sizeof(vertex_t) * target_width * target_height);
  if (vertices == nullptr) {
    error_callback(1, "Failed to allocate memory");
    return false;
  }

  for (u_int i = 0; i < target_height; ++i) {
    for (u_int j = 0; j < target_width; ++j) {
      u_int index = i * target_width + j;
      vertices[index].pos[0] = ((float)i / target_width - 0.5) * 2;
      vertices[index].pos[1] = ((float)j / target_height - 0.5) * 2;

      u_int dataIndex = (u_int)((float)i / ratio_height) * img.w + (u_int)((float)j / ratio_width);
      float bw_level = (float)img.data[dataIndex] / 256;
      float threshold = 0.01;
      if (bw_level > threshold && bw_level + threshold < 1.0) {
        vertices[index].level = bw_level; // later apply gamma curve here
      } else {
        vertices[index].level = 0;
      }
    }
  }

  width = target_width;
  height = target_height;

  printf("Created %d x %d Buffer\n", target_width, target_height);

  return true;
}


static void error_callback(int error, const char* description) {
  fprintf(stderr, "Error: %s\n", description);
}