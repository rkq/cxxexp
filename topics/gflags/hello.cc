#include <cstdio>
#include "gflags/gflags.h"

DEFINE_bool(big_menu, true, "Include 'advanced' options in the menu listing");
DEFINE_string(languages, "english,french,german",
              "comma-separated list of languages to offer in the 'lang' menu");

int main(int argc, char* argv[]) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  if (FLAGS_big_menu) {
    std::printf("big_menu option is present.\n");
  }
  std::printf("languages: %s\n", FLAGS_languages.c_str());
  return 0;
}
