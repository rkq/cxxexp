# Build libevent with epoll backend

include_directories(
  include
  compat
  .
)

add_library(
    event STATIC
    epoll.c
    signal.c
    poll.c
    select.c
    event.c
    evthread.c
    buffer.c
    bufferevent.c
    bufferevent_sock.c
    bufferevent_filter.c
    bufferevent_pair.c
    listener.c
    bufferevent_ratelim.c
    evmap.c
    log.c
    evutil.c
    evutil_rand.c
    strlcpy.c
    event_tagging.c
    http.c
    evdns.c
    evrpc.c
)

target_link_libraries(event rt)
