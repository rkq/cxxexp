#include <libgen.h>
#include "glog/logging.h"

int main(int agrc, char* argv[]) {
  // logging to stderr
  FLAGS_logtostderr = true;
  google::InitGoogleLogging(basename(argv[0]));
  LOG(INFO) << "This is a test!";
  return 0;
}
