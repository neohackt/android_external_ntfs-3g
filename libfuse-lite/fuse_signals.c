/*
    FUSE: Filesystem in Userspace
    Copyright (C) 2001-2007  Miklos Szeredi <miklos@szeredi.hu>

    This program can be distributed under the terms of the GNU LGPLv2.
    See the file COPYING.LIB
*/

#include "config.h"
#include "fuse_lowlevel.h"

#include <stdio.h>
#include <string.h>
#include <signal.h>

static struct fuse_session *fuse_instance;

static void exit_handler(int sig)
{
    (void) sig;
    if (fuse_instance)
        fuse_session_exit(fuse_instance);
}

<<<<<<< HEAD
static int set_one_signal_handler(int sig, void (*handler)(int), int remove)
=======
static int set_one_signal_handler(int sig, void (*handler)(int))
>>>>>>> 2111ad7... Initial import of ntfs-3g_ntfsprogs-2013.1.13
{
    struct sigaction sa;
    struct sigaction old_sa;

    memset(&sa, 0, sizeof(struct sigaction));
<<<<<<< HEAD
    sa.sa_handler = remove ? SIG_DFL : handler;
=======
    sa.sa_handler = handler;
>>>>>>> 2111ad7... Initial import of ntfs-3g_ntfsprogs-2013.1.13
    sigemptyset(&(sa.sa_mask));
    sa.sa_flags = 0;

    if (sigaction(sig, NULL, &old_sa) == -1) {
        perror("fuse: cannot get old signal handler");
        return -1;
    }

<<<<<<< HEAD
    if (old_sa.sa_handler == (remove ? handler : SIG_DFL) &&
=======
    if (old_sa.sa_handler == SIG_DFL &&
>>>>>>> 2111ad7... Initial import of ntfs-3g_ntfsprogs-2013.1.13
        sigaction(sig, &sa, NULL) == -1) {
        perror("fuse: cannot set signal handler");
        return -1;
    }
    return 0;
}

int fuse_set_signal_handlers(struct fuse_session *se)
{
<<<<<<< HEAD
    if (set_one_signal_handler(SIGHUP, exit_handler, 0) == -1 ||
        set_one_signal_handler(SIGINT, exit_handler, 0) == -1 ||
        set_one_signal_handler(SIGTERM, exit_handler, 0) == -1 ||
        set_one_signal_handler(SIGPIPE, SIG_IGN, 0) == -1)
=======
    if (set_one_signal_handler(SIGHUP, exit_handler) == -1 ||
        set_one_signal_handler(SIGINT, exit_handler) == -1 ||
        set_one_signal_handler(SIGTERM, exit_handler) == -1 ||
        set_one_signal_handler(SIGPIPE, SIG_IGN) == -1)
>>>>>>> 2111ad7... Initial import of ntfs-3g_ntfsprogs-2013.1.13
        return -1;

    fuse_instance = se;
    return 0;
}

void fuse_remove_signal_handlers(struct fuse_session *se)
{
    if (fuse_instance != se)
        fprintf(stderr,
                "fuse: fuse_remove_signal_handlers: unknown session\n");
    else
        fuse_instance = NULL;

<<<<<<< HEAD
    set_one_signal_handler(SIGHUP, exit_handler, 1);
    set_one_signal_handler(SIGINT, exit_handler, 1);
    set_one_signal_handler(SIGTERM, exit_handler, 1);
    set_one_signal_handler(SIGPIPE, SIG_IGN, 1);
=======
    set_one_signal_handler(SIGHUP, SIG_DFL);
    set_one_signal_handler(SIGINT, SIG_DFL);
    set_one_signal_handler(SIGTERM, SIG_DFL);
    set_one_signal_handler(SIGPIPE, SIG_DFL);
>>>>>>> 2111ad7... Initial import of ntfs-3g_ntfsprogs-2013.1.13
}

