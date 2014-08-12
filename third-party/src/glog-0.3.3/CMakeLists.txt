include_directories (include src)
add_library (glog
             src/demangle.cc
             src/logging.cc
             src/raw_logging.cc
             src/signalhandler.cc
             src/symbolize.cc
             src/utilities.cc
             src/vlog_is_on.cc)
target_link_libraries (glog gflags pthread unwind)
