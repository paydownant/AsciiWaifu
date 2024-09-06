#include "aui.h"

int main(int argc, char **argv) {
  FILE *ofp = fopen("../out/out2.txt", "w");
  if (ofp == nullptr) {
    exit(1);
  }
  
  AUI *app = new AUI();
  app->run("../images/yuno.png", ofp, 64);
}