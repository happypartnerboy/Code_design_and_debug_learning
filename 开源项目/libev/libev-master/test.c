#include <stdio.h>
#include <ev.h>

ev_io stdin_watcher;
ev_timer timeout_watcher;

static void  stdin_cb(EV_P_ ev_io *w, int revents)
{
    puts("stdin ready");
    ev_io_stop(EV_A_ w);
    ev_break(EV_A_ EVBREAK_ALL);
}

static void timeout_cb(EV_P_ ev_timer *w, int revnts)
{
    puts("time out");
    ev_break(EV_A_ EVBREAK_ONE);
}

 
int  main(void)
{
	struct ev_loop *loop = EV_DEFAULT;

	ev_io_init(&stdin_watcher, stdin_cb, 0, EV_READ);
	printf("hello word1\n");
	ev_io_start(loop, &stdin_watcher);
	printf("hello word2\n");
	ev_timer_init(&timeout_watcher, timeout_cb, 10, 0);
	ev_timer_start(loop, &timeout_watcher);
	printf("hello word3\n");
	ev_run(loop, 0);
	printf("hello word4\n");
    return 0;
}
