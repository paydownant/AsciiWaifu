#include "aui.h"

int main(int argc, char **argv) {
  AUI *app = new AUI();
  app->run("../images/satania1.png", stdout, 128);
}