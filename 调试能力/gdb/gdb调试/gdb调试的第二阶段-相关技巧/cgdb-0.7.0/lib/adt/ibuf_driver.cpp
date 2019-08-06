/*
 * ibuf_driver: A test driver for the infinite string structure.
 *
 * Copyright (c) 2006, Mike Mueller & Bob Rossi
 * Subject to the terms of the GNU General Public Licence
 */

/* Standard Includes */
#if HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#if HAVE_STDIO_H
#include <stdio.h>
#endif /* HAVE_STDIO_H */

#if HAVE_STRING_H
#include <string.h>
#endif /* HAVE_STRING_H */

/* Local Includes */
#include "ibuf.h"

/* 
 * Macros
 */

#define DEBUG 1
#ifdef DEBUG
#define debug(args...) fprintf(stderr, args)
#else
#define debug(args...)
#endif

typedef struct ibuf *ibuf_ptr;

/*
 * Local function prototypes
 */

/* Tests */
static int test_add(ibuf_ptr s);
static int test_addchar(ibuf_ptr s);
static int test_delchar(ibuf_ptr s);
static int test_dup(ibuf_ptr s);

/* main:
 *
 * Description of test procedure here.
 */
int main(int argc, char *argv[])
{
    ibuf_ptr s = NULL;
    int result = 0;

    /* Create a tree */
    debug("Creating string... ");
    s = ibuf_init();
    if (s == NULL) {
        printf("FAILED\n");
        return 1;
    }
    debug("Succeeded.\n");

    /* Run tests */
    result |= test_add(s);
    result |= test_addchar(s);
    result |= test_delchar(s);
    result |= test_dup(s);

    debug("Destroying string...\n");
    ibuf_free(s);

    if (result) {
        printf("FAILED\n");
        return 2;
    }

    printf("PASSED\n");
    return 0;
}

/*
 * Local function implementations
 */

static int test_add(ibuf_ptr s)
{

    /* Add the strings "hello" and " world" to the ibuf */
    ibuf_add(s, "hello");
    ibuf_add(s, " world");

    /* Make sure that's what got added */
    if (strcmp(ibuf_get(s), "hello world") != 0) {
        debug("test_add: Mismatch, expected \"hello world\", got: %s\n",
                ibuf_get(s));
        return 1;
    }

    debug("test_add: Succeeded.\n");
    return 0;
}

static int test_addchar(ibuf_ptr s)
{

    /* Add an exclamation to the hello world string. */
    ibuf_addchar(s, '!');

    /* Make sure it was added correctly. */
    if (strcmp(ibuf_get(s), "hello world!") != 0) {
        debug("test_addchar: Mismatch, expected \"hello world!\", got: %s\n",
                ibuf_get(s));
        return 1;
    }

    debug("test_addchar: Succeeded.\n");
    return 0;
}

static int test_delchar(ibuf_ptr s)
{

    /* Delete the last '!' from the string. */
    ibuf_delchar(s);

    /* Make sure it was deleted correctly. */
    if (strcmp(ibuf_get(s), "hello world") != 0) {
        debug("test_delchar: Mismatch, expected \"hello world\", got: %s\n",
                ibuf_get(s));
        return 1;
    }

    /* Wipe the string via delchar, testing ibuf_length simultaneously */
    while (ibuf_length(s) > 0) {
        ibuf_delchar(s);
    }

    /* Make sure s is now an empty string. */
    if (strcmp(ibuf_get(s), "") != 0) {
        debug("test_delchar: Expected empty string, got: %s\n", ibuf_get(s));
        return 2;
    }

    debug("test_delchar: Succeeded.\n");
    return 0;
}

static int test_dup(ibuf_ptr s)
{

    ibuf_ptr t;

    /* Test duplicating a string. */
    ibuf_add(s, "test string 1");
    t = ibuf_dup(s);

    if (t == NULL) {
        debug("test_dup: ibuf_dup (attempt #1) returned NULL\n");
        return 1;
    }

    if (strcmp(ibuf_get(s), ibuf_get(t)) != 0) {
        debug("test_dup: Strings mismatched: \"%s\" != \"%s\"\n",
                ibuf_get(s), ibuf_get(t));
        return 1;
    }
    ibuf_free(t);

    /* Corner case: duplicate an empty string */
    ibuf_clear(s);
    t = ibuf_dup(s);

    if (t == NULL) {
        debug("test_dup: ibuf_dup (attempt #2) returned NULL\n");
        return 1;
    }

    if (strcmp(ibuf_get(t), "") != 0) {
        debug("test_dup: Expected empty string, got: %s\n", ibuf_get(t));
        return 1;
    }
    ibuf_free(t);

    debug("test_dup: Succeeded.\n");
    return 0;
}

