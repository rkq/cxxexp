#include <cstdio>
#include <cstring>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <pthread.h>
#include <unistd.h>
#include "event2/event.h"
#include "boost/scoped_ptr.hpp"

void notify(evutil_socket_t listen_fd, short flags, void* arg) {
  std::printf("new connection coming!\n");
  struct sockaddr_in addr;
  std::memset(&addr, 0, sizeof(addr));
  socklen_t len = sizeof(addr);
  int fd = accept(listen_fd, reinterpret_cast<struct sockaddr*>(&addr), &len);
  close(fd);
}

void timeout(evutil_socket_t fd, short flags, void* arg) {
  std::printf("just timeout!\n");
}

int main(int argc, char* argv[]) {
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in addr;
  std::memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8080);
  bind(fd, reinterpret_cast<const struct sockaddr*>(&addr), sizeof(addr));
  listen(fd, 10);
  struct event_base* base = event_base_new();
  struct event* ev = event_new(base, fd, EV_READ | EV_PERSIST, notify, NULL);
  event_add(ev, NULL);
  struct event* tm_ev = event_new(base, -1, EV_PERSIST, timeout, NULL);
  struct timeval tv;
  std::memset(&tv, 0, sizeof(tv));
  tv.tv_sec = 20;
  event_add(tm_ev, &tv);
  event_base_dispatch(base);
  return 0;
}
