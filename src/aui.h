#ifndef AUI_H
#define AUI_H

#include <stdio.h>
#include <stdlib.h>

#include <string>

#include "imagesource.h"

typedef struct vertex {
  float pos[2] = { 0.0, 0.0 };
  float level = 0.0;
} vertex_t;

typedef unsigned int auint;

class AUI {

private:

  auint width, height;
  vertex_t *vertices = nullptr;

  const char points[8] = {' ','.',':','!','i','l','w','W'};

public:
  AUI();
  ~AUI();
  void run(std::string file_path, FILE *output_ptr, auint target_px);

private:
  void drawAUI(FILE *output_ptr);
  bool createVertexBuffer(std::string file_path, u_int target_width_px, float aspect_ratio);

};

static void error_callback(int error, const char *desc);

#endif